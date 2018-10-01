#include "model.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QListView>

int main(int argc, char ** argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    AnimalModel model;
    model.addAnimal(Animal("Wolf", "Medium"));
    model.addAnimal(Animal("Polar bear", "Large"));
    model.addAnimal(Animal("Quoll", "Small"));

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("myModel", &model);

    engine.load(QUrl(QStringLiteral("qrc:/view.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QListView listView;
    listView.setModel(&model);
    listView.show();

    return app.exec();
}

