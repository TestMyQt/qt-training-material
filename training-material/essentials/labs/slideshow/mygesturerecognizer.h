#ifndef MYGESTURERECOGNIZER_H
#define MYGESTURERECOGNIZER_H

#include <QGestureRecognizer>
#include <QGesture>
#include <QtCore/QEvent>
#include <QtGui/QMouseEvent>
#include "mygesture.h"

class MyGestureRecognizer : public QGestureRecognizer
{
public:
    MyGestureRecognizer();
    ~MyGestureRecognizer();

    QGestureRecognizer::Result recognize(QGesture* gesture, QObject* watched, QEvent* event);
    QGesture* create(QObject* target);
    void reset(QGesture* gesture);

    // friend class MyGesture;
};

#endif // MYGESTURERECOGNIZER_H
