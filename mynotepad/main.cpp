#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    MainWindow w;
    QPixmap pixmap("screen.png");
    QSplashScreen splash(pixmap);
    splash.show();
    for(long index = 0; index < 1000000000;index ++);
    splash.finish(&w);

    w.show();
    splash.finish(&w);
    return a.exec();
}
