#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include <QQuickPaintedItem>

class EllipseItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_DISABLE_COPY(EllipseItem)

public:
    EllipseItem(QQuickItem *parent = 0);
    ~EllipseItem();
    void paint(QPainter *painter);
};

#endif // ELLIPSEITEM_H
