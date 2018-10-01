#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QColor>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Expose a QColor and a string to QML using QDeclarativeContext.
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("myBackgroundColor", QColor(Qt::yellow));
    context->setContextProperty("myText", "Hi, I'm text from C++!");

    // Expose the application object so that we can use it in QML to quit the app
    // Normally, Qt.quit() is used, but this demonstrates, how to call slots from QML
    context->setContextProperty("application", &app);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
