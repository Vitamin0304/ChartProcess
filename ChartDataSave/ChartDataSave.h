//
// Created by bohan on 2022/11/22.
//

#ifndef QT_MASTER_CHARTDATASAVE_H
#define QT_MASTER_CHARTDATASAVE_H

#include <QWidget>
#include "../ChartDisplay.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class ChartDataSave;
}
QT_END_NAMESPACE

class ChartDataSave : public QWidget
{
Q_OBJECT

public:
    explicit ChartDataSave(QWidget *parent = nullptr);

    ~ChartDataSave() override;

private:
    Ui::ChartDataSave *ui;

    QVector<QCustomPlot*> chartList;

public slots:
    void setCharts(QVector<QCustomPlot*> chartList);
    void saveData();
};


#endif //QT_MASTER_CHARTDATASAVE_H
