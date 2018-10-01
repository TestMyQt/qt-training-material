#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "cppperson.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Expose CppPerson type to QML via the Meta-Object system
    // as "Person" in the "People 1.0" module
    qmlRegisterType<CppPerson>("People", 1,0, "Person");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
