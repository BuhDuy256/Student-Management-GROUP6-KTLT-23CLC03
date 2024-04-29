#include "system.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    importData();

    MainWindow w;
    w.setWindowTitle("Student Management System");
    w.setWindowIcon(QIcon(":/background/Minecraft_thegame_6961.ico"));

    w.showMaximized();

    QObject::connect(&a, &QApplication::aboutToQuit, &saveData);

    return a.exec();
}
