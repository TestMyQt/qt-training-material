#include <QGuiApplication>
#include <QQmlApplicationEngine>
#ifndef __MINGW32__
#include <QtWebEngine/qtwebengineglobal.h>
#endif
#include "imagemodel.h"
#include "incubator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

#ifndef __MINGW32__
    QtWebEngine::initialize();
#endif

    qmlRegisterType<ImageModel>("ImageModule", 1, 0, "ImageModel");
    Incubator incubator;

    QQmlApplicationEngine engine;
    engine.setIncubationController(&incubator);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
