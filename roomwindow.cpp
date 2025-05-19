#include "roomwindow.h"
#include "ui_roomwindow.h"
#include "database.h"

extern Database db;

roomwindow::roomwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::roomwindow)
{
    ui->setupUi(this);
    ui->tableViewRooms->setModel(db.getRoomsModel());
}

roomwindow::~roomwindow()
{
    delete ui;
}
