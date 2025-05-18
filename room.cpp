#include "room.h"

Room::Room(int number, const QString &type, double pricePerNight, bool isAvailable)
    : number(number), type(type), pricePerNight(pricePerNight), available(isAvailable)
{}

int Room::getNumber() const { return number; }
QString Room::getType() const { return type; }
double Room::getPricePerNight() const { return pricePerNight; }
bool Room::isAvailable() const { return available; }
