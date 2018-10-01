#ifndef MYGESTURE_H
#define MYGESTURE_H

#include <QGesture>
#include <QtCore/QPointF>

class MyGesture : public QGesture
{
    Q_OBJECT

public:
    enum Direction {
        NoDirection = 0,
        Left,
        Right
    };

    MyGesture(QObject* parent = 0);
    ~MyGesture();

    Direction gestureDirection();

private:
    QPointF m_gestureStartPos;
    QPointF m_gestureEndPos;
    bool m_gestureStarted;
    friend class MyGestureRecognizer;
};

#endif // MYGESTURE_H
