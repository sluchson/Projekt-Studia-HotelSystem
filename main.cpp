#include "mainwindow.h"
#include "database.h"
#include <QApplication>

Database db;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    db.openConnection();
    MainWindow w;
    w.show();
    return a.exec();
}
