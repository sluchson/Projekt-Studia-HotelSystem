#include "deleteclient.h"
#include "ui_deleteclient.h"
#include "database.h"
#include "clientwindow.h"
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

bool deleteclient::deleteClientById(const QString& clientId)
{
    // Usuń wypożyczenia
    QSqlQuery deleteRentals;
    deleteRentals.prepare("DELETE FROM rentals WHERE client_id = :client_id");
    deleteRentals.bindValue(":client_id", clientId);
    if (!deleteRentals.exec()) {
        QMessageBox::warning(this, "Błąd", "Nie udało się usunąć wypożyczeń:\n" + deleteRentals.lastError().text());
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
        }
    }
}

void deleteclient::on_pushButton_searchClient_clicked()
{
    QString clientId = ui->lineEdit_searchClientId->text().trimmed();
    if (clientId.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wprowadź ID klienta do wyszukania.");
        return;
    }

    // Wyświetlenie danych klienta i jego wypożyczeń
    clientwindow::displayClientDetails(this, clientId);

    // Potwierdzenie usunięcia
    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Potwierdzenie usunięcia",
        "Czy chcesz usunąć tego klienta?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (deleteClientById(clientId)) {
            QMessageBox::information(this, "Sukces", "Klient i jego wypożyczenia zostali usunięci.");
        }
    }
}

void deleteclient::on_pushButtonRefresh_clicked()
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewClientToDelete->model());
    db.refreshExistingModel(model);
}

