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
    setWindowTitle("Hotel System - Clients");
    ui->tableViewClients->setModel(db.getClientsModel());

    // klikniecie w wiersz tabeli pokazuje szczegoly klienta
    connect(ui->tableViewClients, &QTableView::clicked, this, &clientwindow::handleClientRowClick);
    // blokuje edycje w tabeli
    ui->tableViewClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // wlacza sortowanie po kolumnach
    ui->tableViewClients->setSortingEnabled(true);
}

clientwindow::~clientwindow()
{
    delete ui;
}

// obsluga przycisku dodawania klienta
void clientwindow::on_pushButtonAddClient_clicked()
{
    addclient *addClientWin = new addclient(this);
    // po dodaniu klienta odswiez tabele
    connect(addClientWin, &addclient::clientAdded, this, [this]() {
        static_cast<QSqlTableModel*>(ui->tableViewClients->model())->select();
    });
    addClientWin->show();
}

// obsluga przycisku usuwania klienta
void clientwindow::on_pushButtonDeleteClient_clicked()
{
    deleteclient *deleteClientWin = new deleteclient(this);
    // po usunieciu klienta odswiez tabele
    connect(deleteClientWin, &deleteclient::clientDeleted, this, [this]() {
        static_cast<QSqlTableModel*>(ui->tableViewClients->model())->select();
    });
    deleteClientWin->show();
}

// wyswietlanie szczegolow klienta i wypozyczen
void clientwindow::displayClientDetails(QWidget *parent, const QString& clientId)
{
    QString clientInfo = db.searchRecord("clients", "client_id", clientId);

    QString rentalInfo;
    QSqlQuery query;
    query.prepare("SELECT rental_id, room_number, check_in_date, check_out_date FROM rentals WHERE client_id = :client_id");
    query.bindValue(":client_id", clientId);

    if (query.exec()) {
        while (query.next()) {
            rentalInfo += "— Rental #" + query.value("rental_id").toString() +
                          ", room: " + query.value("room_number").toString() +
                          ", from: " + query.value("check_in_date").toString() +
                          ", to: " + query.value("check_out_date").toString() + "\n";
        }
    }

    QString fullInfo = clientInfo;

    if (!rentalInfo.isEmpty()) {
        fullInfo += "\n\nClient's rentals:\n" + rentalInfo.trimmed();
    } else if (!clientInfo.contains("Not found")) {
        fullInfo += "\n\nThe client has no rentals.";
    }

    QMessageBox::information(parent, "Search result", fullInfo);
}

// filtrowanie klientow po wpisaniu tekstu
void clientwindow::on_lineEdit_searchClient_textChanged(const QString &text)
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewClients->model());

    QString pattern = text.trimmed();
    if (pattern.isEmpty()) {
        model->setFilter("");  // pokaz wszystkich
    } else {
        model->setFilter(QString(
                             "first_name ILIKE '%%1%' OR last_name ILIKE '%%1%'"
                             ).arg(pattern));
    }
}

// obsluga klikniecia w wiersz tabeli klientow
void clientwindow::handleClientRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;
    QString clientId = ui->tableViewClients->model()->data(ui->tableViewClients->model()->index(index.row(), 0)).toString();
    clientwindow::displayClientDetails(this, clientId);
}
