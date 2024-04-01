#include "system.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    importData();

    MainWindow w;
    w.show();

    return a.exec();
}
