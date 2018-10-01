#ifndef RPMENGINE_H
#define RPMENGINE_H

#include <QObject>
#include <QTimer>
#include <QThread>

class RpmEngine : public QObject
{
    Q_OBJECT
public:
    explicit RpmEngine(QObject *parent = nullptr);
signals:
    void rpmReady(int rpm);
    void speedReady(int rpm);
public slots:
    void generateRpm();
    void generateSpeed();
    void generate();
private:
    QTimer* m_timer;
    int m_speed;
    int m_rpm;
    bool m_increase;
};

#endif // RPMENGINE_H
