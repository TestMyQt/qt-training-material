#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "rpmengine.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    //qputenv("QSG_VISUALIZE","overdraw");
    qputenv("QT_LOGGING_RULES","qt.scenegraph.*=true");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    /*RpmEngine rpmengine;

    rpmengine.start();*/

    qmlRegisterType<RpmEngine>("com.hmc", 1, 0, "RpmEngine");

    QQmlApplicationEngine engine;
    //engine.rootContext()->setContextProperty("rpmEngine",&rpmengine);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
