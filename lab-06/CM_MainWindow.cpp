#include "CM_MainWindow.h"
#include "ui_CM_MainWindow.h"

CM_MainWindow::CM_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CM_MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->spinBox_steps, SIGNAL(valueChanged(int)), ui->fractal_view, SLOT(setNumberOfSteps(int)));
}

CM_MainWindow::~CM_MainWindow()
{
    delete ui;
}
