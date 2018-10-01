#include <QApplication>
#include <QDebug>
#include "receiver.h"
#include "sender.h"
#include "data.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    // 2.e.
    //qRegisterMetaType<Data>("Data");

    Sender sender;
    // 1.a.
    QScopedPointer<Receiver> receiverPtr(new Receiver());

    // 2.c.
    void (Sender:: *theSignal)(Data &) = &Sender::simpleOverloadedSignal;
    QObject::connect(&sender, theSignal, receiverPtr.data(), &Receiver::simpleReceiverSlot);
    // 2.e.
    //QObject::connect(&sender, theSignal, receiverPtr.data(), &Receiver::simpleReceiverSlot,Qt::QueuedConnection);
    // You need to change the parameter to 'const Data &' type and register Data type with meta-object system.

    sender.show();
    return application.exec();
}
