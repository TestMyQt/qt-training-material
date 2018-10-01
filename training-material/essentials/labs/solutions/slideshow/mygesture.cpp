#include "mygesture.h"

MyGesture::MyGesture(QObject* parent) : QGesture(parent),
    m_gestureStartPos(QPointF()), m_gestureEndPos(QPointF()),
    m_gestureStarted(false)
{

}

MyGesture::~MyGesture()
{
    // Nothing to do here
}

MyGesture::Direction MyGesture::gestureDirection()
{
    if (!m_gestureStarted)
        return NoDirection;

    if (m_gestureEndPos.x() > m_gestureStartPos.x())
    {
        return Right;
    }
    else if (m_gestureEndPos.x() < m_gestureStartPos.x())
    {
        return Left;
    }
    else
    {
        return NoDirection;
    }
}
