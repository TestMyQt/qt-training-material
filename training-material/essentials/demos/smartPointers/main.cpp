#include "exampleqobject.h"
#include <QCoreApplication>
#include <QPointer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);

    QPointer<ExampleQObject> object(new ExampleQObject);
    delete object;
    if (object)
        qDebug() << "Crash";
    else
        qDebug() << "No dangling pointer";


    // return application.exec();
}
