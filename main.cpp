#include "mainwindow.h"
#include "database.h"
#include <QApplication>

// globalny obiekt bazy danych
Database db;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // otwieramy polaczenie z baza przy starcie programu
    db.openConnection();

    MainWindow w;
    w.show();

    return a.exec();
}
