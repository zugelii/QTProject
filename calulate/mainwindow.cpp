#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_caltButtion_clicked()
{
    QString first = ui->firstText->text().trimmed();
    QString second = ui->secondText->text().trimmed();
    bool ok;
    int ft = first.toInt(&ok, 10);
    int sec = second.toInt(&ok, 10);
    int res = ft + sec;
    //QString str;
    //str.setNum(res);
    //ui->reultText->setText(str);
    ui->reultText->setText(QString::number(res));

}
