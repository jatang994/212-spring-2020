#include "PA1MainWindow.h"
#include "ui_PA1MainWindow.h"
#include "FindDialog.h"
#include <QString>
#include <QMessageBox>

PA1MainWindow::PA1MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PA1MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(aboutSlot()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));

    connect(ui->pushButton_append, SIGNAL(clicked()), ui->widget_chrisView, SLOT(requestAppend()));
    connect(ui->pushButton_prepend, SIGNAL(clicked()), ui->widget_chrisView, SLOT(requestPrepend()));
    connect(ui->pushButton_removeFirst, SIGNAL(clicked()), ui->widget_chrisView, SLOT(requestRemoveFirst()));
    connect(ui->pushButton_removeLast, SIGNAL(clicked()), ui->widget_chrisView, SLOT(requestRemoveLast()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), ui->widget_chrisView, SLOT(requestClear()));
    connect(ui->pushButton_find, SIGNAL(clicked()), this, SLOT(findSlot()));
    connect(ui->doubleSpinBox_sf, SIGNAL(valueChanged(double)), ui->widget_chrisView, SLOT(scaleFactorChanged(double)));
    connect(ui->checkBox_showIndex, SIGNAL(stateChanged(int)), ui->widget_chrisView, SLOT(showIndexValue(int)));
}

PA1MainWindow::~PA1MainWindow()
{
    delete ui;
}

void PA1MainWindow::aboutSlot()
{
    QString title, message;
    title = QString("About ") + windowTitle();
    message = QString("Author: Christopher McCooey\n");
    message.append("Build Date: ");
    message.append(__DATE__);
    message.append("\nDescription: This program is used to display dynamic arrays and to test the DynamicArray class.");
    QMessageBox::about(this, title, message);
}

void PA1MainWindow::findSlot()
{
    bool find_first = false, found = false;
    int search_value = 0;
    unsigned int index = 0u;
    QString title, message;
    FindDialog* fd = new FindDialog(this);

    fd->exec();
    fd->getFindInformation(&find_first, &search_value);
    delete fd;

    index = ui->widget_chrisView->findValue(find_first, search_value, &found);
    if (found)
    {
        title = QString("Found value");
        message = QString("Found value ");
        message.append(QString::number(search_value));
        message.append(" at index ");
        message.append(QString::number(index));
        message.append(".");
    }
    else
    {
        title = QString("Value not found");
        message = QString("The value ");
        message.append(QString::number(search_value));
        message.append(" was not found in the array.");
    }
    QMessageBox::information(this, title, message, QMessageBox::Ok);
}

