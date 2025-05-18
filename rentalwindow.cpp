#include "rentalwindow.h"
#include "ui_rentalwindow.h"

rentalwindow::rentalwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::rentalwindow)
{
    ui->setupUi(this);
}

rentalwindow::~rentalwindow()
{
    delete ui;
}
