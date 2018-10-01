#include "sender.h"
#include <QMainWindow>
Sender::Sender(QWidget *parent) :
    QPushButton("Press me", parent), m_Counter(0)
{
#if QT_VERSION < 0x050000
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(emitData()));
#else
    connect(this, &QPushButton::clicked, this, &Sender::emitData);
#endif

    QMetaObject::invokeMethod(this, "emitData", Qt::QueuedConnection);
    // Trying to do an emit here would not help, as the connection has not yet been
    // set up.
    //emitData();
}


void Sender::emitData()
{
    Q_EMIT data(m_Counter++);
}

