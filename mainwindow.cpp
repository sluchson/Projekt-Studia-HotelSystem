#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "clientwindow.h"
#include "rentalwindow.h"
#include "roomwindow.h"

// konstruktor glownego okna aplikacji
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this); // inicjalizacja ui
}

// destruktor
MainWindow::~MainWindow()
{
    delete ui;
}

// otwiera okno zarzadzania klientami
void MainWindow::on_ClientsButton_clicked()
{
    clientwindow *clientWin = new clientwindow(this);
    clientWin->show();
}

// otwiera okno zarzadzania wypozyczeniami
void MainWindow::on_RentalsButton_clicked()
{
    rentalwindow *rentalWin = new rentalwindow(this);
    rentalWin->show();
}

// otwiera okno zarzadzania pokojami
void MainWindow::on_RoomsButton_clicked()
{
    roomwindow *roomWin = new roomwindow(this);
    roomWin->show();
}
