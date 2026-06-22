//
// Created by bohan on 2023/12/18.
//

#include "ZmqSubThread.h"

#include "zmq.h"
#include <QDebug>
#include <nlohmann/json.hpp>
#include <iostream>


ZmqSubThread::ZmqSubThread(QObject *parent) : QThread(parent) {}
ZmqSubThread::~ZmqSubThread()
{
    // 请求退出并等待线程结束
    m_stop = true;
    wait();
}

void ZmqSubThread::run()
{
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    std::cout << "sub zmq!";
    int rc = zmq_connect(subscriber, "tcp://127.0.0.1:5558");
    std::cout << "connect zmq!";
    qDebug() << "zmq connect rc =" << rc;


    /* 订阅所有消息（空串） */
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);

    /* 工具 lambda：把 json 子对象 → Pose6D（容错版） */
    auto readPose = [](const nlohmann::json& obj) -> Pose6D {
        Pose6D p{};
        auto safeNum = [&](const char* key) -> double {
            if (!obj.contains(key)) return 0.0;
            const auto& v = obj[key];
            if (v.is_number()) return v.get<double>();
            if (v.is_array() && !v.empty() && v[0].is_number()) return v[0].get<double>();
            return 0.0;
        };
        p.x  = safeNum("x");
        p.y  = safeNum("y");
        p.z  = safeNum("z");
        p.ax = safeNum("axis_angle_x");
        p.ay = safeNum("axis_angle_y");
        p.az = safeNum("axis_angle_z");
        return p;
    };

    /* 循环收纯文本帧 */
    while (!m_stop)
    {
        zmq_msg_t frame;
        zmq_msg_init(&frame);
        int rc = zmq_msg_recv(&frame, subscriber, 0);
        if (rc == -1) { zmq_msg_close(&frame); continue; }

        std::string jsonStr(static_cast<char*>(zmq_msg_data(&frame)),
                            zmq_msg_size(&frame));
        zmq_msg_close(&frame);

        auto j = nlohmann::json::parse(jsonStr, nullptr, false);
        if (j.is_discarded()) { qDebug() << "bad json"; continue; }

        /* 解析顶层时间戳 */
        RobotPoseFrame f;
        try {
            f.timestamp = j.value("timestamp", 0.0);
            f.cmd   = readPose(j.value("pose_cmd", nlohmann::json::object()));
            f.now   = readPose(j.value("pose_now", nlohmann::json::object()));
            f.joint_pos   = readPose(j.value("joint_pos", nlohmann::json::object()));
            f.actions = readPose(j.value("actions", nlohmann::json::object()));
            f.pose_error = readPose(j.value("pose_error", nlohmann::json::object()));
        } catch (const nlohmann::json::exception& e) {
            qDebug() << "[ZMQ] JSON parse error:" << e.what();
            qDebug() << "[ZMQ] raw:" << QString::fromStdString(jsonStr).left(500);
            continue;
        }

        /* 直接发给 UI（Qt::QueuedConnection 自动跨线程） */
        emit receiveRobotPoseSignal(f);

        // qDebug() << "[ZMQ] t=" << f.timestamp
        //          << " err=" << f.error.x << f.error.y << f.error.z
        //          << f.error.ax <<  f.error.ay << f.error.az
        //          << " cmd=" << f.cmd.x   << f.cmd.y   << f.cmd.z
        //          << f.cmd.ax <<  f.cmd.ay << f.cmd.az
        //          << " now=" << f.now.x   << f.now.y   << f.now.z
        //          << f.now.ax <<  f.now.ay << f.now.az;
    }

    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    qDebug() << "ZMQ thread exit";
}

