#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickItem>
#include <QTimer>

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

    // Call a QML method directly using QMetaObject...
    QQuickItem *item = engine.rootObjects().at(0)->findChild<QQuickItem *>("rectangle");
    QMetaObject::invokeMethod(item, "toggleText");

    // ...or by connecting a signal to it (in this case from a timer, could be any
    // custom signal as well)
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), item, SLOT(toggleText()));
    timer.setInterval(1000);
    timer.start();

    return app.exec();
}






