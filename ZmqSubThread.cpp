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
    int rc = zmq_connect(subscriber, "tcp://192.168.1.43:5558");
    std::cout << "connect zmq!";
    qDebug() << "zmq connect rc =" << rc;


    /* 订阅所有消息（空串） */
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);

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
        f.timestamp = j.value("timestamp", 0.0);

        /* 工具 lambda：把 json 子对象 → Pose6D */
        auto readPose = [](const nlohmann::json& obj) -> Pose6D {
            Pose6D p{};
            p.x  = obj.value("x", 0.0);
            p.y  = obj.value("y", 0.0);
            p.z  = obj.value("z", 0.0);
            p.ax = obj.value("axis_angle_x", 0.0);
            p.ay = obj.value("axis_angle_y", 0.0);
            p.az = obj.value("axis_angle_z", 0.0);
            return p;
        };

        f.error = readPose(j["pose_error"]);
        f.cmd   = readPose(j["pose_cmd"]);
        f.now   = readPose(j["pose_now"]);
        f.vel   = readPose(j["vel_now"]);

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

