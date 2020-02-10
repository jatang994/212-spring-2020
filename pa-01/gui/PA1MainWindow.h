/*
 * Author: Christopher McCooey
 * Date Created: January 29, 2020
 * Description: This is the Qt main window of the application. There is no reason to change this code.
 */

#ifndef PA1MAINWINDOW_H
#define PA1MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class PA1MainWindow;
}

class PA1MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PA1MainWindow(QWidget *parent = nullptr);
    ~PA1MainWindow();

private slots:
    void aboutSlot();
    void findSlot();

private:
    Ui::PA1MainWindow *ui;
};

#endif // PA1MAINWINDOW_H
