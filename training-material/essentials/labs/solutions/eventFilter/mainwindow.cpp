#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include <QMouseEvent>
#include <QDebug>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      lcdNumber(0)
{
    resize(440, 200);

    // Add a few widgets to hard-coded positions on the window
    QPushButton* button = new QPushButton("I'm a QPushButton!", this);
    button->setGeometry(30, 30, 120, 30);

    QLabel* label = new QLabel("I'm a QLabel!", this);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(180, 30, 100, 30);

    lcdNumber = new QLCDNumber(this);
    lcdNumber->display(50);
    lcdNumber->setGeometry(310, 30, 100, 30);

    // When a button is clicked, we want to know about it
#if QT_VERSION < 0x050000
    connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
#else
    connect(button, &QPushButton::clicked, this, &MainWindow::buttonClicked);
#endif

    // Install the event filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    // Nothing to do here
}

bool MainWindow::eventFilter(QObject *receiver, QEvent *event)
{
    // 3.a.
    if (event->type() == QEvent::MouseButtonPress)
    {
        // 3.b.
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        // 3.c.
        if (mouseEvent->button() == Qt::RightButton)
        {
            // 3.d. and 3.e.
            QWidget *targetWidget = qobject_cast<QWidget*>(receiver);

            if (targetWidget) {
                //qDebug() << targetWidget;
                QPoint pos(targetWidget->x() + 10, targetWidget->y());
                targetWidget->move(pos);
                // Important: return true to block the event from
                // propagating further!
                return true;
            }
            /*else {
                qDebug() << receiver;
                QWidget *widget = static_cast<QWidget *>(receiver);
                if (widget)
                    qDebug() << "x and y " << widget->x() << widget->y();
            }*/
        }
    }
    // Pass the event on to the parent class (will simply return
    // false in this case)
    return QObject::eventFilter(receiver, event);
}

void MainWindow::buttonClicked()
{
    QPushButton* button = static_cast<QPushButton*>(sender());
    QMessageBox::information(this, "Button clicked", button->text());
}



