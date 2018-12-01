#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//custom slot
private slots:
   void changeTitleSlot(void);
  // void on_changeTileButton_clicked();

   void on_custButtion_clicked();
   void setMainWindowTitle(QString);
signals:
   void custSignal(QString);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
