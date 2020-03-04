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

private:
    Ui::CM_MainWindow *ui;
};

#endif // CM_MAINWINDOW_H
