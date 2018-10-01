#ifndef RECEIVER_H
#define RECEIVER_H

#include <QTextEdit>

class Receiver : public QTextEdit
{
    Q_OBJECT
public:
    explicit Receiver(QWidget *parent = 0);
    
public Q_SLOTS:
    void data(int i);
};

#endif // RECEIVER_H
