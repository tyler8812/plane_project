#include "mainwindow.h"
#include <QApplication>

MainWindow * ww;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //ww = &w;

    return a.exec();
}
