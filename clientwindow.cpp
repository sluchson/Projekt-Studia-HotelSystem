#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "database.h"
#include "addclient.h"

extern Database db;

clientwindow::clientwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::clientwindow)
{
    ui->setupUi(this);
    ui->tableViewClients->setModel(db.getClientsModel());
}

clientwindow::~clientwindow()
{
    delete ui;
}

void clientwindow::on_pushButtonAddClient_clicked()
{

    addclient *addClientWin = new addclient(this);
    addClientWin->show();
}

