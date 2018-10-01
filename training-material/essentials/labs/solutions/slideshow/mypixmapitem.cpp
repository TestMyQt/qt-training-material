#include <QGraphicsBlurEffect>
#include "mypixmapitem.h"

MyPixmapItem::MyPixmapItem(const QPixmap& pix, QObject *parent) :
    QObject(parent), QGraphicsPixmapItem(pix)
{
    setCacheMode(ItemCoordinateCache, pix.size());
    setTransformOriginPoint(boundingRect().center().x(), 0);

    QGraphicsBlurEffect* effect = new QGraphicsBlurEffect(this);
    effect->setBlurHints(QGraphicsBlurEffect::AnimationHint); // Prepare to be animated
    effect->setBlurRadius(0);  // No blurring by default
    setGraphicsEffect(effect);
}

MyPixmapItem::~MyPixmapItem()
{
    // Nothing to do here
}

/*
   This QGraphicsItem function is overridden and declared as private in this
   class - the purpose is to hide it so that no other effects than the
   built-in blur effect can be used. Notice that this is merely a design choice,
   nothing forces this function to be hidden!
*/
void MyPixmapItem::setGraphicsEffect(QGraphicsEffect *effect)
{
    QGraphicsItem::setGraphicsEffect(effect);
}
