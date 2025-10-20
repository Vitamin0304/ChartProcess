/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot_old.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_chart;
    QGridLayout *gridLayout_11;
    QCustomPlot *chart1;
    QCustomPlot *chart3;
    QCustomPlot *chart4;
    QLabel *label_56;
    QLabel *label_55;
    QCustomPlot *chart2;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_12;
    QLabel *label_51;
    QLabel *label_48;
    QLabel *label_error2;
    QLabel *label_31;
    QLabel *label_36;
    QSpacerItem *verticalSpacer_17;
    QLabel *label_imu_omega_y;
    QLabel *label_27;
    QLabel *label_imu_state;
    QLabel *label_49;
    QLabel *label_torque2;
    QLabel *label_52;
    QLabel *label_35;
    QLabel *label_torque1;
    QLabel *label_37;
    QLabel *label_error1;
    QLabel *label_34;
    QLabel *label_29;
    QLabel *label_28;
    QLabel *label_imu_omega_z;
    QLabel *label_imu_omega_x;
    QLabel *label_input1;
    QLabel *label_33;
    QLabel *label_30;
    QLabel *label_26;
    QLabel *label_position1;
    QLabel *label_32;
    QLabel *label_speed1;
    QLabel *label_position2;
    QLabel *label_50;
    QLabel *label_input2;
    QLabel *label_speed2;
    QSpacerItem *verticalSpacer_18;
    QGroupBox *showModeGroupBox;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_14;
    QVBoxLayout *verticalLayout_11;
    QRadioButton *manualButton;
    QRadioButton *translationButton;
    QRadioButton *stretchButton;
    QSpacerItem *verticalSpacer_15;
    QPushButton *globalButton;
    QPushButton *nowButton;
    QPushButton *clearButton;
    QSpacerItem *verticalSpacer_20;
    QPushButton *saveChartButton;
    QSpacerItem *verticalSpacer_16;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1400, 713);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_chart = new QGroupBox(centralwidget);
        groupBox_chart->setObjectName(QString::fromUtf8("groupBox_chart"));
        groupBox_chart->setStyleSheet(QString::fromUtf8(""));
        gridLayout_11 = new QGridLayout(groupBox_chart);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        chart1 = new QCustomPlot(groupBox_chart);
        chart1->setObjectName(QString::fromUtf8("chart1"));

        gridLayout_11->addWidget(chart1, 1, 0, 1, 1);

        chart3 = new QCustomPlot(groupBox_chart);
        chart3->setObjectName(QString::fromUtf8("chart3"));

        gridLayout_11->addWidget(chart3, 1, 1, 1, 1);

        chart4 = new QCustomPlot(groupBox_chart);
        chart4->setObjectName(QString::fromUtf8("chart4"));

        gridLayout_11->addWidget(chart4, 2, 1, 1, 1);

        label_56 = new QLabel(groupBox_chart);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        label_56->setFont(font);
        label_56->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_56, 0, 1, 1, 1);

        label_55 = new QLabel(groupBox_chart);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setMaximumSize(QSize(16777215, 20));
        label_55->setFont(font);
        label_55->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_55, 0, 0, 1, 1);

        chart2 = new QCustomPlot(groupBox_chart);
        chart2->setObjectName(QString::fromUtf8("chart2"));

        gridLayout_11->addWidget(chart2, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_chart, 0, 0, 2, 1);

        groupBox_13 = new QGroupBox(centralwidget);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_13->sizePolicy().hasHeightForWidth());
        groupBox_13->setSizePolicy(sizePolicy);
        groupBox_13->setMaximumSize(QSize(260, 111111));
        gridLayout_12 = new QGridLayout(groupBox_13);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_51 = new QLabel(groupBox_13);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setMaximumSize(QSize(80, 16777215));
        label_51->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_51, 16, 0, 1, 1);

        label_48 = new QLabel(groupBox_13);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_48->setFont(font1);

        gridLayout_12->addWidget(label_48, 13, 0, 1, 1);

        label_error2 = new QLabel(groupBox_13);
        label_error2->setObjectName(QString::fromUtf8("label_error2"));
        label_error2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_error2, 12, 1, 1, 1);

        label_31 = new QLabel(groupBox_13);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMaximumSize(QSize(80, 16777215));
        label_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_31, 6, 0, 1, 1);

        label_36 = new QLabel(groupBox_13);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMaximumSize(QSize(80, 16777215));
        label_36->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_36, 9, 0, 1, 1);

        verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_17, 0, 0, 1, 1);

        label_imu_omega_y = new QLabel(groupBox_13);
        label_imu_omega_y->setObjectName(QString::fromUtf8("label_imu_omega_y"));
        label_imu_omega_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_imu_omega_y, 16, 1, 1, 1);

        label_27 = new QLabel(groupBox_13);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMaximumSize(QSize(80, 16777215));
        label_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_27, 2, 0, 1, 1);

        label_imu_state = new QLabel(groupBox_13);
        label_imu_state->setObjectName(QString::fromUtf8("label_imu_state"));
        label_imu_state->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_imu_state, 14, 1, 1, 1);

        label_49 = new QLabel(groupBox_13);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setMaximumSize(QSize(80, 16777215));
        label_49->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_49, 14, 0, 1, 1);

        label_torque2 = new QLabel(groupBox_13);
        label_torque2->setObjectName(QString::fromUtf8("label_torque2"));
        label_torque2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_torque2, 11, 1, 1, 1);

        label_52 = new QLabel(groupBox_13);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setMaximumSize(QSize(80, 16777215));
        label_52->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_52, 17, 0, 1, 1);

        label_35 = new QLabel(groupBox_13);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setFont(font1);

        gridLayout_12->addWidget(label_35, 7, 0, 1, 1);

        label_torque1 = new QLabel(groupBox_13);
        label_torque1->setObjectName(QString::fromUtf8("label_torque1"));
        label_torque1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_torque1, 5, 1, 1, 1);

        label_37 = new QLabel(groupBox_13);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMaximumSize(QSize(80, 16777215));
        label_37->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_37, 12, 0, 1, 1);

        label_error1 = new QLabel(groupBox_13);
        label_error1->setObjectName(QString::fromUtf8("label_error1"));
        label_error1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_error1, 6, 1, 1, 1);

        label_34 = new QLabel(groupBox_13);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setMaximumSize(QSize(80, 16777215));
        label_34->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_34, 10, 0, 1, 1);

        label_29 = new QLabel(groupBox_13);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMaximumSize(QSize(80, 16777215));
        label_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_29, 4, 0, 1, 1);

        label_28 = new QLabel(groupBox_13);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMaximumSize(QSize(80, 16777215));
        label_28->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_28, 3, 0, 1, 1);

        label_imu_omega_z = new QLabel(groupBox_13);
        label_imu_omega_z->setObjectName(QString::fromUtf8("label_imu_omega_z"));
        label_imu_omega_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_imu_omega_z, 17, 1, 1, 1);

        label_imu_omega_x = new QLabel(groupBox_13);
        label_imu_omega_x->setObjectName(QString::fromUtf8("label_imu_omega_x"));
        label_imu_omega_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_imu_omega_x, 15, 1, 1, 1);

        label_input1 = new QLabel(groupBox_13);
        label_input1->setObjectName(QString::fromUtf8("label_input1"));
        label_input1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_input1, 2, 1, 1, 1);

        label_33 = new QLabel(groupBox_13);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMaximumSize(QSize(80, 16777215));
        label_33->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_33, 8, 0, 1, 1);

        label_30 = new QLabel(groupBox_13);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMaximumSize(QSize(80, 16777215));
        label_30->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_30, 5, 0, 1, 1);

        label_26 = new QLabel(groupBox_13);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setBold(true);
        font2.setWeight(75);
        label_26->setFont(font2);

        gridLayout_12->addWidget(label_26, 1, 0, 1, 1);

        label_position1 = new QLabel(groupBox_13);
        label_position1->setObjectName(QString::fromUtf8("label_position1"));
        label_position1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_position1, 3, 1, 1, 1);

        label_32 = new QLabel(groupBox_13);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMaximumSize(QSize(80, 16777215));
        label_32->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_32, 11, 0, 1, 1);

        label_speed1 = new QLabel(groupBox_13);
        label_speed1->setObjectName(QString::fromUtf8("label_speed1"));
        label_speed1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_speed1, 4, 1, 1, 1);

        label_position2 = new QLabel(groupBox_13);
        label_position2->setObjectName(QString::fromUtf8("label_position2"));
        label_position2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_position2, 9, 1, 1, 1);

        label_50 = new QLabel(groupBox_13);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setMaximumSize(QSize(80, 16777215));
        label_50->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_50, 15, 0, 1, 1);

        label_input2 = new QLabel(groupBox_13);
        label_input2->setObjectName(QString::fromUtf8("label_input2"));
        label_input2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_input2, 8, 1, 1, 1);

        label_speed2 = new QLabel(groupBox_13);
        label_speed2->setObjectName(QString::fromUtf8("label_speed2"));
        label_speed2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_speed2, 10, 1, 1, 1);

        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_18, 18, 0, 1, 1);


        gridLayout->addWidget(groupBox_13, 0, 1, 1, 1);

        showModeGroupBox = new QGroupBox(centralwidget);
        showModeGroupBox->setObjectName(QString::fromUtf8("showModeGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(showModeGroupBox->sizePolicy().hasHeightForWidth());
        showModeGroupBox->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        showModeGroupBox->setFont(font3);
        verticalLayout_12 = new QVBoxLayout(showModeGroupBox);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_14);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        manualButton = new QRadioButton(showModeGroupBox);
        manualButton->setObjectName(QString::fromUtf8("manualButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(manualButton->sizePolicy().hasHeightForWidth());
        manualButton->setSizePolicy(sizePolicy2);
        manualButton->setFont(font3);

        verticalLayout_11->addWidget(manualButton, 0, Qt::AlignLeft);

        translationButton = new QRadioButton(showModeGroupBox);
        translationButton->setObjectName(QString::fromUtf8("translationButton"));
        sizePolicy2.setHeightForWidth(translationButton->sizePolicy().hasHeightForWidth());
        translationButton->setSizePolicy(sizePolicy2);
        translationButton->setFont(font3);

        verticalLayout_11->addWidget(translationButton, 0, Qt::AlignLeft);

        stretchButton = new QRadioButton(showModeGroupBox);
        stretchButton->setObjectName(QString::fromUtf8("stretchButton"));
        sizePolicy2.setHeightForWidth(stretchButton->sizePolicy().hasHeightForWidth());
        stretchButton->setSizePolicy(sizePolicy2);
        stretchButton->setFont(font3);
        stretchButton->setChecked(true);

        verticalLayout_11->addWidget(stretchButton, 0, Qt::AlignLeft);


        verticalLayout_12->addLayout(verticalLayout_11);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_15);

        globalButton = new QPushButton(showModeGroupBox);
        globalButton->setObjectName(QString::fromUtf8("globalButton"));
        sizePolicy2.setHeightForWidth(globalButton->sizePolicy().hasHeightForWidth());
        globalButton->setSizePolicy(sizePolicy2);
        globalButton->setMinimumSize(QSize(101, 41));
        globalButton->setFont(font3);

        verticalLayout_12->addWidget(globalButton, 0, Qt::AlignHCenter);

        nowButton = new QPushButton(showModeGroupBox);
        nowButton->setObjectName(QString::fromUtf8("nowButton"));
        sizePolicy2.setHeightForWidth(nowButton->sizePolicy().hasHeightForWidth());
        nowButton->setSizePolicy(sizePolicy2);
        nowButton->setMinimumSize(QSize(101, 41));

        verticalLayout_12->addWidget(nowButton, 0, Qt::AlignHCenter);

        clearButton = new QPushButton(showModeGroupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        sizePolicy2.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy2);
        clearButton->setMinimumSize(QSize(101, 41));
        clearButton->setFont(font3);

        verticalLayout_12->addWidget(clearButton, 0, Qt::AlignHCenter);

        verticalSpacer_20 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_20);

        saveChartButton = new QPushButton(showModeGroupBox);
        saveChartButton->setObjectName(QString::fromUtf8("saveChartButton"));
        sizePolicy2.setHeightForWidth(saveChartButton->sizePolicy().hasHeightForWidth());
        saveChartButton->setSizePolicy(sizePolicy2);
        saveChartButton->setMinimumSize(QSize(101, 41));
        saveChartButton->setFont(font3);

        verticalLayout_12->addWidget(saveChartButton, 0, Qt::AlignHCenter);

        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_16);


        gridLayout->addWidget(showModeGroupBox, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_chart->setTitle(QCoreApplication::translate("MainWindow", "\346\233\262\347\272\277\346\230\276\347\244\272", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "\344\277\257\344\273\260\350\275\264\347\212\266\346\200\201", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "\346\226\271\344\275\215\350\275\264\347\212\266\346\200\201", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\347\212\266\346\200\201", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "  y\350\275\264\350\247\222\351\200\237\345\272\246", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "IMU\357\274\232", nullptr));
        label_error2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "  \350\257\257\345\267\256", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "  \344\275\215\347\275\256", nullptr));
        label_imu_omega_y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "  \350\276\223\345\205\245", nullptr));
        label_imu_state->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "  \347\212\266\346\200\201", nullptr));
        label_torque2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "  z\350\275\264\350\247\222\351\200\237\345\272\246", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "\344\277\257\344\273\260\350\275\264\357\274\232", nullptr));
        label_torque1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "  \350\257\257\345\267\256", nullptr));
        label_error1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "  \351\200\237\345\272\246", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "  \351\200\237\345\272\246", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "  \344\275\215\347\275\256", nullptr));
        label_imu_omega_z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_imu_omega_x->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_input1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "  \350\276\223\345\205\245", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "  \345\212\233\347\237\251", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\345\201\217\350\210\252\350\275\264\357\274\232", nullptr));
        label_position1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "  \345\212\233\347\237\251", nullptr));
        label_speed1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_position2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "  x\350\275\264\350\247\222\351\200\237\345\272\246", nullptr));
        label_input2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_speed2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        showModeGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\233\262\347\272\277\346\230\276\347\244\272", nullptr));
        manualButton->setText(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250", nullptr));
        translationButton->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\271\263\347\247\273", nullptr));
        stretchButton->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\213\211\344\274\270", nullptr));
        globalButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\205\250\345\261\200", nullptr));
        nowButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\346\263\250\345\275\223\345\211\215", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\225\260\346\215\256", nullptr));
        saveChartButton->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
