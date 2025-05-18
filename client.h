#ifndef CLIENT_H
#define CLIENT_H

#include <QString>

class Client
{
public:
    Client(int id, const QString &firstName, const QString &lastName,
           const QString &email, const QString &phoneNumber);

    int getId() const;
    QString getFirstName() const;
    QString getLastName() const;
    QString getEmail() const;
    QString getPhoneNumber() const;

private:
    int id;
    QString firstName;
    QString lastName;
    QString email;
    QString phoneNumber;
};

#endif // CLIENT_H
