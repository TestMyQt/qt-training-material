#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "rpmengine.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    RpmEngine rpmengine;

    QObject::connect(&rpmengine, &RpmEngine::rpmReady, [=](int rpm){
        qDebug()<<"Rpm : "<<rpm;
    });

    QObject::connect(&rpmengine, &RpmEngine::speedReady, [=](int speed){
        qDebug()<<"Speed : "<<speed;
    });

    QObject::connect(&rpmengine, &RpmEngine::fuelReady, [=](qreal fuel){
        qDebug()<<"Fuel : "<<fuel;
    });

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
