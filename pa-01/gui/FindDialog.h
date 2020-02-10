#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

    void getFindInformation(bool* find_first, int* find_value);

private:
    Ui::FindDialog *ui;
};

#endif // FINDDIALOG_H
