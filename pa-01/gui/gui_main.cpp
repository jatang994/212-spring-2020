/*
 * Author: Christopher McCooey
 * Date Created: January 29, 2020
 * Description: This is the entry point of the Qt GUI application. Do not change this code.
 */

#include "PA1MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PA1MainWindow w;
    w.show();

    return a.exec();
}
