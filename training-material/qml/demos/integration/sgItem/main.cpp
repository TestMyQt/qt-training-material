#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "triangleitem.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<TriangleItem>("ShapeObjects", 1, 0, "Triangle");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/triangletest.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
