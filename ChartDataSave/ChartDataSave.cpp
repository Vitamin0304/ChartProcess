//
// Created by bohan on 2022/11/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChartDataSave.h" resolved

#include "ChartDataSave.h"
#include "ui_ChartDataSave.h"
#include <fstream>
#include "../definitions.h"

ChartDataSave::ChartDataSave(QWidget *parent) :
        QWidget(parent), ui(new Ui::ChartDataSave)
{
    ui->setupUi(this);


    connect(ui->saveButton, &QPushButton::clicked, this, &ChartDataSave::saveData);
}

ChartDataSave::~ChartDataSave()
{
    delete ui;
}

void ChartDataSave::setCharts(QVector<QCustomPlot *> charts)
{
    this->chartList = charts;
}


void ChartDataSave::saveData()
{
    if(chartList.empty())
        return;

    QString path = QFileDialog::getExistingDirectory(this, "保存", "./");

    if(path == "")
        return;

    QDateTime curDateTime = QDateTime::currentDateTime();

    QString dataName = ui->dataName->text();
    QString title = QString("%1_%2")
                .arg(dataName, curDateTime.toString("yyyy-MM-dd_hh_mm_ss"));

    QString dirName = path + "/" + title;
    QDir().mkdir(dirName);

    ui->label_path->setText(dirName);

    double startTime = ui->doubleSpinBox_startTime->value();
    double editValue = ui->doubleSpinBox_timeSpan_endTime->value();

    double endTime;
    if(ui->comboBox_modeSet->currentIndex() == 0)
    {
        if(editValue < 0.1)
        {
            QMessageBox::critical(this, "错误", "时间输入错误或不足0.1s");
            return;
        }
        endTime = startTime + editValue;
    }
    else
    {
        if(startTime >= editValue - 0.1)
        {
            QMessageBox::critical(this, "错误", "时间输入错误或不足0.1s");
            return;
        }
        endTime = editValue;
    }

    int chartCount = chartList.count();
    for (int i = 0; i < chartCount; ++i)
    {
        QCustomPlot* plot = chartList[i];
        int graphCount = plot->graphCount();
        for(int j = 0; j < graphCount; j++)
        {
            int dataCount = plot->graph(j)->dataCount();
            if(dataCount == 0)
                continue;

            QString graphName = plot->graph(j)->name();
            QFile file(QString("%1/chart%2_%3.csv").arg(dirName).arg(i).arg(graphName));
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                return;

//            QTextStream outFile(&file);
//
//            QString outStr;
//            QTextStream out(&outStr, QIODevice::WriteOnly);

            QTextStream out(&file);

            out << "x," << graphName << "\n";

            for(int k = 0; k < dataCount; k++)
            {
                double key = plot->graph(j)->data()->at(k)->key;

                //限定保存时间
                if(key < startTime || key > endTime)
                    continue;

                double value = plot->graph(j)->data()->at(k)->value;
                out << QString::number(key, 'f', 3) << ",";
                out << QString::number(value, 'g', 7) << "\n";
            }

//            outFile << outStr;
        }
    }
}
