#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Untitled notepad  ----leo create");
    QObject::connect(ui->newAction, SIGNAL(triggered()), this, SLOT(newFileSlot()));
    QObject::connect(ui->openAction, SIGNAL(triggered()), this, SLOT(openFileSlot()));
    QObject::connect(ui->saveAction, SIGNAL(triggered()), this, SLOT(saveFileSlot()));
    QObject::connect(ui->saveAsAction, SIGNAL(triggered()), this, SLOT(saveAsFileSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFileSlot()
{
    if(ui->textEdit->document()->isModified())
    {
        qDebug()<<"current file modified";
    }
    else
    {
        qDebug()<<"not modified";
        ui->textEdit->clear();
        this->setWindowTitle("Untitled.txt  ----leo create");
    }
}

void MainWindow::openFileSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, "open file", QDir::currentPath());
    qDebug() << "open file name:" << fileName;
    if(fileName.isEmpty())
    {
        QMessageBox::information(this, "Error Message", "please select a text file");
        return;
    }
    QFile *file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream in(file);
        ui->textEdit->setText(in.readAll()); //read all data from in
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this, "Error message", file->errorString());
        return;
    }
}

void MainWindow::saveFileSlot()
{
    if(saveFileName.isEmpty())
    {
        this->saveAsFileSlot();
    }
    else
    {
        QFile *file = new QFile;
        file->setFileName(saveFileName);
        bool ok = file->open(QIODevice::WriteOnly);
        if(ok)
        {
            QTextStream out(file);
            out << ui->textEdit->toPlainText();
            this->setWindowTitle(saveFileName + "------notepad");
            file->close();
            delete file;
        }
        else
        {
            QMessageBox::information(this, "Error message", "open file error");
            return;
        }
    }
}
void MainWindow::saveAsFileSlot()
{
    saveFileName = QFileDialog::getSaveFileName(this, "save file", QDir::currentPath());
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(this, "Error Message", "please input filename");
        return;
    }
    QFile *file = new QFile;
    file->setFileName(saveFileName);
    bool ok = file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out << ui->textEdit->toPlainText();
        this->setWindowTitle(saveFileName + "------notepad");
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this, "Error message", "open file error");
        return;
    }
}

void MainWindow::printFileSlot()
{
    //QPrintDialog
}