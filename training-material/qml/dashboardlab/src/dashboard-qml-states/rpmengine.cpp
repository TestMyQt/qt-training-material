#include "rpmengine.h"
#include <QGuiApplication>

RpmEngine::RpmEngine(QObject *parent) : QThread(parent),
                                        m_speed(0),
                                        m_rpm(0),
                                        m_increase(true)
{
}

RpmEngine::~RpmEngine()
{
    requestInterruption();
    while (isRunning()) {
        msleep(10);
    }
}

void RpmEngine::generateRpm()
{
    if(m_rpm < 1000) {
        m_rpm = 1000;
        m_increase = true;
    }
    else if(m_rpm > 8000) {
        m_rpm = 8000;
        m_increase = false;
    }
    else
        m_increase = qrand() % 2;
    if(m_increase)
        m_rpm += qrand()%500;
    else
        m_rpm -= qrand()%500;
    emit rpmReady(1000+m_rpm);
}

void RpmEngine::generateSpeed()
{
    if(m_increase)
        m_speed += qrand()%20;
    else
        m_speed -= qrand()%20;
    if(m_speed>300)
       m_speed = 300;
    else if(m_speed<0)
        m_speed = 0;
    emit speedReady(m_speed);
}

void RpmEngine::run()
{
    while(!isInterruptionRequested()) {
        generateRpm();
        generateSpeed();
        msleep(100);
    }
}
