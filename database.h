// database.h

#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
#include <QPair>
#include <QDate>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include "client.h"
#include "room.h"
#include "rental.h"

class Database
{
public:
    Database();
    bool openConnection();
    void closeConnection();

    QSqlDatabase& getDatabase();

    QSqlTableModel* getClientsModel();
    QSqlTableModel* getRentalsModel();
    QSqlTableModel* getRoomsModel();

    bool addClient(const Client& client);
    bool removeClient(int clientId);

    bool addRoom(const Room& room);
    bool removeRoom(int number);

    bool addRental(const Rental& rental);
    bool removeRental(int rentalId);

    QString searchRecord(const QString& table, const QString& column, const QString& value);

    void updateRoomsAvailability();

    QList<QPair<QDate, QDate>> getReservedRangesForRoom(int roomNumber); 

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
