#include "CMMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMMainWindow w;
    w.show();

    return a.exec();
}
