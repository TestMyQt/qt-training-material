#include <QtCore/QStateMachine>
#include <QtCore/QPropertyAnimation>
#include <QtCore/QParallelAnimationGroup>
#include <QtCore/QSignalTransition>
#include <QGraphicsEffect>

#include "mygesturerecognizer.h"
#include "slideshowdialog.h"
#include "ui_slideshowdialog.h"

SlideShowDialog::SlideShowDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::SlideShowDialog),
    m_imageWidth(140), m_imageHeight(140)
{
    ui->setupUi(this);
    setWindowTitle("Slide Show!");

    // Create the custom gesture recognizer and subscribe to custom
    // gestures.
    MyGestureRecognizer* recognizer = new MyGestureRecognizer();
    m_gestureType = QGestureRecognizer::registerRecognizer(recognizer);
    grabGesture(m_gestureType);

    // Initialize the graphics view/scene contents.
    initGraphicsView();

    // Initialize the state machine for animations.
    initStateMachine();
}

SlideShowDialog::~SlideShowDialog()
{
    delete ui;
}

void SlideShowDialog::initGraphicsView()
{
    // Create a graphics scene of size 360x360, make this
    // dialog the parent of the scene.
    int sceneWidth = 360;
    int sceneHeight = 360;
    QGraphicsScene* scene = new QGraphicsScene(0, 0, sceneWidth, sceneHeight, this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    scene->setBackgroundBrush(QBrush(Qt::yellow));

    // Path to each image to be added to the scene.
    QStringList imageFiles;
    imageFiles.append(":/images/gif_with_alpha/skinny_louie_bruno.gif");
    imageFiles.append(":/images/gif_with_alpha/leo_rubbernubs.gif");
    imageFiles.append(":/images/gif_with_alpha/vito_gallo.gif");
    imageFiles.append(":/images/gif_with_alpha/stefano_the_gun.gif");

    // Initialize image positions on the graphics scene.
    // Bottom:
    m_imagePositions.append(QPointF((sceneWidth - m_imageWidth)/2, (sceneHeight-m_imageHeight)));
    // Left:
    m_imagePositions.append(QPointF(0, (sceneHeight - m_imageHeight)/2));
    // Top:
    m_imagePositions.append(QPointF((sceneWidth - m_imageWidth)/2, 0));
    // Right:
    m_imagePositions.append(QPointF((sceneWidth-m_imageWidth), (sceneHeight - m_imageHeight)/2));

    // Load the images from the resource file into a list (m_images)
    // and put them onto the scene.
    MyPixmapItem* item;
    for (int i = 0; i < imageFiles.length(); i++)
    {
        // Scale all the images to be the same size.
        item = new MyPixmapItem(QPixmap(imageFiles[i]).scaled(m_imageWidth, m_imageHeight));
        m_images.append(item);

        // Initial position, state machine takes over once initialized.
        item->setPos(m_imagePositions[i]);

        // Add item to the scene
        ui->graphicsView->scene()->addItem(item);
    }
}

bool SlideShowDialog::event(QEvent *event)
{
    // 3.
    if (event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent*>(event));
    return QWidget::event(event);
}

bool SlideShowDialog::gestureEvent(QGestureEvent* event)
{
    MyGesture* g = static_cast<MyGesture*>(event->gesture(m_gestureType));
    if (g->state() != Qt::GestureFinished)
        return true;

    if (g && (g->gestureDirection() == MyGesture::Right))
    {
        emit scrollRight();
    } else if (g && (g->gestureDirection() == MyGesture::Left))
    {
        emit scrollLeft();
    }
    return true;
}

void SlideShowDialog::keyPressEvent(QKeyEvent* event)
{
    // 2.
    int key = event->key();
    switch(key)
    {
        case Qt::Key_Left:
            emit scrollLeft();
            break;
        case Qt::Key_Right:
            emit scrollRight();
            break;
        default:
            break;
    }
    return QDialog::keyPressEvent(event);
}

void SlideShowDialog::initStateMachine()
{
    QStateMachine* machine = new QStateMachine(this);
    QState* s1 = new QState();  // First image on the bottom
    QState* s2 = new QState();  // Second image on the bottom
    QState* s3 = new QState();  // Third image on the bottom
    QState* s4 = new QState();  // Fourth image on the bottom

    // Create an animation group to be run each time the state
    // changes (each image's position, scaling and blur will be animated).
    int animationDuration = 1000;
    QParallelAnimationGroup* group = new QParallelAnimationGroup(this);
    for (int i = 0; i < m_images.count(); ++i) {
        QPropertyAnimation* anim = new QPropertyAnimation(m_images[i], "pos");
        anim->setDuration(animationDuration);
        anim->setEasingCurve(QEasingCurve::OutBounce);
        group->addAnimation(anim);
        
        QPropertyAnimation* anim2 = new QPropertyAnimation(m_images[i], "scaleFactor");
        anim2->setDuration(animationDuration);
        anim2->setEasingCurve(QEasingCurve::OutBounce);
        group->addAnimation(anim2);
        
        QPropertyAnimation* anim3 = new QPropertyAnimation(m_images[i]->graphicsEffect(), "blurRadius");
        anim3->setDuration(animationDuration);
        anim3->setEasingCurve(QEasingCurve::OutBounce);
        group->addAnimation(anim3);  
    }

    // Use the same animation for all transitions
    machine->addDefaultAnimation(group);

    // From state 1 we can go to state 2...
    s1->addTransition(this, SIGNAL(scrollRight()), s2);
    // ...or state 4
    s1->addTransition(this, SIGNAL(scrollLeft()), s4);

    // From state 2 we can go to state 3...
    s2->addTransition(this, SIGNAL(scrollRight()), s3);
    // ...or state 1
    s2->addTransition(this, SIGNAL(scrollLeft()), s1);

    // From state 3 we can go to state 4...
    s3->addTransition(this, SIGNAL(scrollRight()), s4);
    // ...or state 2
    s3->addTransition(this, SIGNAL(scrollLeft()), s2);

    // From state 4 we can go to state 1...
    s4->addTransition(this, SIGNAL(scrollRight()), s1);
    // ...or state 3
    s4->addTransition(this, SIGNAL(scrollLeft()), s3);

    /* State 1, image at index 0 is on the bottom */
    s1->assignProperty(m_images[0], "pos", m_imagePositions[0]);
    s1->assignProperty(m_images[1], "pos", m_imagePositions[1]);
    s1->assignProperty(m_images[2], "pos", m_imagePositions[2]);
    s1->assignProperty(m_images[3], "pos", m_imagePositions[3]);

    s1->assignProperty(m_images[0], "scaleFactor", 1.0);
    s1->assignProperty(m_images[1], "scaleFactor", 0.8);
    s1->assignProperty(m_images[2], "scaleFactor", 0.6);
    s1->assignProperty(m_images[3], "scaleFactor", 0.8);

    s1->assignProperty(m_images[0]->graphicsEffect(), "blurRadius", 0.0);
    s1->assignProperty(m_images[1]->graphicsEffect(), "blurRadius", 2.0);
    s1->assignProperty(m_images[2]->graphicsEffect(), "blurRadius", 5.0);
    s1->assignProperty(m_images[3]->graphicsEffect(), "blurRadius", 2.0);
    
    /* State 2, image at index 1 is on the bottom */
    s2->assignProperty(m_images[1], "pos", m_imagePositions[0]);
    s2->assignProperty(m_images[2], "pos", m_imagePositions[1]);
    s2->assignProperty(m_images[3], "pos", m_imagePositions[2]);
    s2->assignProperty(m_images[0], "pos", m_imagePositions[3]);

    s2->assignProperty(m_images[1], "scaleFactor", 1.0);
    s2->assignProperty(m_images[2], "scaleFactor", 0.8);
    s2->assignProperty(m_images[3], "scaleFactor", 0.6);
    s2->assignProperty(m_images[0], "scaleFactor", 0.8);

    s2->assignProperty(m_images[1]->graphicsEffect(), "blurRadius", 0.0);
    s2->assignProperty(m_images[2]->graphicsEffect(), "blurRadius", 2.0);
    s2->assignProperty(m_images[3]->graphicsEffect(), "blurRadius", 5.0);
    s2->assignProperty(m_images[0]->graphicsEffect(), "blurRadius", 2.0);
    
    /* State 3, image at index 2 is on the bottom */
    s3->assignProperty(m_images[2], "pos", m_imagePositions[0]);
    s3->assignProperty(m_images[3], "pos", m_imagePositions[1]);
    s3->assignProperty(m_images[0], "pos", m_imagePositions[2]);
    s3->assignProperty(m_images[1], "pos", m_imagePositions[3]);

    s3->assignProperty(m_images[2], "scaleFactor", 1.0);
    s3->assignProperty(m_images[3], "scaleFactor", 0.8);
    s3->assignProperty(m_images[0], "scaleFactor", 0.6);
    s3->assignProperty(m_images[1], "scaleFactor", 0.8);

    s3->assignProperty(m_images[2]->graphicsEffect(), "blurRadius", 0.0);
    s3->assignProperty(m_images[3]->graphicsEffect(), "blurRadius", 2.0);
    s3->assignProperty(m_images[0]->graphicsEffect(), "blurRadius", 5.0);
    s3->assignProperty(m_images[1]->graphicsEffect(), "blurRadius", 2.0);
    
    /* State 4, image at index 3 is on the bottom */
    s4->assignProperty(m_images[3], "pos", m_imagePositions[0]);
    s4->assignProperty(m_images[0], "pos", m_imagePositions[1]);
    s4->assignProperty(m_images[1], "pos", m_imagePositions[2]);
    s4->assignProperty(m_images[2], "pos", m_imagePositions[3]);

    s4->assignProperty(m_images[3], "scaleFactor", 1.0);
    s4->assignProperty(m_images[0], "scaleFactor", 0.8);
    s4->assignProperty(m_images[1], "scaleFactor", 0.6);
    s4->assignProperty(m_images[2], "scaleFactor", 0.8);

    s4->assignProperty(m_images[3]->graphicsEffect(), "blurRadius", 0.0);
    s4->assignProperty(m_images[0]->graphicsEffect(), "blurRadius", 2.0);
    s4->assignProperty(m_images[1]->graphicsEffect(), "blurRadius", 5.0);
    s4->assignProperty(m_images[2]->graphicsEffect(), "blurRadius", 2.0);
    
    machine->addState(s1);
    machine->addState(s2);
    machine->addState(s3);
    machine->addState(s4);
    machine->setInitialState(s1);
    machine->start();
}
