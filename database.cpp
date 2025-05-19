// database.cpp

#include "database.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>



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
        if (!db.isOpen()) {
            qDebug() << "Połączenie z bazą danych nie jest aktywne";
            return false;
        }

        QSqlQuery query(db);

        query.prepare("INSERT INTO clients (first_name, last_name, email, phone_number) "
                      "VALUES (:first_name, :last_name, :email, :phone_number)");
        query.bindValue(":first_name", client.getFirstName());
        query.bindValue(":last_name", client.getLastName());
        query.bindValue(":email", client.getEmail());
        query.bindValue(":phone_number", client.getPhoneNumber());

        if (!query.exec()) {
            qDebug() << "Błąd dodawania klienta:" << query.lastError().text();
            return false;
        }

        return true;
    }

    bool Database::removeClient(int clientId) {
        QSqlQuery query(db);
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
        QSqlQuery query(db);
        query.prepare("INSERT INTO rooms (room_number, type, price_per_night, available) "
                      "VALUES (:room_number, :type, :price, :available)");
        query.bindValue(":room_number", room.getNumber());
        query.bindValue(":type", room.getType());
        query.bindValue(":price", room.getPricePerNight());
        query.bindValue(":available", room.isAvailable());

        if (!query.exec()) {
            qDebug() << "Blad dodawania pokoju:" << query.lastError().text();
            return false;
        }

        return true;
    }


    bool Database::removeRoom(int roomNumber) {
        QSqlQuery query(db);
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
                      "VALUES (:client_id, :room_number, :check_in, :check_out, :total)");
        query.bindValue(":client_id", rental.getClientId());
        query.bindValue(":room_number", rental.getRoomNumber());
        query.bindValue(":check_in", rental.getCheckInDate());
        query.bindValue(":check_out", rental.getCheckOutDate());
        query.bindValue(":total", rental.getTotalPrice());

        if (!query.exec()) {
            qDebug() << "Blad dodawania wynajmu:" << query.lastError().text();
            return false;
        }
        return true;
    }

    bool Database::removeRental(int rentalId) {
        QSqlQuery query(db);
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

