#include "roomwindow.h"
#include "ui_roomwindow.h"

roomwindow::roomwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::roomwindow)
{
    ui->setupUi(this);
}

roomwindow::~roomwindow()
{
    delete ui;
}
