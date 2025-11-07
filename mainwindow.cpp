#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ZmqSubThread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer1 = new QTimer(this);
    timer1->setInterval(60);
    timer1->setObjectName("timer1");
    QObject::connect(timer1, &QTimer::timeout, this, &MainWindow::on_timer1_timeout, Qt::QueuedConnection);

    chart1 = new ChartDisplay(this, ui->chart1, nullptr,
                              ui->clearButton, ui->manualButton, ui->translationButton, ui->stretchButton);
    chart2 = new ChartDisplay(this, ui->chart2, nullptr,
                              ui->clearButton, ui->manualButton, ui->translationButton, ui->stretchButton);
    chart3 = new ChartDisplay(this, ui->chart3, nullptr,
                              ui->clearButton, ui->manualButton, ui->translationButton, ui->stretchButton);
    chart4 = new ChartDisplay(this, ui->chart4, nullptr,
                              ui->clearButton, ui->manualButton, ui->translationButton, ui->stretchButton);

    connect(ui->globalButton, &QPushButton::clicked, chart1, &ChartDisplay::viewGlobal);
    connect(ui->globalButton, &QPushButton::clicked, chart2, &ChartDisplay::viewGlobal);
    connect(ui->globalButton, &QPushButton::clicked, chart3, &ChartDisplay::viewGlobal);
    connect(ui->globalButton, &QPushButton::clicked, chart4, &ChartDisplay::viewGlobal);
    connect(ui->nowButton, &QPushButton::clicked, chart1, &ChartDisplay::followCurrent);
    connect(ui->nowButton, &QPushButton::clicked, chart2, &ChartDisplay::followCurrent);
    connect(ui->nowButton, &QPushButton::clicked, chart3, &ChartDisplay::followCurrent);
    connect(ui->nowButton, &QPushButton::clicked, chart4, &ChartDisplay::followCurrent);

    //曲线显示线程
    for (auto & t : chartThread)
    {
        t = new QThread();
    }

    chart1->setLabel("时间（s）", "方位轴");
    chart2->setLabel("时间（s）", "方位轴");
    chart3->setLabel("时间（s）", "俯仰轴");
    chart4->setLabel("时间（s）", "俯仰轴");

