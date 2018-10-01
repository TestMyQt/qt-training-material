#ifndef MYPIXMAPITEM_H
#define MYPIXMAPITEM_H

#include <QtCore/QObject>
#include <QGraphicsPixmapItem>

class MyPixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)  // Refers to QGraphicsPixmapItem members
    Q_PROPERTY(qreal scaleFactor READ scale WRITE setScale)  // Refers to QGraphicsPixmapItem members

public:
    MyPixmapItem(const QPixmap& pix, QObject* parent = 0);
    ~MyPixmapItem();

private:
    // This class only supports the built-in blur effect, prevent
    // other effects from being set by hiding this QGraphicsItem function.
    void setGraphicsEffect(QGraphicsEffect *effect);

};

#endif // MYPIXMAPITEM_H
