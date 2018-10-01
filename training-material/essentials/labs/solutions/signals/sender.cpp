#include <QDebug>
#include "sender.h"
#include "data.h"

Sender::Sender(QWidget *parent) :
    QPushButton("Press me", parent)
{
    setMinimumSize(400, 200);

    // 1.c.
    //connect(this, &Sender::clicked, this, &Sender::simpleOverloadedSignal);
    //connect(this, &Sender::simpleOverloadedSignal, this, &Sender::simpleSlot);

    // 1.d.
    void (Sender:: *noParameters)() = &Sender::simpleOverloadedSignal;
    connect(this, &Sender::clicked, this, noParameters);
    connect(this, noParameters, this, &Sender::simpleSlot);

    // 3.
    QMetaObject::invokeMethod(this, "simpleSlot", Qt::QueuedConnection);
}

void Sender::simpleSlot()
{
    // 1.c.
    qDebug("Sender: Simple slot called");

    // 2.b.
    int *intPointer = new int(42);
    Data data(1, intPointer, "Hello");
    Q_EMIT simpleOverloadedSignal(data);

    // 2.e.
    qDebug() << "Sender: New data values: " << data.m_integer << " " << *data.m_pointer << " " << data.m_string;
}



