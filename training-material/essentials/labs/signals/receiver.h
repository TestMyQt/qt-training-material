#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Data;

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);

};

#endif // RECEIVER_H
