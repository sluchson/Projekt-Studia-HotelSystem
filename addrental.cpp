#include <QSqlQuery>
#include <QMessageBox>
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

    // Załaduj klientów
    QSqlQuery clientsQuery("SELECT client_id, first_name || ' ' || last_name AS full_name FROM clients");
    while (clientsQuery.next()) {
        int id = clientsQuery.value("client_id").toInt();
        QString name = clientsQuery.value("full_name").toString();
        ui->comboBox_client->addItem(name, id);
    }

    // Załaduj dostępne pokoje
    QSqlQuery roomsQuery("SELECT room_number, price_per_night FROM rooms WHERE is_available = true");
    while (roomsQuery.next()) {
        int roomNumber = roomsQuery.value("room_number").toInt();
        double price = roomsQuery.value("price_per_night").toDouble();
        QString displayText = QString("%1 – %2 zł/night").arg(roomNumber).arg(price, 0, 'f', 2);
        ui->comboBox_room->addItem(displayText, roomNumber);
    }


    // Automatyczna aktualizacja ceny przy zmianie pokoju lub dat
    connect(ui->comboBox_room, &QComboBox::currentIndexChanged, this, &addrental::updateTotalPrice);
    connect(ui->dateEdit_checkin, &QDateEdit::dateChanged, this, &addrental::updateTotalPrice);
    connect(ui->dateEdit_checkout, &QDateEdit::dateChanged, this, &addrental::updateTotalPrice);

    // Zablokuj możliwość edycji ceny
    ui->lineEdit_price->setReadOnly(true);
    ui->dateEdit_checkin->setDate(QDate::currentDate());
    ui->dateEdit_checkout->setDate(QDate::currentDate());
}

addrental::~addrental()
{
    delete ui;
}

void addrental::updateTotalPrice() {
    int roomNumber = ui->comboBox_room->currentData().toInt();
    QDate checkIn = ui->dateEdit_checkin->date();
    QDate checkOut = ui->dateEdit_checkout->date();

    // Liczba dni
    int days = checkIn.daysTo(checkOut);
    if (days <= 0) {
        ui->lineEdit_price->clear();
        return;
    }

    // Pobierz cenę za noc z bazy
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

void addrental::on_pushButton_add_rental_clicked()
{
    // Tworzenie wypożyczenia na podstawie pól formularza
    QDate checkIn = ui->dateEdit_checkin->date();
    QDate checkOut = ui->dateEdit_checkout->date();

    if (checkIn >= checkOut) {
        QMessageBox::warning(this, "Błąd", "Data zameldowania musi być wcześniejsza niż data wymeldowania.");
        return;
    }

    Rental rental(
        ui->comboBox_client->currentData().toInt(),
        ui->comboBox_room->currentData().toInt(),
        checkIn,
        checkOut,
        ui->lineEdit_price->text().toDouble()
        );


    if (db.addRental(rental)) {
        QMessageBox::information(this, "Sukces", "Dodano wypożyczenie");
        this->close();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać wypożyczenia.");
    }
}
