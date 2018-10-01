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

void MainWindow::buttonClicked()
{
    QPushButton* button = static_cast<QPushButton*>(sender());
    QMessageBox::information(this, "Button clicked", button->text());
}



