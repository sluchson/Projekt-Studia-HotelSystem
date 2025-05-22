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
    rentalsModel = db.getRentalsModel();
    ui->tableViewRentalToDelete->setModel(rentalsModel);

    connect(ui->tableViewRentalToDelete, &QTableView::clicked, this, &deleterental::handleRowClick);
    ui->tableViewRentalToDelete->setSortingEnabled(true);
    ui->dateEdit_from->setDate(QDate::currentDate().addYears(-1));
}

deleterental::~deleterental()
{
    delete ui;
}


bool deleterental::deleteRentalById(const QString& rentalId)
{
    QString roomNumber;
    QSqlQuery getRoomQuery;
    getRoomQuery.prepare("SELECT room_number FROM rentals WHERE rental_id = :rental_id");
    getRoomQuery.bindValue(":rental_id", rentalId);
    if (getRoomQuery.exec() && getRoomQuery.next()) {
        roomNumber = getRoomQuery.value(0).toString();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się znaleźć pokoju dla danego wypożyczenia.");
        return false;
    }

    // Teraz usuń wypożyczenie z modelu
    for (int row = 0; row < rentalsModel->rowCount(); ++row) {
        QString modelRentalId = rentalsModel->data(rentalsModel->index(row, 0)).toString();
        if (modelRentalId == rentalId) {
            if (!rentalsModel->removeRow(row)) {
                QMessageBox::warning(this, "Błąd", "Nie udało się usunąć wypożyczenia.");
                return false;
            }

            if (!rentalsModel->submitAll()) {
                QMessageBox::warning(this, "Błąd", "Nie udało się zapisać zmian:\n" + rentalsModel->lastError().text());
                rentalsModel->revertAll();
                return false;
            }

            // Zaktualizuj dostępność pokoju na true
            QSqlQuery updateRoomQuery;
            updateRoomQuery.prepare("UPDATE rooms SET is_available = true WHERE room_number = :room_number");
            updateRoomQuery.bindValue(":room_number", roomNumber);
            if (!updateRoomQuery.exec()) {
                QMessageBox::warning(this, "Błąd", "Nie udało się zaktualizować statusu pokoju:\n" + updateRoomQuery.lastError().text());
                return false;
            }

            return true;
        }
    }

    QMessageBox::warning(this, "Błąd", "Nie znaleziono wypożyczenia o podanym ID.");
    return false;
}



void deleterental::handleRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString rentalId = rentalsModel->data(rentalsModel->index(index.row(), 0)).toString(); // kol. 0 = rental_id

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Potwierdzenie",
        QString("Czy na pewno chcesz usunąć wypożyczenie #%1?").arg(rentalId),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (deleteRentalById(rentalId)) {
            QMessageBox::information(this, "Sukces", "Wypożyczenie zostało usunięte.");
            static_cast<QSqlTableModel*>(ui->tableViewRentalToDelete->model())->select();
            emit rentalDeleted();

        }
    }
}


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

void deleterental::on_lineEdit_searchRental_textChanged(const QString &)
{
    applyCombinedFilter();
}

void deleterental::on_dateEdit_from_dateChanged(const QDate &)
{
    applyCombinedFilter();
}


