#include "rental.h"

Rental::Rental(int clientId, int roomNumber, const QDate &checkInDate, const QDate &checkOutDate, double totalPrice)
    : clientId(clientId), roomNumber(roomNumber), checkInDate(checkInDate), checkOutDate(checkOutDate),totalPrice(totalPrice)
{}

int Rental::getRentalId() const
{
    return rentalId;
}

int Rental::getClientId() const
{
    return clientId;
}

int Rental::getRoomNumber() const
{
    return roomNumber;
}

QDate Rental::getCheckInDate() const
{
    return checkInDate;
}

QDate Rental::getCheckOutDate() const
{
    return checkOutDate;
}

double Rental::getTotalPrice() const
{
    return totalPrice;
}
