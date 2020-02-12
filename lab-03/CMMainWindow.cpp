#include "CMMainWindow.h"
#include "ui_CMMainWindow.h"
#include <QMessageBox>

CMMainWindow::CMMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMMainWindow)
{
    ui->setupUi(this);

    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(aboutSlot()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

CMMainWindow::~CMMainWindow()
{
    delete ui;
}

void CMMainWindow::aboutSlot()
{
    QString title, message;

    title = QString("About ") + windowTitle();
    message = QString("Author: Christopher McCooey");
    message += QString("Description: This program is used to display a circular linked list of the Mancara game.");
    QMessageBox::about(this, title, message);
}
