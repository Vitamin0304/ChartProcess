//
// Created by bohan on 2023/12/18.
//

#include "ZmqSubThread.h"

#include "zmq.h"
#include <QDebug>

ZmqSubThread::ZmqSubThread()
{

}

ZmqSubThread::~ZmqSubThread()
{

}

void ZmqSubThread::run()
{
    // 1.初始化上下文
    void *context = zmq_ctx_new();

    // 2.创建套接字、连接发布者
    void *subscriber = zmq_socket(context, ZMQ_SUB);

    int rc = zmq_connect(subscriber, "tcp://localhost:5555");
    qDebug() << "zmq subscribe tcp://192.168.1.219:5555" << rc;

    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, NULL, 0);

    DisplayDataStruct displayDataStruct;
    ATPSensorData atpSensorData;
    WebotsData webotsData;

    for (;;)
    {
//        int size = zmq_recv(subscriber, &webotsData, sizeof(WebotsData), 0);
//        if(size == sizeof(WebotsData))
//        {
//            emit receiveWebotsDataSignal(webotsData);
//        }

        uint8_t msgId = 0;
        int size = zmq_recv(subscriber, &msgId, sizeof(uint8_t), 0);
        if(size == sizeof(uint8_t))
        {
            if(msgId == 1)
            {
                size = zmq_recv(subscriber, &displayDataStruct, sizeof(DisplayDataStruct), 0);
                if(size == sizeof(DisplayDataStruct))
                {
                    emit receiveStateDataSignal(displayDataStruct);
                }
            }
            else if(msgId == 2)
            {
                size = zmq_recv(subscriber, &atpSensorData, sizeof(ATPSensorData), 0);
                if(size == sizeof(ATPSensorData))
                {
                    emit receiveATPDataSignal(atpSensorData);
                }
            }
            else if(msgId == 3)
            {
                size = zmq_recv(subscriber, &webotsData, sizeof(WebotsData), 0);
                if(size == sizeof(WebotsData))
                {
                    emit receiveWebotsDataSignal(webotsData);
                }
            }
        }
    }
}
