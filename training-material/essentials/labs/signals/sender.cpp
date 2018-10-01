#include <QDebug>
#include "sender.h"
#include "data.h"

Sender::Sender(QWidget *parent) :
    QPushButton("Press me", parent)
{
    setMinimumSize(400, 200);

}
