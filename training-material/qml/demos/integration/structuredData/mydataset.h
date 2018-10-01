#ifndef MYDATASET_H
#define MYDATASET_H

#include <QtCore/QObject>
#include <QtGui/QColor>

class MyDataSet : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor myBackgroundColor MEMBER mColor
               NOTIFY myBackgroundColorChanged)
    Q_PROPERTY(QString myText MEMBER mText
               WRITE setText NOTIFY myTextChanged)
public:
    explicit MyDataSet(QObject *parent = 0);

protected:
    void timerEvent(QTimerEvent *);

Q_SIGNALS:
    void myBackgroundColorChanged();
    void myTextChanged();

private:
    QColor mColor;
    QString mText;
};

#endif // MYDATASET_H
