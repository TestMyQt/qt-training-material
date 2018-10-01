#include <QtGui>
#include "ellipseitem.h"

EllipseItem::EllipseItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

EllipseItem::~EllipseItem()
{
}

void EllipseItem::paint(QPainter *painter)
{
    const qreal halfPenWidth = qMax(painter->pen().width() / 2.0, 1.0);

    QRectF rect = boundingRect();
    rect.adjust(halfPenWidth, halfPenWidth, -halfPenWidth, -halfPenWidth);

    painter->drawEllipse(rect);
}
