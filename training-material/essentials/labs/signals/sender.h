#ifndef SENDER_H
#define SENDER_H

#include <QPushButton>

class Data;

class Sender : public QPushButton
{
    Q_OBJECT
public:
    explicit Sender(QWidget *parent = 0);

};

#endif // SENDER_H
