#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"  // Dodajemy zależność do klasy DatabaseManager

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ClientsButton_clicked();

    void on_RentalsButton_clicked();

    void on_RoomsButton_clicked();

private:
    Ui::MainWindow *ui;
    Database db;

};
#endif // MAINWINDOW_H
