#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QDebug>
#include <QMovie>
#include <QMessageBox>
namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = 0);
    ~about();


private:
    Ui::about *ui;
    QMovie *movie;
private slots:
    void startMoive();
    void stopMoive();
};

#endif // ABOUT_H
