#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Untitled notepad  ----leo create");
    //file  slot
    QObject::connect(ui->newAction, SIGNAL(triggered()), this, SLOT(newFileSlot()));
    QObject::connect(ui->openAction, SIGNAL(triggered()), this, SLOT(openFileSlot()));
    QObject::connect(ui->saveAction, SIGNAL(triggered()), this, SLOT(saveFileSlot()));
    QObject::connect(ui->saveAsAction, SIGNAL(triggered()), this, SLOT(saveAsFileSlot()));

    //edit slot
    QObject::connect(ui->redoAction, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    QObject::connect(ui->cutAction, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    QObject::connect(ui->copyAction, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    QObject::connect(ui->seleteAllAction, SIGNAL(triggered()), ui->textEdit, SLOT(selectAll()));
    QObject::connect(ui->colorAction, SIGNAL(triggered()), this, SLOT(setColorSlot()));
    QObject::connect(ui->fontAction, SIGNAL(triggered()), this, SLOT(setFontSlot()));
    QObject::connect(ui->dateAction, SIGNAL(triggered()), this, SLOT(setDateTimeLocalSlot()));

    //help slot
    QObject::connect(ui->aboutQTAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    QObject::connect(ui->webAction, SIGNAL(triggered()), this, SLOT(aboutWebsiteSlot()));
    QObject::connect(ui->aboutSoftwareAction, SIGNAL(triggered()), this, SLOT(aboutSofewareSlot()));

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

void MainWindow::setFontSlot()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok)
    {
        ui->textEdit->setFont(font);
    } else
    {
        QMessageBox::information(this, "Error message", "Error set font!");
    }
}

void MainWindow::setColorSlot()
{
    QColor color;
    color = QColorDialog::getColor(Qt::green, this);

    if (color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else
    {
        QMessageBox::information(this, "Error message", "Error set color");
    }
}

void MainWindow::setDateTimeLocalSlot()
{
    QDateTime current = QDateTime::currentDateTime();
    QString time = current.toString("yyyy-M-dd hh:mm:ss");
    ui->textEdit->append(time);
}


void MainWindow::aboutWebsiteSlot()
{
    QDesktopServices::openUrl(QUrl("http://google.com"));

}

void MainWindow::aboutSofewareSlot()
{
    about *dialog = new about;
    //dialog->show();  //非模态对话框
    dialog->exec(); //模态对话框

}


void MainWindow::closeEvent(QCloseEvent *event)
{
//    event->ignore();
 //   qDebug() <<"close event";
    if(ui->textEdit->document()->isModified())
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
          case QMessageBox::Save:
              // Save was clicked
                this->saveFileSlot();
              break;
          case QMessageBox::Discard:
              // Don't Save was clicked
                event->accept();
              break;
          case QMessageBox::Cancel:
              // Cancel was clicked
                event->ignore();
              break;
          default:
              // should never be reached
              break;
        }
    }
    else
    {
        event->accept();
        qDebug()<< "没有改变";
    }
}











