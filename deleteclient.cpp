#include "deleteclient.h"
#include "ui_deleteclient.h"
#include "database.h"
#include "deleterental.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

extern Database db;

deleteclient::deleteclient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deleteclient)
{
    ui->setupUi(this);
    clientsModel = db.getClientsModel();
    ui->tableViewClientToDelete->setModel(clientsModel);
    // polaczenie klikniecia wiersza z funkcja usuwania
    connect(ui->tableViewClientToDelete, &QTableView::clicked, this, &deleteclient::handleRowClick);
    ui->tableViewClientToDelete->setSortingEnabled(true);
}

deleteclient::~deleteclient()
{
    delete ui;
}

// usuwa klienta po id razem i wypozyczenia
bool deleteclient::deleteClientById(const QString& clientId)
{
    // usun wszystkie wypozyczenia klienta
    QSqlQuery getRentals;
    getRentals.prepare("SELECT rental_id FROM rentals WHERE client_id = :client_id");
    getRentals.bindValue(":client_id", clientId);
    if (getRentals.exec()) {
        deleterental rentalDeleter;
        while (getRentals.next()) {
            QString rentalId = getRentals.value(0).toString();
            rentalDeleter.deleteRentalById(rentalId);
        }
    } else {
        QMessageBox::warning(this, "Error", "Could not fetch client's rentals:\n" + getRentals.lastError().text());
        return false;
    }

    // usun klienta z modelu
    for (int row = 0; row < clientsModel->rowCount(); ++row) {
        QString modelClientId = clientsModel->data(clientsModel->index(row, 0)).toString();
        if (modelClientId == clientId) {
            if (!clientsModel->removeRow(row)) {
                QMessageBox::warning(this, "Error", "Could not delete client.");
                return false;
            }
            if (!clientsModel->submitAll()) {
                QMessageBox::warning(this, "Error", "Could not save changes:\n" + clientsModel->lastError().text());
                clientsModel->revertAll();
                return false;
            }
            return true;
        }
    }

    QMessageBox::warning(this, "Error", "Client not found in model.");
    return false;
}

// obsluga klikniecia wiersza - pyta o potwierdzenie i usuwa klienta
void deleteclient::handleRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString clientId = clientsModel->data(clientsModel->index(index.row(), 0)).toString();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Confirmation",
        "This client may have assigned rentals.\nAre you sure you want to delete?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (deleteClientById(clientId)) {
            QMessageBox::information(this, "Success", "Client and all their rentals have been deleted.");
            static_cast<QSqlTableModel*>(ui->tableViewClientToDelete->model())->select();
            emit clientDeleted();
        }
    }
}

// filtruje klientow po wpisanym tekscie
void deleteclient::on_lineEdit_searchClient_textChanged(const QString &text)
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewClientToDelete->model());
    QString pattern = text.trimmed();
    if (pattern.isEmpty()) {
        model->setFilter("");
    } else {
        model->setFilter(QString(
                             "first_name ILIKE '%%1%%' OR last_name ILIKE '%%1%%'"
                             ).arg(pattern));
    }
}
