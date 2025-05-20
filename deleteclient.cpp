#include "deleteclient.h"
#include "ui_deleteclient.h"
#include "database.h"
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

}

deleteclient::~deleteclient()
{
    delete ui;
}


void deleteclient::handleRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    int row = index.row();
    QString clientId = clientsModel->data(clientsModel->index(row, 0)).toString(); // kolumna 0 = client_id

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Potwierdzenie",
        "Ten klient może mieć przypisane wypożyczenia.\nCzy na pewno chcesz go usunąć?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        // Usuń wypożyczenia tego klienta
        QSqlQuery deleteRentals;
        deleteRentals.prepare("DELETE FROM rentals WHERE client_id = :client_id");
        deleteRentals.bindValue(":client_id", clientId);
        if (!deleteRentals.exec()) {
            QMessageBox::warning(this, "Błąd", "Nie udało się usunąć wypożyczeń:\n" + deleteRentals.lastError().text());
            return;
        }

        // Usuń klienta
        if (!clientsModel->removeRow(row)) {
            QMessageBox::warning(this, "Błąd", "Nie udało się usunąć klienta.");
            return;
        }

        if (!clientsModel->submitAll()) {
            QMessageBox::warning(this, "Błąd", "Nie udało się zapisać zmian:\n" + clientsModel->lastError().text());
            clientsModel->revertAll();
            return;
        }

        QMessageBox::information(this, "Sukces", "Klient i jego wypożyczenia zostali usunięci.");
    }
}
