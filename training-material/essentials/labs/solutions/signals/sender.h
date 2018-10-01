#ifndef SENDER_H
#define SENDER_H

#include <QPushButton>

class Data;

class Sender : public QPushButton
{
    Q_OBJECT
public:
    explicit Sender(QWidget *parent = 0);

Q_SIGNALS:
    // 1.b.
    void simpleOverloadedSignal();
    // 1.d.
    void simpleOverloadedSignal(Data &data);

private Q_SLOTS:
    // 1.b.
    void simpleSlot();

};

#endif // SENDER_H
