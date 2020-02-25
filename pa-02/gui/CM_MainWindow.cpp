/**
 * @file CM_MainWindow.cpp
 * @author Christopher McCooey
 * @date February 12, 2020
 * @brief This class is the main window of the user interface. Do not change this file.
 */

#include "CM_MainWindow.h"
#include "ui_CM_MainWindow.h"
#include <QKeyEvent>
#include <QMessageBox>

CM_MainWindow::CM_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CM_MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionClear_List, SIGNAL(triggered()), ui->widget_gv, SLOT(clearSlot()));
    connect(ui->actionFind_First_Of, SIGNAL(triggered()), this, SLOT(findFirstSlot()));
    connect(ui->actionFind_Last_Of, SIGNAL(triggered()), this, SLOT(findLastSlot()));
    connect(ui->actionConstruct_Random_String, SIGNAL(triggered()), ui->widget_gv, SLOT(randomStringSlot()));
    connect(ui->actionHow_to_use_this_GUI, SIGNAL(triggered()), this, SLOT(helpSlot()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

CM_MainWindow::~CM_MainWindow()
{
    delete ui;
}

void CM_MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    //propagate keyboard event down to the graphics view widget
    ui->widget_gv->keyFunction(ev);
}

//slots
void CM_MainWindow::findFirstSlot()
{
    ui->widget_gv->setMode(Mode_Find_First);
}
void CM_MainWindow::findLastSlot()
{
    ui->widget_gv->setMode(Mode_Find_Last);
}
void CM_MainWindow::helpSlot()
{
    QString title, text;

    title = QString("How to use this GUI");
    text = QString("Controls:\n");
    text.append("  1. Type characters on the keyboard to add characters to your linked list.\n");
    text.append("  2. Use backspace key to remove the previous character");
    text.append("  2. Use delete key to delete the next character");
    text.append("  3. The arrow keys change where you are typing in the string. If you are in the middle of the string it will test the insert functions. The helper text underneath the string indicates what append/prepend/insert function will be tested when typing a key.");
    text.append("  4. Use the tools menu to clear the string, find a character, or use the string constructor.");
    QMessageBox::information(this, title, text);
}
