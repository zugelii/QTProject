#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QDebug>
#include <QMessageBox>

#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>


#include <QFont>
#include <QFontDialog>
#include <QColorDialog>
#include <QColor>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QTextCodec>


#include "about.h"


#include <QSound>
#include <QCloseEvent>
//当程序需要关闭的时候，所处理的内容
//所有的时间都是受保护的成员函数
//protected
//QWidget closeEvent() QMainWindow  closeEvent();

#include <QPixmap>
#include <QSplashScreen>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *);
private:
    Ui::MainWindow *ui;
    QString saveFileName;
private slots:
    void newFileSlot();
    void openFileSlot();
    void saveFileSlot();
    void saveAsFileSlot();
    void printFileSlot();
    void setFontSlot();
    void setColorSlot();
    void setDateTimeLocalSlot();
    void aboutWebsiteSlot();
    void aboutSofewareSlot();
};

#endif // MAINWINDOW_H
