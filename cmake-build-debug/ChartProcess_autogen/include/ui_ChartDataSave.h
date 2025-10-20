/********************************************************************************
** Form generated from reading UI file 'ChartDataSave.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTDATASAVE_H
#define UI_CHARTDATASAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartDataSave
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_startTime;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_modeSet;
    QDoubleSpinBox *doubleSpinBox_timeSpan_endTime;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *dataName;
    QLabel *label;
    QLabel *label_path;
    QPushButton *saveButton;

    void setupUi(QWidget *ChartDataSave)
    {
        if (ChartDataSave->objectName().isEmpty())
            ChartDataSave->setObjectName(QString::fromUtf8("ChartDataSave"));
        ChartDataSave->resize(1228, 529);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChartDataSave->sizePolicy().hasHeightForWidth());
        ChartDataSave->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ChartDataSave);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(ChartDataSave);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        doubleSpinBox_startTime = new QDoubleSpinBox(ChartDataSave);
        doubleSpinBox_startTime->setObjectName(QString::fromUtf8("doubleSpinBox_startTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox_startTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_startTime->setSizePolicy(sizePolicy1);
        doubleSpinBox_startTime->setMinimumSize(QSize(188, 30));
        doubleSpinBox_startTime->setDecimals(3);
        doubleSpinBox_startTime->setMaximum(999999.000000000000000);

        gridLayout->addWidget(doubleSpinBox_startTime, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        comboBox_modeSet = new QComboBox(ChartDataSave);
        comboBox_modeSet->addItem(QString());
        comboBox_modeSet->addItem(QString());
        comboBox_modeSet->setObjectName(QString::fromUtf8("comboBox_modeSet"));
        comboBox_modeSet->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(comboBox_modeSet, 1, 1, 1, 1);

        doubleSpinBox_timeSpan_endTime = new QDoubleSpinBox(ChartDataSave);
        doubleSpinBox_timeSpan_endTime->setObjectName(QString::fromUtf8("doubleSpinBox_timeSpan_endTime"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_timeSpan_endTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_timeSpan_endTime->setSizePolicy(sizePolicy1);
        doubleSpinBox_timeSpan_endTime->setMinimumSize(QSize(188, 30));
        doubleSpinBox_timeSpan_endTime->setDecimals(3);
        doubleSpinBox_timeSpan_endTime->setMaximum(999999.000000000000000);
        doubleSpinBox_timeSpan_endTime->setValue(1800.000000000000000);

        gridLayout->addWidget(doubleSpinBox_timeSpan_endTime, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        label_2 = new QLabel(ChartDataSave);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        dataName = new QLineEdit(ChartDataSave);
        dataName->setObjectName(QString::fromUtf8("dataName"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dataName->sizePolicy().hasHeightForWidth());
        dataName->setSizePolicy(sizePolicy2);
        dataName->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(dataName, 2, 2, 1, 1);

        label = new QLabel(ChartDataSave);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        label_path = new QLabel(ChartDataSave);
        label_path->setObjectName(QString::fromUtf8("label_path"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_path->sizePolicy().hasHeightForWidth());
        label_path->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_path, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        saveButton = new QPushButton(ChartDataSave);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy4);
        saveButton->setMinimumSize(QSize(101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        saveButton->setFont(font);

        verticalLayout->addWidget(saveButton, 0, Qt::AlignHCenter);


        retranslateUi(ChartDataSave);

        QMetaObject::connectSlotsByName(ChartDataSave);
    } // setupUi

    void retranslateUi(QWidget *ChartDataSave)
    {
        ChartDataSave->setWindowTitle(QCoreApplication::translate("ChartDataSave", "\346\233\262\347\272\277\345\233\276\346\225\260\346\215\256\344\277\235\345\255\230", nullptr));
        label_3->setText(QCoreApplication::translate("ChartDataSave", "\350\265\267\345\247\213\346\227\266\345\210\273", nullptr));
        comboBox_modeSet->setItemText(0, QCoreApplication::translate("ChartDataSave", "\346\214\201\347\273\255\346\227\266\351\227\264", nullptr));
        comboBox_modeSet->setItemText(1, QCoreApplication::translate("ChartDataSave", "\347\273\210\346\255\242\346\227\266\345\210\273", nullptr));

        label_2->setText(QCoreApplication::translate("ChartDataSave", "\346\225\260\346\215\256\345\220\215\347\247\260", nullptr));
        dataName->setText(QCoreApplication::translate("ChartDataSave", "\346\233\262\347\272\277\346\225\260\346\215\256", nullptr));
        label->setText(QCoreApplication::translate("ChartDataSave", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        label_path->setText(QCoreApplication::translate("ChartDataSave", "\350\267\257\345\276\204", nullptr));
        saveButton->setText(QCoreApplication::translate("ChartDataSave", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartDataSave: public Ui_ChartDataSave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTDATASAVE_H
