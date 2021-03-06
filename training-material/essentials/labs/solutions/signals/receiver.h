#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Data;

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);

public Q_SLOTS:
    // 2.a.
    void simpleReceiverSlot(Data &data);
};

#endif // RECEIVER_H
