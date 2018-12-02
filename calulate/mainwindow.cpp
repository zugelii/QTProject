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
    int res = 0;
    //QString str;
    //str.setNum(res);
    //ui->reultText->setText(str);
    switch((int)ui->comboBox->currentIndex())
    {
    case 0:  //+
        res = ft + sec;
        break;
    case 1: //-
        res = ft - sec;
        break;
    case 2: //*
        res = ft * sec;
        break;
    case 3: ///
        if(sec == 0)
        {
            QMessageBox::warning(this,"error input","second cannot be zero");
            break;
        }
        res = ft / sec;
        break;
    default:
        break;
    }
    ui->reultText->setText(QString::number(res));

}















