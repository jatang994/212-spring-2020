#include "FindDialog.h"
#include "ui_FindDialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);

    ui->comboBox_findMode->addItem(QString("First Occurence"));
    ui->comboBox_findMode->addItem(QString("Last Occurence"));
    ui->comboBox_findMode->setCurrentIndex(0); //select the first option

    connect(ui->pushButton_find, SIGNAL(clicked()), this, SLOT(close()));
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::getFindInformation(bool *find_first, int *find_value)
{
    const int idx = ui->comboBox_findMode->currentIndex();

    *find_first = (idx == 0);
    *find_value = ui->spinBox_value->value();
}
