#include "rpmengine.h"

RpmEngine::RpmEngine(QObject *parent) : QObject(parent),
                                        m_speed(0),
                                        m_rpm(0),
                                        m_increase(true),
                                        m_fuel(70)
{
    connect(&m_timer, &QTimer::timeout, this, &RpmEngine::generateRpm );
    connect(&m_timer, &QTimer::timeout, this, &RpmEngine::generateSpeed );
    connect(&m_timer, &QTimer::timeout, this, &RpmEngine::generateFuel );
    m_timer.start(500);
}

void RpmEngine::generateRpm()
{
    if(m_rpm < 1000)
        m_increase = true;
    else if(m_rpm > 8000)
        m_increase = false;
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
        m_speed += qrand()%10;
    else
        m_speed -= qrand()%10;
    if(m_speed>300)
       m_speed = 300;
    else if(m_speed<0)
        m_speed = 0;
    emit speedReady(m_speed);
}

void RpmEngine::generateFuel()
{
    m_fuel-=0.1;
    if(m_fuel==0)
        m_timer.stop();
    emit fuelReady(m_fuel);
}
