#include "deleteclient.h"
#include "ui_deleteclient.h"
#include "database.h"
#include "clientwindow.h"
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
    connect(ui->tableViewClientToDelete, &QTableView::clicked, this, &deleteclient::handleRowClick);
    ui->tableViewClientToDelete->setSortingEnabled(true);
}

deleteclient::~deleteclient()
{
    delete ui;
}

bool deleteclient::deleteClientById(const QString& clientId)
{
    // Usuń wypożyczenia klienta z użyciem deleterental
    QSqlQuery getRentals;
    getRentals.prepare("SELECT rental_id FROM rentals WHERE client_id = :client_id");
    getRentals.bindValue(":client_id", clientId);
    if (getRentals.exec()) {
        deleterental rentalDeleter; // tymczasowy obiekt do wywołania funkcji
        while (getRentals.next()) {
            QString rentalId = getRentals.value(0).toString();
            rentalDeleter.deleteRentalById(rentalId);
        }
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się pobrać wypożyczeń klienta:\n" + getRentals.lastError().text());
        return false;
    }

    // Usuń klienta z modelu
    for (int row = 0; row < clientsModel->rowCount(); ++row) {
        QString modelClientId = clientsModel->data(clientsModel->index(row, 0)).toString();
        if (modelClientId == clientId) {
            if (!clientsModel->removeRow(row)) {
                QMessageBox::warning(this, "Błąd", "Nie udało się usunąć klienta.");
                return false;
            }

            if (!clientsModel->submitAll()) {
                QMessageBox::warning(this, "Błąd", "Nie udało się zapisać zmian:\n" + clientsModel->lastError().text());
                clientsModel->revertAll();
                return false;
            }

            return true;
        }
    }

    QMessageBox::warning(this, "Błąd", "Nie znaleziono klienta w modelu.");
    return false;
}


void deleteclient::handleRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString clientId = clientsModel->data(clientsModel->index(index.row(), 0)).toString();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Potwierdzenie",
        "Ten klient może mieć przypisane wypożyczenia.\nCzy na pewno chcesz go usunąć?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (deleteClientById(clientId)) {
            QMessageBox::information(this, "Sukces", "Klient i jego wypożyczenia zostali usunięci.");
            static_cast<QSqlTableModel*>(ui->tableViewClientToDelete->model())->select();
            emit clientDeleted();  // powiadomienie o zmianie
        }
    }
}



void deleteclient::on_lineEdit_searchClient_textChanged(const QString &text)
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewClientToDelete->model());

    QString pattern = text.trimmed();
    if (pattern.isEmpty()) {
        model->setFilter("");  // Pokaż wszystkich
    } else {
        model->setFilter(QString(
                             "first_name ILIKE '%%1%%' OR last_name ILIKE '%%1%%'"
                             ).arg(pattern));
    }
}




