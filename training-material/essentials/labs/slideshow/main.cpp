#include <QApplication>
#include "slideshowdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SlideShowDialog w;
    w.show();
    return a.exec();
}
