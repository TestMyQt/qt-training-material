#include <QApplication>
#include <QDebug>
#include "receiver.h"
#include "sender.h"
#include "data.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    Sender sender;

	sender.show();
    return application.exec();
}
