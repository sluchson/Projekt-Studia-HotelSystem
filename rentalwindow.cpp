#include "rentalwindow.h"
#include "ui_rentalwindow.h"
#include "database.h"
#include "addrental.h"
#include "deleterental.h"
#include <QMessageBox>
#include <QSqlQuery>

extern Database db;

// konstruktor okna wypozyczen
rentalwindow::rentalwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::rentalwindow)
{
    ui->setupUi(this);
    setWindowTitle("Hotel System - Rentals");
    ui->tableViewRentals->setModel(db.getRentalsModel());

    // po kliknieciu w tabele wypozyczen, wyswietl szczegoly
    connect(ui->tableViewRentals, &QTableView::clicked, this, &rentalwindow::handleRentalRowClick);
    ui->tableViewRentals->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewRentals->setSortingEnabled(true);
    ui->dateEdit_from->setDate(QDate::currentDate().addYears(-1));
}

// destruktor okna
rentalwindow::~rentalwindow()
{
    delete ui;
}

// obsluga przycisku dodania wypozyczenia
void rentalwindow::on_pushButtonAddRental_clicked()
{
    addrental *addRentalWin = new addrental(this);
    // odswiez model po dodaniu wypozyczenia
    connect(addRentalWin, &addrental::rentalAdded, this, [this]() {
        static_cast<QSqlTableModel*>(ui->tableViewRentals->model())->select();
    });
    addRentalWin->show();
}

// obsluga przycisku usuniecia wypozyczenia
void rentalwindow::on_pushButtonDeleteRental_clicked()
{
    deleterental *deleteRentalWin = new deleterental(this);
    // odswiez model po usunieciu wypozyczenia
    connect(deleteRentalWin, &deleterental::rentalDeleted, this, [this]()
            {
                static_cast<QSqlTableModel*>(ui->tableViewRentals->model())->select();
            });
    deleteRentalWin->show();
}

// wyswietlanie szczegolow wypozyczenia
void rentalwindow::displayRentalDetails(QWidget *parent, const QString& rentalId)
{
    if (rentalId.isEmpty()) {
        QMessageBox::warning(parent, "Error", "Rental ID is empty.");
        return;
    }

    QString rentalInfo = db.searchRecord("rentals", "rental_id", rentalId);
    QString fullInfo = rentalInfo;

    if (!rentalInfo.contains("Not found")) {
        QSqlQuery query;
        query.prepare("SELECT client_id, room_number FROM rentals WHERE rental_id = :rental_id");
        query.bindValue(":rental_id", rentalId);

        if (query.exec() && query.next()) {
            QString clientId = query.value("client_id").toString();
            QString roomNumber = query.value("room_number").toString();

            QString clientInfo = db.searchRecord("clients", "client_id", clientId);
            fullInfo += "\n\n--- Client details ---\n" + clientInfo;

            QString roomInfo = db.searchRecord("rooms", "room_number", roomNumber);
            fullInfo += "\n\n--- Room details ---\n" + roomInfo;
        }
    }

    QMessageBox::information(parent, "Rental details", fullInfo);
}

// laczenie filtrow wyszukiwania (tekst + data)
void rentalwindow::applyCombinedFilter()
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewRentals->model());

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

// po zmianie tekstu wyszukiwania wywolaj filtrowanie
void rentalwindow::on_lineEdit_searchRental_textChanged(const QString &)
{
    applyCombinedFilter();
}

// po zmianie daty poczatkowej wywolaj filtrowanie
void rentalwindow::on_dateEdit_from_dateChanged(const QDate &)
{
    applyCombinedFilter();
}

// obsluga klikniecia w wiersz tabeli - wyswietl szczegoly wypozyczenia
void rentalwindow::handleRentalRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString rentalId = ui->tableViewRentals->model()->data(ui->tableViewRentals->model()->index(index.row(), 0)).toString();
    rentalwindow::displayRentalDetails(this, rentalId);
}