//    chart1->moveToThread(chartThread[0]);
//    chart2->moveToThread(chartThread[1]);
//    chart3->moveToThread(chartThread[2]);
//    chart4->moveToThread(chartThread[3]);

    qRegisterMetaType<QCPRange>("QCPRange");
    qRegisterMetaType<QCPRange>("QCPRange&");

    //根据变量更改
    QStringList motor1Names = {"输入", "速度", "位置", "力矩指令", "偏差", "角度引导"};  //chart0
    QStringList motor2Names = {"输入", "速度", "位置", "力矩指令", "偏差", "角度引导"}; //chart2
    QStringList error1Name = {"横向脱靶量", "陀螺仪Z角速度", "cpu"};  //chart1
    QStringList error2Name = {"纵向脱靶量", "陀螺仪X角速度", "陀螺仪Y角速度", "ATP状态"};  //chart3

    chartList << chart1 << chart2 << chart3 << chart4;

    colorList.append(Qt::red);
    colorList.append(Qt::blue);
    colorList.append(Qt::magenta);
    colorList.append(QColor(145, 204, 117));
    colorList.append(QColor(255, 151, 0));
    colorList.append(Qt::green);

    chartNamesList << motor1Names << error1Name << motor2Names  << error2Name;
    int chartNum = chartNamesList.count();
    for(int i = 0; i < chartNum; i++)
    {
        int graphNum = chartNamesList[i].count();
        for(int j = 0; j < graphNum; j++)
        {
            chartList[i]->addGraph(chartNamesList[i][j], colorList[j]);
        }
    }

    for (auto & t : chartThread)
    {
        t->start();
    }

    //曲线数据存储窗口
    chartDataSaveWindow = new ChartDataSave();

    //曲线数据保存
    for(auto* chartDisplay : chartList)
    {
        servoCharts << chartDisplay->getCustomPlot();
    }
    connect(ui->saveChartButton, &QPushButton::clicked, this, [this]()
    {
        saveChartData(servoCharts);
    }, Qt::QueuedConnection);
    qRegisterMetaType<QVector<QCustomPlot *> >("QVector<QCustomPlot *>");

    zmqSubThread = new ZmqSubThread();

    qRegisterMetaType<DisplayDataStruct>("DisplayDataStruct");
    qRegisterMetaType<ATPSensorData>("ATPSensorData");
    qRegisterMetaType<WebotsData>("WebotsData");
    connect(zmqSubThread, &ZmqSubThread::receiveStateDataSignal, this, &MainWindow::receiveStateData);
    connect(zmqSubThread, &ZmqSubThread::receiveATPDataSignal, this, &MainWindow::receiveATPData);
    connect(zmqSubThread, &ZmqSubThread::receiveWebotsDataSignal, this, [this](WebotsData webotsData)
    {
        emit chartList[0]->addDataSignal(0, webotsData.dspTime, webotsData.input[0]);
        emit chartList[0]->addDataSignal(1, webotsData.dspTime, webotsData.speed[0]);
        emit chartList[0]->addDataSignal(2, webotsData.dspTime, webotsData.position[0]);
        emit chartList[0]->addDataSignal(3, webotsData.dspTime, webotsData.torque[0]);
        emit chartList[0]->addDataSignal(4, webotsData.dspTime, webotsData.error[0]);

        emit chartList[2]->addDataSignal(0, webotsData.dspTime, webotsData.input[1]);
        emit chartList[2]->addDataSignal(1, webotsData.dspTime, webotsData.speed[1]);
        emit chartList[2]->addDataSignal(2, webotsData.dspTime, webotsData.position[1]);
        emit chartList[2]->addDataSignal(3, webotsData.dspTime, webotsData.torque[1]);
        emit chartList[2]->addDataSignal(4, webotsData.dspTime, webotsData.error[1]);

        emit chartList[1]->addDataSignal(0, webotsData.dspTime, webotsData.missDistance[0]);
        emit chartList[3]->addDataSignal(0, webotsData.dspTime, webotsData.missDistance[1]);
        emit chartList[0]->addDataSignal(5, webotsData.dspTime, webotsData.guidePos[0]);
        emit chartList[2]->addDataSignal(5, webotsData.dspTime, webotsData.guidePos[1]);

        emit chartList[3]->addDataSignal(1, webotsData.dspTime, webotsData.omega[0]);
        emit chartList[3]->addDataSignal(2, webotsData.dspTime, webotsData.omega[1]);
        emit chartList[1]->addDataSignal(1, webotsData.dspTime, webotsData.omega[2]);
    });

    zmqSubThread->start();

    //定时器启动
    timer1->start();

    QString strExePath = QCoreApplication::applicationDirPath();
    QString strSettingInfo = strExePath + "\\SettingInfo.ini";
    QSettings settings(strSettingInfo, QSettings::IniFormat);// 当前目录的SetInfo.ini文件，一定要添加第二个参数为IniFormat
    settings.beginGroup("Process");
    WId windowID = this->winId();
    settings.setValue("pro1", windowID);
    settings.endGroup();

    //正常显示大小
    //https://stackoverflow.com/questions/30162091/drawing-errors-and-crash-with-qwidgetcreatewindowcontainer
//    this->setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    for (auto & t : chartThread)
    {
        t->quit();
    }
    zmqSubThread->quit();
    delete ui;
}

