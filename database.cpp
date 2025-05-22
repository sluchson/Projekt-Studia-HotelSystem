// database.cpp

#include "database.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>



Database::Database() {
    // Pusta definicja konstruktora
}

bool Database::openConnection() {
    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("localhost");
        db.setDatabaseName("hotel_db");
        db.setUserName("postgres");
        db.setPassword("admin");
    }
    return db.open();
}


void Database::closeConnection() {
    db.close();
}

QSqlDatabase& Database::getDatabase() {
    return db;
}

//Modele poszczególnych tabel
QSqlTableModel* Database::getClientsModel() {
    QSqlTableModel* model = new QSqlTableModel;
    model->setTable("clients");
    model->select();
    return model;
}

QSqlTableModel* Database::getRoomsModel() {
    QSqlTableModel* model = new QSqlTableModel;
    model->setTable("rooms");
    model->select();
    return model;
}

QSqlTableModel* Database::getRentalsModel() {
    QSqlTableModel* model = new QSqlTableModel;
    model->setTable("rentals");
    model->select();
    return model;
}




// Operacje dodawania i usuwania klienta
bool Database::addClient(const Client& client) {
    QSqlQuery query;

    query.prepare("INSERT INTO clients (first_name, last_name, email, phone) "
                  "VALUES (:first_name, :last_name, :email, :phone)");
    query.bindValue(":first_name", client.getFirstName());
    query.bindValue(":last_name", client.getLastName());
    query.bindValue(":email", client.getEmail());
    query.bindValue(":phone", client.getPhoneNumber());

    if (!query.exec()) {
        qDebug() << "Błąd dodawania klienta:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Database::removeClient(int clientId) {
    QSqlQuery query;
    query.prepare("DELETE FROM clients WHERE client_id = :id");
    query.bindValue(":id", clientId);

    if (!query.exec()) {
        qDebug() << "Błąd usuwania klienta:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "Nie znaleziono klienta o podanym ID.";
        return false;
    }

    return true;
}



//Operacje dodawania i usuwania pokoju
bool Database::addRoom(const Room& room) {
    QSqlQuery query;
    query.prepare("INSERT INTO rooms (room_number, room_type, price_per_night, is_available) "
                  "VALUES (:room_number, :room_type, :price_per_night, :is_available)");
    query.bindValue(":room_number", room.getNumber());
    query.bindValue(":room_type", room.getType());
    query.bindValue(":price_per_night", room.getPricePerNight());
    query.bindValue(":is_available", room.isAvailable());

    if (!query.exec()) {
        qDebug() << "Blad dodawania pokoju:" << query.lastError().text();
        return false;
    }

    return true;
}


bool Database::removeRoom(int roomNumber) {
    QSqlQuery query;
    query.prepare("DELETE FROM rooms WHERE room_number = :room_number");
    query.bindValue(":room_number", roomNumber);

    if (!query.exec()) {
        qDebug() << "Blad usuwania pokoju:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "Nie znaleziono pokoju o podanym numerze.";
        return false;
    }

    return true;
}


//Operacje dodawania i usuwania rezerwacji
bool Database::addRental(const Rental& rental) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO rentals (client_id, room_number, check_in_date, check_out_date, total_price) "
                  "VALUES (:client_id, :room_number, :check_in_date, :check_out_date, :total_price)");
    query.bindValue(":client_id", rental.getClientId());
    query.bindValue(":room_number", rental.getRoomNumber());
    query.bindValue(":check_in_date", rental.getCheckInDate());
    query.bindValue(":check_out_date", rental.getCheckOutDate());
    query.bindValue(":total_price", rental.getTotalPrice());

    if (!query.exec()) {
        qDebug() << "Błąd dodawania wypożyczenia:" << query.lastError().text();
        return false;
    }

    // Zmieniamy status pokoju na niedostępny
    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE rooms SET is_available = false WHERE room_number = :room_number");
    updateQuery.bindValue(":room_number", rental.getRoomNumber());

    if (!updateQuery.exec()) {
        qDebug() << "Błąd aktualizacji dostępności pokoju:" << updateQuery.lastError().text();
        return false;
    }

    return true;
}


bool Database::removeRental(int rentalId) {
    QSqlQuery query;
    query.prepare("DELETE FROM rentals WHERE rental_id = :id");
    query.bindValue(":id", rentalId);

    if (!query.exec()) {
        qDebug() << "Blad usuwania wynajmu:" << query.lastError().text();
        return false;
    }
    if (query.numRowsAffected() == 0) {
        qDebug() << "Nie znaleziono wynajmu o podanym ID.";
        return false;
    }
    return true;
}


QString Database::searchRecord(const QString& table, const QString& column, const QString& value) {
    QSqlQuery query(db);
    QString sql = QString("SELECT * FROM %1 WHERE %2 = :value").arg(table, column);
    query.prepare(sql);
    query.bindValue(":value", value);

    if (!query.exec()) {
        return "Błąd zapytania: " + query.lastError().text();
    }

    if (query.next()) {
        QString result;
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); ++i) {
            result += record.fieldName(i) + ": " + query.value(i).toString() + "\n";
        }
        return result.trimmed();
    } else {
        return "Nie znaleziono rekordu.";
    }
}
