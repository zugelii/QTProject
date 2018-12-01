#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->changeTileButton,SIGNAL(clicked()),this,SLOT(changeTitleSlot()));
   // QObject::connect(ui->closeButton,SIGNAL(clicked()),qApp,SLOT(quit()));
    QObject::connect(this, SIGNAL(custSignal(QString)), this, SLOT(setMainWindowTitle(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeTitleSlot()
{
   this->setWindowTitle("hello i am bill gates");
}

void MainWindow::setMainWindowTitle(QString context)
{
    this->setWindowTitle(context);
}


void MainWindow::on_custButtion_clicked()
{
    emit this->custSignal("hello argv");

}
