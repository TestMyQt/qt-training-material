#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>

#include "sender.h"
#include "receiver.h"

int main( int argc, char** argv )
{
    QApplication app(argc,argv);

    Sender* sender = new Sender;
    Receiver* receiver = new Receiver;

    QWidget* box = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout(box);
    layout->addWidget(sender);
    layout->addWidget(receiver);
#if QT_VERSION < 0x050000
    QObject::connect(sender, SIGNAL(data(int)), receiver, SLOT(data(int)));
#else
    QObject::connect(sender, &Sender::data, receiver, &Receiver::data);
#endif

    box->show();
    return app.exec();
}
