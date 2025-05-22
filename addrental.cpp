#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>
#include "addrental.h"
#include "ui_addrental.h"
#include "rental.h"
#include "database.h"

extern Database db;

addrental::addrental(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addrental)
{
    ui->setupUi(this);

    // laduj klientow do comboboxa
    QSqlQuery clientsQuery("SELECT client_id, first_name || ' ' || last_name AS full_name FROM clients");
    while (clientsQuery.next()) {
        int id = clientsQuery.value("client_id").toInt();
        QString name = clientsQuery.value("full_name").toString();
        ui->comboBox_client->addItem(name, id);
    }

    // laduj wszystkie pokoje do comboboxa
    QSqlQuery roomsQuery("SELECT room_number, price_per_night FROM rooms");
    while (roomsQuery.next()) {
        int roomNumber = roomsQuery.value("room_number").toInt();
        double price = roomsQuery.value("price_per_night").toDouble();
        QString displayText = QString("%1 – %2 PLN/night").arg(roomNumber).arg(price, 0, 'f', 2);
        ui->comboBox_room->addItem(displayText, roomNumber);
    }

    // automatyczna aktualizacja ceny po zmianie pokoju lub daty
    connect(ui->comboBox_room, &QComboBox::currentIndexChanged, this, &addrental::updateTotalPrice);
    connect(ui->dateEdit_checkin, &QDateEdit::dateChanged, this, &addrental::updateTotalPrice);
    connect(ui->dateEdit_checkout, &QDateEdit::dateChanged, this, &addrental::updateTotalPrice);

    // pole z cena jest tylko do odczytu
    ui->lineEdit_price->setReadOnly(true);
    ui->dateEdit_checkin->setDate(QDate::currentDate());
    ui->dateEdit_checkout->setDate(QDate::currentDate());
}

addrental::~addrental()
{
    delete ui;
}

// oblicza i wyswietla cene za caly okres pobytu
void addrental::updateTotalPrice() {
    int roomNumber = ui->comboBox_room->currentData().toInt();
    QDate checkIn = ui->dateEdit_checkin->date();
    QDate checkOut = ui->dateEdit_checkout->date();

    // licz dni pobytu
    int days = checkIn.daysTo(checkOut);
    if (days <= 0) {
        ui->lineEdit_price->clear();
        return;
    }

    // pobierz cene za noc z bazy
    QSqlQuery query;
    query.prepare("SELECT price_per_night FROM rooms WHERE room_number = :room_number");
    query.bindValue(":room_number", roomNumber);

    if (query.exec() && query.next()) {
        double pricePerNight = query.value(0).toDouble();
        double totalPrice = pricePerNight * days;
        ui->lineEdit_price->setText(QString::number(totalPrice, 'f', 2));
    } else {
        ui->lineEdit_price->clear();
    }
}

// klikniecie w przycisk dodania rezerwacji
void addrental::on_pushButton_add_rental_clicked()
{
    QDate checkIn = ui->dateEdit_checkin->date();
    QDate checkOut = ui->dateEdit_checkout->date();

    // sprawdz czy data zameldowania jest wczesniejsza niz wymeldowania
    if (checkIn >= checkOut) {
        QMessageBox::warning(this, "Error", "Check-in date must be earlier than check-out date.");
        return;
    }

    // sprawdz konflikt rezerwacji dla pokoju
    int roomNumber = ui->comboBox_room->currentData().toInt();
    QSqlQuery conflictQuery;
    conflictQuery.prepare(R"(
        SELECT COUNT(*) FROM rentals
        WHERE room_number = :room_number
        AND (:check_in < check_out_date AND :check_out > check_in_date)
    )");
    conflictQuery.bindValue(":room_number", roomNumber);
    conflictQuery.bindValue(":check_in", checkIn);
    conflictQuery.bindValue(":check_out", checkOut);

    if (conflictQuery.exec() && conflictQuery.next()) {
        int conflictCount = conflictQuery.value(0).toInt();
        if (conflictCount > 0) {
            QMessageBox::warning(this, "Error", "This room is already reserved for the selected period.");
            return;
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to check room availability.");
        return;
    }

    // utworz rezerwacje i dodaj do bazy
    Rental rental(
        ui->comboBox_client->currentData().toInt(),
        ui->comboBox_room->currentData().toInt(),
        checkIn,
        checkOut,
        ui->lineEdit_price->text().toDouble()
        );

    if (db.addRental(rental)) {
        QMessageBox::information(this, "Success", "Rental added.");
        emit rentalAdded();
        db.updateRoomsAvailability();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Failed to add rental.");
    }
}
