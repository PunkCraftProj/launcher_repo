#include "mainwindow.h"
#include "connection.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1000, 600);
    w.show();

    if (!connectToDataBase()) {
        return -1;
    }

    return a.exec();
}
