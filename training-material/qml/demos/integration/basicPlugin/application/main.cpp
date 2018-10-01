#include <QGuiApplication>
#include <QDir>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/files/ellipse9.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
