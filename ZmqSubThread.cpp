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

        /* 转成 std::string */
        std::string jsonStr(static_cast<char*>(zmq_msg_data(&frame)),
                            zmq_msg_size(&frame));
        zmq_msg_close(&frame);

        /* 解析 JSON（举例用 nlohmann::json） */
        auto j = nlohmann::json::parse(jsonStr, nullptr, false);
        if (j.is_discarded()) { qDebug() << "bad json"; continue; }

        double ts = j.value("timestamp", 0.0);
        auto &pe  = j["pose_error"];
        double x  = pe.value("x", 0.0);
        double y  = pe.value("y", 0.0);
        double z  = pe.value("z", 0.0);
        double ax = pe.value("axis_angle_x", 0.0);
        double ay = pe.value("axis_angle_y", 0.0);
        double az = pe.value("axis_angle_z", 0.0);

        qDebug() << "time" << ts << "got pose" << x << y << z << ax << ay << az;
        /* 这里再 emit 给 UI 即可 */
    }

    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    qDebug() << "ZMQ thread exit";
}

