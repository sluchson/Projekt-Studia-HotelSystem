#include "client.h"

Client::Client(const QString &firstName, const QString &lastName, const QString &email, const QString &phoneNumber)
    : firstName(firstName), lastName(lastName), email(email), phoneNumber(phoneNumber)
{}


int Client::getId() const { return id; }

QString Client::getFirstName() const { return firstName; }

QString Client::getLastName() const { return lastName; }

QString Client::getEmail() const { return email; }

QString Client::getPhoneNumber() const { return phoneNumber; }
