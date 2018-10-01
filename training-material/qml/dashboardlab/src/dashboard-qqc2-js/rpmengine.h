#ifndef RPMENGINE_H
#define RPMENGINE_H

#include <QObject>
#include <QTimer>
#include <QThread>

class RpmEngine : public QThread
{
    Q_OBJECT
public:
    explicit RpmEngine(QObject *parent = nullptr);
    ~RpmEngine();
    void run() override;
signals:
    void rpmReady(int rpm);
    void speedReady(int speed);
public slots:
    void generateRpm();
    void generateSpeed();
private:
    int m_speed;
    int m_rpm;
    bool m_increase;
};

#endif // RPMENGINE_H
