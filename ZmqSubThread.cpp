//
// Created by bohan on 2023/12/18.
// 改造: 适配 control_process.py 的 send_pyobj(pickle) + IPC 发送方式
//

#include "ZmqSubThread.h"

#include "zmq.h"
#include <QDebug>
#include <iostream>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>


ZmqSubThread::ZmqSubThread(QObject *parent) : QThread(parent) {}
ZmqSubThread::~ZmqSubThread()
{
    m_stop = true;
    wait();
}

// ============================================================
//  pickle 协议常量 (protocol 4 / 5)
// ============================================================
static constexpr uint8_t P_MARK              = '(';
static constexpr uint8_t P_STOP              = '.';
static constexpr uint8_t P_EMPTY_DICT        = '}';
static constexpr uint8_t P_EMPTY_LIST        = ']';
static constexpr uint8_t P_APPENDS           = 'e';
static constexpr uint8_t P_SETITEMS          = 'u';
static constexpr uint8_t P_BINFLOAT          = 'G';
static constexpr uint8_t P_PROTO             = '\x80';
static constexpr uint8_t P_SHORT_BINUNICODE  = '\x8c';
static constexpr uint8_t P_MEMOIZE           = '\x94';
static constexpr uint8_t P_FRAME             = '\x95';

// ---------- 工具: 大端 double → 本机 ----------
static double beDouble(const uint8_t* src)
{
    uint64_t be = 0;
    for (int i = 0; i < 8; ++i) be = (be << 8) | src[i];
    double d;
    std::memcpy(&d, &be, sizeof(d));
    return d;
}

// ---------- pickle 解析器 (仅解析 control_process.py 产生的固定结构) ----------
struct PickleReader {
    const uint8_t* data;
    size_t size;
    size_t pos = 0;

    bool eof() const { return pos >= size; }

    uint8_t nextByte() {
        if (eof()) return P_STOP; // 安全兜底
        return data[pos++];
    }

    // 跳过 PROTO + FRAME 头
    void skipHeader() {
        pos = 0;
        // PROTO
        if (!eof() && data[pos] == P_PROTO) {
            ++pos;              // 跳过 0x80
            if (!eof()) ++pos;  // 跳过协议版本号 (0x04/0x05)
        }
        // FRAME (可选)
        if (!eof() && data[pos] == P_FRAME) {
            ++pos;
            pos += 8;  // 跳过 8 字节 little-endian frame 长度
        }
    }

    // 读一个 SHORT_BINUNICODE 字符串
    std::string readShortUnicode() {
        uint8_t len = nextByte();
        std::string s(reinterpret_cast<const char*>(data + pos), len);
        pos += len;
        return s;
    }

    // 读一个 BINFLOAT (8 字节大端 double), 跳过可能的前置 MEMOIZE
    double readFloat() {
        // 吃掉可能存在的 MEMOIZE
        if (!eof() && data[pos] == P_MEMOIZE) ++pos;
        if (nextByte() != P_BINFLOAT) return 0.0;
        double v = beDouble(data + pos);
        pos += 8;
        return v;
    }

    // 读一个 list<double> (6 个元素), 要求以 EMPTY_LIST + MEMOIZE + MARK 开头
    std::vector<double> readFloatList6() {
        if (!eof() && data[pos] == P_MEMOIZE) ++pos;
        uint8_t b = nextByte();
        if (b != P_EMPTY_LIST) return std::vector<double>(6, 0.0);
        // 跳过 list 的 MEMOIZE
        if (!eof() && data[pos] == P_MEMOIZE) ++pos;
        // 期望 MARK '('
        if (!eof() && data[pos] == P_MARK) ++pos;
        std::vector<double> v(6, 0.0);
        for (int i = 0; i < 6; ++i) {
            v[i] = readFloat();
        }
        // 期望 APPENDS 'e'
        if (!eof() && data[pos] == P_APPENDS) ++pos;
        return v;
    }

    // 填充 Pose6D
    static void fillPose(Pose6D& p, const std::vector<double>& v) {
        if (v.size() >= 6) {
            p.x  = v[0]; p.y  = v[1]; p.z  = v[2];
            p.ax = v[3]; p.ay = v[4]; p.az = v[5];
        }
    }
};

static bool parsePickle(const uint8_t* data, size_t size, RobotPoseFrame& f)
{
    PickleReader r{data, size};
    r.skipHeader();

    // 期望 EMPTY_DICT + MEMOIZE + MARK
    if (r.nextByte() != P_EMPTY_DICT) return false;
    if (!r.eof() && r.data[r.pos] == P_MEMOIZE) r.pos++;
    if (!r.eof() && r.data[r.pos] == P_MARK) r.pos++;

    // 循环解析 key-value 对，直到 SETITEMS/STOP
    while (!r.eof()) {
        if (r.data[r.pos] == P_SETITEMS) { r.pos++; break; }
        if (r.data[r.pos] == P_STOP)     { r.pos++; break; }

        // --- 读 key: SHORT_BINUNICODE + MEMOIZE ---
        if (r.nextByte() != P_SHORT_BINUNICODE) return false;
        std::string key = r.readShortUnicode();
        if (!r.eof() && r.data[r.pos] == P_MEMOIZE) r.pos++;

        // --- 读 value ---
        if (key == "timestamp") {
            f.timestamp = r.readFloat();
        } else {
            std::vector<double> list = r.readFloatList6();
            if (key == "pose_cmd")   PickleReader::fillPose(f.cmd, list);
            else if (key == "pose_now")   PickleReader::fillPose(f.now, list);
            else if (key == "joint_pos")  PickleReader::fillPose(f.joint_pos, list);
            else if (key == "actions")    PickleReader::fillPose(f.actions, list);
            else if (key == "pose_error") PickleReader::fillPose(f.pose_error, list);
        }
    }
    return true;
}

// ============================================================
//  主线程
// ============================================================
void ZmqSubThread::run()
{
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);

    // 🌟 改为 IPC 连接，与 control_process.py 的 chart_pub 对接
    std::cout << "[ZMQ] connecting to ipc:///tmp/jk5_chart.ipc ..." << std::endl;
    int rc = zmq_connect(subscriber, "ipc:///tmp/jk5_chart.ipc");
    if (rc != 0) {
        qDebug() << "[ZMQ] ⚠ IPC connect failed, trying TCP fallback...";
        rc = zmq_connect(subscriber, "tcp://127.0.0.1:5558");
    }
    qDebug() << "[ZMQ] connect rc =" << rc;

    // 增大接收缓冲区 (pickle 消息可能较大)
    int rcvBuf = 256 * 1024;
    zmq_setsockopt(subscriber, ZMQ_RCVBUF, &rcvBuf, sizeof(rcvBuf));

    /* 订阅所有消息 */
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);

    /* 循环接收 pickle 二进制帧 */
    while (!m_stop)
    {
        zmq_msg_t frame;
        zmq_msg_init(&frame);
        int rc = zmq_msg_recv(&frame, subscriber, 0);
        if (rc == -1) { zmq_msg_close(&frame); continue; }

        const auto* rawData = static_cast<const uint8_t*>(zmq_msg_data(&frame));
        size_t rawSize = zmq_msg_size(&frame);

        RobotPoseFrame f{};
        if (rawSize > 4 && parsePickle(rawData, rawSize, f)) {
            emit receiveRobotPoseSignal(f);
        } else {
            qDebug() << "[ZMQ] pickle parse failed, size=" << rawSize;
        }

        zmq_msg_close(&frame);
    }

    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    qDebug() << "[ZMQ] thread exit";
}

