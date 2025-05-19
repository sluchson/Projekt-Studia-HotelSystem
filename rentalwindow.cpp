#include "rentalwindow.h"
#include "ui_rentalwindow.h"
#include "database.h"

extern Database db;


rentalwindow::rentalwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::rentalwindow)
{
    ui->setupUi(this);
    ui->tableViewRentals->setModel(db.getRentalsModel());
}

rentalwindow::~rentalwindow()
{
    delete ui;
}
