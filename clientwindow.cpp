#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "database.h"
#include "addclient.h"
#include "deleteclient.h"
#include <QMessageBox>
#include <QSqlQuery>

extern Database db;

clientwindow::clientwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::clientwindow)
{
    ui->setupUi(this);
    ui->tableViewClients->setModel(db.getClientsModel());

    connect(ui->tableViewClients, &QTableView::clicked, this, &clientwindow::handleClientRowClick);
    ui->tableViewClients->setEditTriggers(QAbstractItemView::NoEditTriggers);

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


void clientwindow::on_pushButtonDeleteClient_clicked()
{
    deleteclient *deleteClientWin = new deleteclient(this);
    deleteClientWin->show();
}


void clientwindow::displayClientDetails(QWidget *parent, const QString& clientId)
{
    QString clientInfo = db.searchRecord("clients", "client_id", clientId);

    QString rentalInfo;
    QSqlQuery query;
    query.prepare("SELECT rental_id, room_number, check_in_date, check_out_date FROM rentals WHERE client_id = :client_id");
    query.bindValue(":client_id", clientId);

    if (query.exec()) {
        while (query.next()) {
            rentalInfo += "— Wypożyczenie #" + query.value("rental_id").toString() +
                          ", pokój: " + query.value("room_number").toString() +
                          ", od: " + query.value("check_in_date").toString() +
                          ", do: " + query.value("check_out_date").toString() + "\n";
        }
    }

    QString fullInfo = clientInfo;

    if (!rentalInfo.isEmpty()) {
        fullInfo += "\n\nWypożyczenia klienta:\n" + rentalInfo.trimmed();
    } else if (!clientInfo.contains("Nie znaleziono")) {
        fullInfo += "\n\nKlient nie posiada wypożyczeń.";
    }

    QMessageBox::information(parent, "Wynik wyszukiwania", fullInfo);
}


void clientwindow::on_pushButton_searchClient_clicked()
{
    QString clientId = ui->lineEdit_searchClientId->text().trimmed();
    if (clientId.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wprowadź ID klienta do wyszukania.");
        return;
    }

    clientwindow::displayClientDetails(this, clientId);
}


void clientwindow::handleClientRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString clientId = ui->tableViewClients->model()->data(ui->tableViewClients->model()->index(index.row(), 0)).toString();
    clientwindow::displayClientDetails(this, clientId);
}

void clientwindow::on_pushButtonRefresh_clicked()
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewClients->model());
    db.refreshExistingModel(model);
}

