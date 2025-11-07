#include "mainwindow.h"

#include <QtCore/QLocale>
#include <QtWidgets/QApplication>
#include <QtCore/QTranslator>
// #include <glut.h>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    // glutInit(&argc, argv);

    QApplication a(argc, argv);

    // QTranslator translator;
    // const QStringList uiLanguages = QLocale::system().uiLanguages();
    // for (const QString &locale : uiLanguages) {
    //     const QString baseName = "chart_demo_" + QLocale(locale).name();
    //     if (translator.load(":/i18n/" + baseName)) {
    //         a.installTranslator(&translator);
    //         break;
    //     }
    // }
    // // must give an absolute path to the "theme" folder
    // QDir::addSearchPath("icon", QDir::currentPath() + "/theme");
    //
    // QStringList dirs = QDir::searchPaths("icon");
    //
    // qDebug() << dirs[0];
    //
    // QFile file("my_theme.qss");
    // file.open(QFile::ReadOnly);
    //
    // QString styleSheet { file.readAll() };
    // qApp->setStyleSheet(styleSheet);


    // QFont font("微软雅黑",11);
    // QApplication::setFont(font);

    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
