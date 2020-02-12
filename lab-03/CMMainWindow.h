#ifndef CMMAINWINDOW_H
#define CMMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class CMMainWindow;
}

class CMMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMMainWindow(QWidget *parent = 0);
    ~CMMainWindow();

private slots:
    void aboutSlot();

private:
    Ui::CMMainWindow *ui;
};

#endif // CMMAINWINDOW_H
