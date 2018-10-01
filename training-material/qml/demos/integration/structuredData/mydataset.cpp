#include <QDebug>
#include "mydataset.h"

MyDataSet::MyDataSet(QObject *parent) :
    QObject(parent), mColor(QColor(Qt::lightGray)), mText("Hi, I'm text from C++!")
{
    startTimer(1000);
}

void MyDataSet::timerEvent(QTimerEvent *)
{
    int red(qrand() % 256);
    int green(qrand() % 256);
    int blue(qrand() % 256);
    qDebug() << red << " " << green << " " << blue;
    setProperty("myBackgroundColor", QColor(red, green, blue));
}
