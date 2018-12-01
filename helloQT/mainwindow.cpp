#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumWidth(541);
    this->setMaximumHeight(260);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QProcess *myProcess = new QProcess;
    QString startProgram = ui->lineEdit->text();
    myProcess->start(startProgram.trimmed());
    ui->lineEdit->clear();
    this->close();

}
