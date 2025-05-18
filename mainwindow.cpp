#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "clientwindow.h"
#include "rentalwindow.h"
#include "roomwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (!db.openConnection()) {
        QMessageBox::critical(this, "Błąd połączenia", "Nie można połączyć z bazą danych.");
    }

}

MainWindow::~MainWindow()
{
    db.closeConnection();
    delete ui;
}

void MainWindow::on_ClientsButton_clicked()
{
    clientwindow *clientWin = new clientwindow(this);
    clientWin->show();
}


void MainWindow::on_RentalsButton_clicked()
{
    rentalwindow *rentalWin = new rentalwindow(this);
    rentalWin->show();
}


void MainWindow::on_RoomsButton_clicked()
{
    roomwindow *roomWin = new roomwindow(this);
    roomWin->show();
}

