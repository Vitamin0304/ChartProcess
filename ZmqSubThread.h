//
// Created by bohan on 2023/12/18.
//

#ifndef QT_MASTER_ZMQSUBTHREAD_H
#define QT_MASTER_ZMQSUBTHREAD_H

#include <qobject.h>
#include <qthread.h>

struct DisplayDataStruct
{
    float cpuUsage = 0;
    uint8_t servoState = 0;
    uint32_t driverState[2] = {0x240,0x240};
    uint16_t driverErrorCount[2] = {0};
    uint8_t atpState = 0;

    double dspTime = 0;
    double input[2] = {0};
    double position[2] = {0};
    double speed[2] = {0};
    double torque[2] = {0};
    double error[2] = {0};

    uint8_t imuState = 0;
    double omega[3] = {0};

    uint8_t atpErrorCode[6] = {0};
    uint8_t atpLastErrorCode[6] = {0};

    //ATP状态
    bool isWeakExamined = false;
    bool isDriverPowerOn = false;
    bool isLocked[2] = {true, true};
    bool isServoOpen = false;
    uint8_t pitchPosLimitMode = 2; //俯仰限位状态，0为工作限位，1为撤收限位，2为未设置

    bool pitchPosLimitIn : 1;
    bool driverPowerIn : 1;
    bool driverBreakIn : 1;

    bool driverBreakOut : 1;
    bool driverPowerOut : 1;
    bool yawLockOut : 1;
    bool pitchLockOut : 1;
};

struct ATPSensorData
{
    uint32_t count;
    float guidePos[2];
    float missDistance[2];
    float omega[3];
    uint8_t imuState;
};

struct WebotsData
{
    float dspTime = 0;
    float input[2] = {0};
    float position[2] = {0};
    float speed[2] = {0};
    float torque[2] = {0};
    float error[2] = {0};

    float omega[3] = {0};

    float guidePos[2] = {0};
    float missDistance[2] = {0};
};

struct Pose6D {
    double x, y, z;
    double ax, ay, az;
};
struct RobotPoseFrame {
    double timestamp;
    Pose6D error;
    Pose6D cmd;
    Pose6D now;
    Pose6D vel;
};

class ZmqSubThread : public QThread
{
    Q_OBJECT
public:
    explicit ZmqSubThread(QObject *parent = nullptr);
    ~ZmqSubThread();

protected:
    void run() override;

signals:
    void receiveStateDataSignal(DisplayDataStruct  displayData);
    void receiveATPDataSignal   (ATPSensorData     atpData);
    void receiveWebotsDataSignal(WebotsData        webotsData);
    void receiveRobotPoseSignal(RobotPoseFrame   robotPose);

private:
    volatile bool m_stop = false;   // 用于打断循环
};


#endif //QT_MASTER_ZMQSUBTHREAD_H
