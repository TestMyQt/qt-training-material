#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject *root = engine.rootObjects().at(0);
    QQuickItem *item = root->findChild<QQuickItem *>("blueRect");
    item->setRotation(45);

    return app.exec();
}
