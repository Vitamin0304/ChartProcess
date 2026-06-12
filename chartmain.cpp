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
    // QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling); // 1. 关自动缩放
    // QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, false); // 2. 关高分 pixmap

    QApplication a(argc, argv);

    // 在创建 QApplication 之前设置默认的 OpenGL 格式
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(3, 3);
    // format.setShareContext(false); // 在某些 Qt 版本中可以尝试不共享上下文
    QSurfaceFormat::setDefaultFormat(format);

    // QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

    // QTranslator translator;
    // const QStringList uiLanguages = QLocale::system().uiLanguages();
    // for (const QString &locale : uiLanguages) {
    //     const QString baseName = "chart_demo_" + QLocale(locale).name();
    //     if (translator.load(":/i18n/" + baseName)) {
    //         a.installTranslator(&translator);
    //         break;
    //     }
    // }

    QFile file("my_theme.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet { file.readAll() };
    qApp->setStyleSheet(styleSheet);

    QFont font("微软雅黑",11);
    QApplication::setFont(font);

    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
