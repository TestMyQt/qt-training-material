import QtQuick 2.9

Item {
    property int m_rpm: 0
    property int m_speed: 0
    property bool m_increase: true

    signal rpmReady(int rpm);
    signal speedReady(int speed);
    function generateRpm()
    {
        if(m_rpm < 1000)
            m_increase = true;
        else if(m_rpm > 8000)
            m_increase = false;
        else {
            if(Math.random()>0.5)
                m_increase = true;
            else
                m_increase = false;
        }
        if(m_increase)
            m_rpm += Math.random()*8000%500;
        else
            m_rpm -= Math.random()*8000%500;
        rpmReady(1000+m_rpm);
    }

    function generateSpeed()
    {
        if(m_increase)
            m_speed += Math.random()*260%10;
        else
            m_speed -= Math.random()*260%10;
        if(m_speed>260)
           m_speed = 260;
        else if(m_speed<0)
            m_speed = 0;
        speedReady(m_speed);
    }

    Timer{
        repeat: true
        interval: 100
        running: true
        onTriggered: {
            generateRpm();
            generateSpeed();
        }
    }

}
