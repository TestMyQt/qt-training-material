#include <QDebug>
#include "receiver.h"
#include "data.h"

Receiver::Receiver(QObject *parent) :
    QObject(parent)
{
}

// 2.a.
void Receiver::simpleReceiverSlot(Data &data)
{
    qDebug() << "Receiver: Simple slot called: " << data.m_integer << " " << *data.m_pointer << " " << data.m_string;

    // 2.d.
    int *intPointer = new int(24);
    data.changeData(10, intPointer, "olleH");
}

