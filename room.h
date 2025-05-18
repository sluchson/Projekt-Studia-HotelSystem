#ifndef ROOM_H
#define ROOM_H

#include <QString>

class Room
{
public:
    Room(int number, const QString &type,
         double pricePerNight, bool isAvailable);

    int getNumber() const;
    QString getType() const;
    double getPricePerNight() const;
    bool isAvailable() const;

private:
    int number;
    QString type;
    double pricePerNight;
    bool available;
};

#endif // ROOM_H
