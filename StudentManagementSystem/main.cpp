#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include <QFontDatabase>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
