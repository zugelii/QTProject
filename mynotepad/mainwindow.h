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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

};

#endif // MAINWINDOW_H
