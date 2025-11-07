#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ChartDisplay.h"
#include "ZmqSubThread.h"
#include "ChartDataSave/ChartDataSave.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer* timer1 = nullptr;

    ChartDisplay* chart1 = nullptr;
    ChartDisplay* chart2 = nullptr;
    ChartDisplay* chart3 = nullptr;
    ChartDisplay* chart4 = nullptr;
    QThread* chartThread[4];
    QVector<ChartDisplay*> chartList;
    QVector<QStringList> chartNamesList;
    QVector<QColor> colorList;

    ZmqSubThread* zmqSubThread;

    ChartDataSave* chartDataSaveWindow;
    QVector<QCustomPlot*> servoCharts;

    DisplayDataStruct windowDisplayData;

public slots:
    void receiveStateData(DisplayDataStruct displayDataStruct);
    void receiveATPData(ATPSensorData atpSensorData);
    void on_timer1_timeout();
    void saveChartData(QVector<QCustomPlot *> chartList);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
