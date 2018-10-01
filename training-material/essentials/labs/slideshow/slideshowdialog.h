#ifndef SLIDESHOWDIALOG_H
#define SLIDESHOWDIALOG_H

#include <QDialog>
#include <QtGui/QKeyEvent>
#include <QGestureEvent>

#include "mygesture.h"
#include "mypixmapitem.h"

namespace Ui
{
    class SlideShowDialog;
}

class SlideShowDialog : public QDialog
{
    Q_OBJECT

public:
    SlideShowDialog(QWidget *parent = 0);
    ~SlideShowDialog();

private:
    void initGraphicsView();
    void initStateMachine();

    bool event(QEvent* event);
    void keyPressEvent(QKeyEvent* event) override;
    bool gestureEvent(QGestureEvent* event);

signals:
    void scrollLeft();
    void scrollRight();

private:
    Ui::SlideShowDialog *ui;
    QList<MyPixmapItem*> m_images;

    // Image positions on the scene.
    QList<QPointF> m_imagePositions;

    // Each image is scaled to the same size when loaded from the resource file.
    const int m_imageWidth;
    const int m_imageHeight;

    // Store the custom gesture type ID.
    Qt::GestureType m_gestureType;
};

#endif // SLIDESHOWDIALOG_H
