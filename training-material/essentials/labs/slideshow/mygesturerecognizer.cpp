#include "mygesturerecognizer.h"

MyGestureRecognizer::MyGestureRecognizer() : QGestureRecognizer()
{
    // Nothing to do here
}

MyGestureRecognizer::~MyGestureRecognizer()
{
    // Nothing to do here
}

QGestureRecognizer::Result MyGestureRecognizer::recognize(QGesture* gesture, QObject* watched, QEvent* event)
{
    Q_UNUSED(watched)
    MyGesture* g = static_cast<MyGesture*>(gesture);
    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

    QGestureRecognizer::Result result;
    switch(event->type()) {
        case QEvent::MouseButtonPress:
            g->m_gestureStartPos = mouseEvent->pos();
            g->m_gestureStarted = true;
            result = QGestureRecognizer::MayBeGesture;
            break;
        case QEvent::MouseButtonRelease:
            if (g->m_gestureStarted)
            {
                g->m_gestureEndPos = mouseEvent->pos();
                int xDistance = qAbs(g->m_gestureStartPos.x() - g->m_gestureEndPos.x());
                // We only consider it a proper gesture if the mouse has moved 50
                // pixels while pressed
                if (xDistance > 50)
                {
                    result = QGestureRecognizer::FinishGesture;
                    break;
                }
            }
            result = QGestureRecognizer::CancelGesture;
            break;
        default:
            result = QGestureRecognizer::Ignore;
    }
    return result;
}

QGesture* MyGestureRecognizer::create(QObject* target)
{
    Q_UNUSED(target)
    return new MyGesture();
}

void MyGestureRecognizer::reset(QGesture *gesture)
{
    MyGesture* g = static_cast<MyGesture*>(gesture);

    g->m_gestureStarted = false;
    g->m_gestureStartPos = QPointF();
    g->m_gestureEndPos = QPointF();

    QGestureRecognizer::reset(gesture);
}
