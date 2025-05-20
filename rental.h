#ifndef RENTAL_H
#define RENTAL_H

#include <QString>
#include <QDate>

class Rental
{
public:
    Rental(int rentalId, int clientId, int roomNumber,
           const QDate &checkInDate, const QDate &checkOutDate, double totalPrice);

    // Konstruktor bez rentalId – do dodawania nowego wypożyczenia
    Rental(int clientId, int roomNumber,
           const QDate &checkInDate,
           const QDate &checkOutDate, double totalPrice);

    int getRentalId() const;
    int getClientId() const;
    int getRoomNumber() const;
    QDate getCheckInDate() const;
    QDate getCheckOutDate() const;
    double getTotalPrice() const;

private:
    int rentalId;
    int clientId;
    int roomNumber;
    QDate checkInDate;
    QDate checkOutDate;
    double totalPrice;
};

#endif // RENTAL_H
