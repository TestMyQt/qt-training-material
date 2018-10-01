#ifndef SENDER_H
#define SENDER_H

#include <QPushButton>

class Sender : public QPushButton
{
    Q_OBJECT
public:
    explicit Sender(QWidget *parent = 0);

Q_SIGNALS:
    void data( int );

protected Q_SLOTS:
    void emitData();

private:
    int m_Counter;
};

#endif // SENDER_H