void MainWindow::receiveStateData(DisplayDataStruct displayDataStruct)
{
    emit chartList[0]->addDataSignal(0, displayDataStruct.dspTime, displayDataStruct.input[0]);
    emit chartList[0]->addDataSignal(1, displayDataStruct.dspTime, displayDataStruct.speed[0]);
    emit chartList[0]->addDataSignal(2, displayDataStruct.dspTime, displayDataStruct.position[0]);
    emit chartList[0]->addDataSignal(3, displayDataStruct.dspTime, displayDataStruct.torque[0]);
    emit chartList[0]->addDataSignal(4, displayDataStruct.dspTime, displayDataStruct.error[0]);

    emit chartList[2]->addDataSignal(0, displayDataStruct.dspTime, displayDataStruct.input[1]);
    emit chartList[2]->addDataSignal(1, displayDataStruct.dspTime, displayDataStruct.speed[1]);
    emit chartList[2]->addDataSignal(2, displayDataStruct.dspTime, displayDataStruct.position[1]);
    emit chartList[2]->addDataSignal(3, displayDataStruct.dspTime, displayDataStruct.torque[1]);
    emit chartList[2]->addDataSignal(4, displayDataStruct.dspTime, displayDataStruct.error[1]);

    emit chartList[1]->addDataSignal(2, displayDataStruct.dspTime, displayDataStruct.cpuUsage);
    emit chartList[3]->addDataSignal(3, displayDataStruct.dspTime, displayDataStruct.atpState);

    if(int(displayDataStruct.dspTime*1000) % 50 == 0)
        this->windowDisplayData = displayDataStruct;
}

void MainWindow::receiveATPData(ATPSensorData atpSensorData)
{
    double time = atpSensorData.count / 1000.0;
    emit chartList[1]->addDataSignal(0, time, atpSensorData.missDistance[0]);
    emit chartList[3]->addDataSignal(0, time, atpSensorData.missDistance[1]);
    emit chartList[0]->addDataSignal(5, time, atpSensorData.guidePos[0]);
    emit chartList[2]->addDataSignal(5, time, atpSensorData.guidePos[1]);

    emit chartList[3]->addDataSignal(1, time, atpSensorData.omega[0]);
    emit chartList[3]->addDataSignal(2, time, atpSensorData.omega[1]);
    emit chartList[1]->addDataSignal(1, time, atpSensorData.omega[2]);
}

void MainWindow::on_timer1_timeout()
{
    for(auto& chart : chartList)
    {
        emit chart->replotSignal();
    }

    ui->label_input1->setText(QString::number(windowDisplayData.input[0], 'f', 6));
    ui->label_position1->setText(QString::number(windowDisplayData.position[0], 'f', 6));
    ui->label_speed1->setText(QString::number(windowDisplayData.speed[0], 'f', 6));
    ui->label_torque1->setText(QString::number(windowDisplayData.torque[0], 'f', 6));
    ui->label_error1->setText(QString::number(windowDisplayData.error[0], 'f', 6));
    ui->label_input2->setText(QString::number(windowDisplayData.input[1], 'f', 6));
    ui->label_position2->setText(QString::number(windowDisplayData.position[1], 'f', 6));
    ui->label_speed2->setText(QString::number(windowDisplayData.speed[1], 'f', 6));
    ui->label_torque2->setText(QString::number(windowDisplayData.torque[1], 'f', 6));
    ui->label_error2->setText(QString::number(windowDisplayData.error[1], 'f', 6));

    ui->label_imu_state->setText(QString::number(windowDisplayData.imuState, 16));
    ui->label_imu_omega_x->setText(QString::number(windowDisplayData.omega[0], 'f', 6));
    ui->label_imu_omega_y->setText(QString::number(windowDisplayData.omega[1], 'f', 6));
    ui->label_imu_omega_z->setText(QString::number(windowDisplayData.omega[2], 'f', 6));

//    windowDisplayData.dspTime += 0.01;
//    receiveStateData(windowDisplayData);
}

void MainWindow::saveChartData(QVector<QCustomPlot *> chartList)
{
    chartDataSaveWindow->show();
    chartDataSaveWindow->activateWindow();
    chartDataSaveWindow->setWindowState((chartDataSaveWindow->windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
    chartDataSaveWindow->setCharts(std::move(chartList));
}
