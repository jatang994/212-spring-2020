/**
 * @file CM_MainWindow.h
 * @author Christopher McCooey
 * @date February 12, 2020
 * @brief This class is the main window of the user interface. Do not change this file.
 */

#ifndef CM_MAINWINDOW_H
#define CM_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class CM_MainWindow;
}

class CM_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CM_MainWindow(QWidget *parent = nullptr);
    ~CM_MainWindow();

protected:
    void keyReleaseEvent(QKeyEvent* ev);

private slots:
    void findFirstSlot();
    void findLastSlot();
    void helpSlot();

private:
    Ui::CM_MainWindow *ui;
};

#endif // CM_MAINWINDOW_H
