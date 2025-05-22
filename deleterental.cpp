#include "deleterental.h"
#include "ui_deleterental.h"
#include "database.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

extern Database db;

deleterental::deleterental(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deleterental)
{
    ui->setupUi(this);
    setWindowTitle("Hotel System - Delete Rental");
    rentalsModel = db.getRentalsModel();
    ui->tableViewRentalToDelete->setModel(rentalsModel);

    // laczymy klikniecie z obsluga usuwania
    connect(ui->tableViewRentalToDelete, &QTableView::clicked, this, &deleterental::handleRowClick);
    ui->tableViewRentalToDelete->setSortingEnabled(true);
    // domyslna data od ktorej wyswietlane sa wyniki
    ui->dateEdit_from->setDate(QDate::currentDate().addYears(-1));
}

deleterental::~deleterental()
{
    delete ui;
}

// usuwa wypozyczenie o podanym id, aktualizuje status pokoju
bool deleterental::deleteRentalById(const QString& rentalId)
{
    QString roomNumber;
    QSqlQuery getRoomQuery;
    getRoomQuery.prepare("SELECT room_number FROM rentals WHERE rental_id = :rental_id");
    getRoomQuery.bindValue(":rental_id", rentalId);
    if (getRoomQuery.exec() && getRoomQuery.next()) {
        roomNumber = getRoomQuery.value(0).toString();
    } else {
        QMessageBox::warning(this, "Error", "Could not find the room for the selected rental.");
        return false;
    }

    // szukamy wypozyczenia w modelu i usuwamy je
    for (int row = 0; row < rentalsModel->rowCount(); ++row) {
        QString modelRentalId = rentalsModel->data(rentalsModel->index(row, 0)).toString();
        if (modelRentalId == rentalId) {
            if (!rentalsModel->removeRow(row)) {
                QMessageBox::warning(this, "Error", "Could not delete rental.");
                return false;
            }

            if (!rentalsModel->submitAll()) {
                QMessageBox::warning(this, "Error", "Could not save changes:\n" + rentalsModel->lastError().text());
                rentalsModel->revertAll();
                return false;
            }

            // po usunieciu wywolujemy globalna aktualizacje dostepnosci pokoi
            db.updateRoomsAvailability();

            return true;
        }
    }

    QMessageBox::warning(this, "Error", "Rental not found in model.");
    return false;
}

// obsluga klikniecia wiersza, pyta o potwierdzenie i usuwa
void deleterental::handleRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString rentalId = rentalsModel->data(rentalsModel->index(index.row(), 0)).toString();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Confirmation",
        QString("Are you sure you want to delete rental #%1?").arg(rentalId),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (deleteRentalById(rentalId)) {
            QMessageBox::information(this, "Success", "Rental has been deleted.");
            static_cast<QSqlTableModel*>(ui->tableViewRentalToDelete->model())->select();
            emit rentalDeleted();
        }
    }
}

// filtrowanie po dacie i tekscie
void deleterental::applyCombinedFilter()
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewRentalToDelete->model());

    QString pattern = ui->lineEdit_searchRental->text().trimmed();
    QDate from = ui->dateEdit_from->date();

    QString textFilter;
    if (!pattern.isEmpty()) {
        textFilter = QString(
                         "(CAST(rental_id AS TEXT) ILIKE '%%1%%' OR "
                         "CAST(client_id AS TEXT) ILIKE '%%1%%' OR "
                         "CAST(room_number AS TEXT) ILIKE '%%1%%')"
                         ).arg(pattern);
    }

    QString dateFilter = QString("check_in_date >= '%1'")
                             .arg(from.toString("yyyy-MM-dd"));

    QString finalFilter = textFilter.isEmpty() ? dateFilter : dateFilter + " AND " + textFilter;
    model->setFilter(finalFilter);
}

// aktualizuje filtrowanie po zmianie tekstu
void deleterental::on_lineEdit_searchRental_textChanged(const QString &)
{
    applyCombinedFilter();
}

// aktualizuje filtrowanie po zmianie daty
void deleterental::on_dateEdit_from_dateChanged(const QDate &)
{
    applyCombinedFilter();
}
