#include "rentalwindow.h"
#include "ui_rentalwindow.h"
#include "database.h"
#include "addrental.h"
#include "deleterental.h"
#include <QMessageBox>
#include <QSqlQuery>

extern Database db;


rentalwindow::rentalwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::rentalwindow)
{
    ui->setupUi(this);
    ui->tableViewRentals->setModel(db.getRentalsModel());
}

rentalwindow::~rentalwindow()
{
    delete ui;
}

void rentalwindow::on_pushButtonAddRental_clicked()
{
    addrental *addRentalWin = new addrental(this);
    addRentalWin->show();
}


void rentalwindow::on_pushButtonDeleteRental_clicked()
{
    deleterental *deleteRentalWin = new deleterental(this);
    deleteRentalWin->show();
}

void rentalwindow::on_pushButton_searchRental_clicked()
{
    QString rentalId = ui->lineEdit_searchRentalId->text().trimmed();
    if (rentalId.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wprowadź ID wypożyczenia do wyszukania.");
        return;
    }

    // Dane wypożyczenia
    QString rentalInfo = db.searchRecord("rentals", "rental_id", rentalId);
    QString fullInfo = rentalInfo;

    // Jeśli znaleziono, to szukamy danych klienta i pokoju
    if (!rentalInfo.contains("Nie znaleziono")) {
        QSqlQuery query;
        query.prepare("SELECT client_id, room_number FROM rentals WHERE rental_id = :rental_id");
        query.bindValue(":rental_id", rentalId);

        if (query.exec() && query.next()) {
            QString clientId = query.value("client_id").toString();
            QString roomNumber = query.value("room_number").toString();

            // Dane klienta
            QString clientInfo = db.searchRecord("clients", "client_id", clientId);
            fullInfo += "\n\n--- Dane klienta ---\n" + clientInfo;

            // Dane pokoju
            QString roomInfo = db.searchRecord("rooms", "room_number", roomNumber);
            fullInfo += "\n\n--- Dane pokoju ---\n" + roomInfo;
        }
    }

    QMessageBox::information(this, "Wynik wyszukiwania", fullInfo);
}

