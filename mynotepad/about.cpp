#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->movie = new QMovie("laoban.gif");
    ui->moiveLabel->setMovie(this->movie);
    this->movie->start();
    qDebug()<<"current movies has "<< this->movie->frameCount();

    QMessageBox::information(this, "move frame", "move frame count:" + QString::number(this->movie->frameCount(), 10));
    QObject::connect(ui->openButton_2, SIGNAL(clicked()), this, SLOT(startMoive()));
    QObject::connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(stopMoive()));
}

about::~about()
{
    delete ui;
}

void about::startMoive()
{
    this->movie->start();
}

void about::stopMoive()
{
    this->movie->stop();
}
