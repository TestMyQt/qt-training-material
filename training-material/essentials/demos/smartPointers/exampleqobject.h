#ifndef EXAMPLEQOBJECT_H
#define EXAMPLEQOBJECT_H

#include <QObject>

class ExampleQObject : public QObject
{
    Q_OBJECT
public:
    explicit ExampleQObject(QObject *parent = 0);

signals:

public slots:
};

#endif // EXAMPLEQOBJECT_H
