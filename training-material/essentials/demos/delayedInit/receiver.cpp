#include "receiver.h"

Receiver::Receiver(QWidget *parent) :
    QTextEdit(parent)
{
}

void Receiver::data(int i)
{
    append(QString::number(i));
}
