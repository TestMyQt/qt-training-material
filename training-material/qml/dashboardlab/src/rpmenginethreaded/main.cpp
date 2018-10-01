#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QThread>
#include "rpmengine.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QThread thread;
    RpmEngine rpmengine;

    rpmengine.moveToThread(&thread);
    thread.start();
    QObject::connect(&thread, &QThread::started, &rpmengine, &RpmEngine::generate);
    QObject::connect(qApp, &QGuiApplication::aboutToQuit, &thread, &QThread::quit);

    QObject::connect(&rpmengine, &RpmEngine::rpmReady, [=](int rpm){
        qDebug()<<"Rpm : "<<rpm;
    });

    QObject::connect(&rpmengine, &RpmEngine::speedReady, [=](int speed){
        qDebug()<<"Speed : "<<speed;
    });

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
