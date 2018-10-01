#ifndef RPMENGINE_H
#define RPMENGINE_H

#include <QObject>
#include <QTimer>

class RpmEngine : public QObject
{
    Q_OBJECT
public:
    explicit RpmEngine(QObject *parent = nullptr);

signals:
    void rpmReady(int rpm);
    void speedReady(int rpm);
    void fuelReady(qreal fuel);
public slots:
    void generateRpm();
    void generateSpeed();
    void generateFuel();
private:
    QTimer m_timer;
    int m_speed;
    int m_rpm;
    bool m_increase;
    qreal m_fuel;
};

class HObject : public QObject {
    Q_OBJECT
    void event(QEvent event) {
        if(event.type == HRoundEvent)
            RoundEvent(event);
    }
    virtual void RoundEvent(QEvent event);
};

class RoundButtonHandler : public HObject {
    virtual void RoundEvent(QEvent event) {

    }

}
#endif // RPMENGINE_H
