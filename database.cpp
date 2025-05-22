// database.cpp

#include "database.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

// konstruktor pusty
Database::Database() {}

bool Database::openConnection() {
    // otwarcie polaczenia z baza
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

// zwraca polaczenie do bazy
QSqlDatabase& Database::getDatabase() {
    return db;
}

// pobierz model klientow
QSqlTableModel* Database::getClientsModel() {
    QSqlTableModel* model = new QSqlTableModel;
    model->setTable("clients");
    model->select();
    return model;
}

// pobierz model pokoi
QSqlTableModel* Database::getRoomsModel() {
    QSqlTableModel* model = new QSqlTableModel;
    model->setTable("rooms");
    model->select();
    return model;
}

// pobierz model wypozyczen
QSqlTableModel* Database::getRentalsModel() {
    QSqlTableModel* model = new QSqlTableModel;
    model->setTable("rentals");
    model->select();
    return model;
}

// dodaj klienta do bazy
bool Database::addClient(const Client& client) {
    QSqlQuery query;
    query.prepare("INSERT INTO clients (first_name, last_name, email, phone) "
                  "VALUES (:first_name, :last_name, :email, :phone)");
    query.bindValue(":first_name", client.getFirstName());
    query.bindValue(":last_name", client.getLastName());
    query.bindValue(":email", client.getEmail());
    query.bindValue(":phone", client.getPhoneNumber());

    if (!query.exec()) {
        qDebug() << "Error adding client:" << query.lastError().text();
        return false;
    }
    return true;
}

// usun klienta z bazy
bool Database::removeClient(int clientId) {
    QSqlQuery query;
    query.prepare("DELETE FROM clients WHERE client_id = :id");
    query.bindValue(":id", clientId);

    if (!query.exec()) {
        qDebug() << "Error deleting client:" << query.lastError().text();
        return false;
    }
    if (query.numRowsAffected() == 0) {
        qDebug() << "No client found with the provided ID.";
        return false;
    }
    return true;
}

// dodaj pokoj do bazy
bool Database::addRoom(const Room& room) {
    QSqlQuery query;
    query.prepare("INSERT INTO rooms (room_number, room_type, price_per_night, is_available) "
                  "VALUES (:room_number, :room_type, :price_per_night, :is_available)");
    query.bindValue(":room_number", room.getNumber());
    query.bindValue(":room_type", room.getType());
    query.bindValue(":price_per_night", room.getPricePerNight());
    query.bindValue(":is_available", room.isAvailable());

    if (!query.exec()) {
        qDebug() << "Error adding room:" << query.lastError().text();
        return false;
    }
    return true;
}

// usun pokoj z bazy
bool Database::removeRoom(int roomNumber) {
    QSqlQuery query;
    query.prepare("DELETE FROM rooms WHERE room_number = :room_number");
    query.bindValue(":room_number", roomNumber);

    if (!query.exec()) {
        qDebug() << "Error deleting room:" << query.lastError().text();
        return false;
    }
    if (query.numRowsAffected() == 0) {
        qDebug() << "No room found with the provided number.";
        return false;
    }
    return true;
}

// dodaj wypozyczenie
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
        qDebug() << "Error adding rental:" << query.lastError().text();
        return false;
    }

    // ustaw pokoj jako niedostepny
    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE rooms SET is_available = false WHERE room_number = :room_number");
    updateQuery.bindValue(":room_number", rental.getRoomNumber());

    if (!updateQuery.exec()) {
        qDebug() << "Error updating room availability:" << updateQuery.lastError().text();
        return false;
    }

    return true;
}

// usun wypozyczenie
bool Database::removeRental(int rentalId) {
    QSqlQuery query;
    query.prepare("DELETE FROM rentals WHERE rental_id = :id");
    query.bindValue(":id", rentalId);

    if (!query.exec()) {
        qDebug() << "Error deleting rental:" << query.lastError().text();
        return false;
    }
    if (query.numRowsAffected() == 0) {
        qDebug() << "No rental found with the provided ID.";
        return false;
    }
    return true;
}

// wyszukiwanie rekordu po wartosci kolumny
QString Database::searchRecord(const QString& table, const QString& column, const QString& value) {
    QSqlQuery query(db);
    QString sql = QString("SELECT * FROM %1 WHERE %2 = :value").arg(table, column);
    query.prepare(sql);
    query.bindValue(":value", value);

    if (!query.exec()) {
        return "Query error: " + query.lastError().text();
    }

    if (query.next()) {
        QString result;
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); ++i) {
            result += record.fieldName(i) + ": " + query.value(i).toString() + "\n";
        }
        return result.trimmed();
    } else {
        return "Record not found.";
    }
}

// aktualizuje status dostepnosci pokoi na podstawie rezerwacji
void Database::updateRoomsAvailability() {
    QSqlQuery q1(db), q2(db);
    q1.exec(R"(
        UPDATE rooms SET is_available = FALSE
        WHERE room_number IN (
            SELECT room_number FROM rentals
            WHERE CURRENT_DATE >= check_in_date AND CURRENT_DATE < check_out_date
        )
    )");
    q2.exec(R"(
        UPDATE rooms SET is_available = TRUE
        WHERE room_number NOT IN (
            SELECT room_number FROM rentals
            WHERE CURRENT_DATE >= check_in_date AND CURRENT_DATE < check_out_date
        )
    )");
}




// pobierz zakresy zajetych terminow dla pokoju (do kalendarza)
QList<QPair<QDate, QDate>> Database::getReservedRangesForRoom(int roomNumber)
{
    QList<QPair<QDate, QDate>> ranges;
    QSqlQuery query(db);
    query.prepare("SELECT check_in_date, check_out_date FROM rentals WHERE room_number = :room_number");
    query.bindValue(":room_number", roomNumber);
    if (query.exec()) {
        while (query.next()) {
            QDate from = query.value(0).toDate();
            QDate to = query.value(1).toDate().addDays(-1); // dzien wymeldowania nie jest zajety
            ranges.append(qMakePair(from, to));
        }
    }
    return ranges;
}

