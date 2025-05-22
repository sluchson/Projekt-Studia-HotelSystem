#include "addclient.h"
#include "ui_addclient.h"
#include "client.h"
#include "database.h"
#include <QMessageBox>
#include <QRegularExpression>

extern Database db;

addclient::addclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addclient)
{
    ui->setupUi(this);
}

addclient::~addclient()
{
    delete ui;
}

// funkcja wywolywana po kliknieciu przycisku dodaj
void addclient::on_addButton_clicked()
{
    // pobieranie danych z pol tekstowych
    QString first_name = ui->firstNameEdit->text().trimmed();
    QString last_name = ui->lastNameEdit->text().trimmed();
    QString email = ui->emailEdit->text().trimmed();
    QString phone = ui->phoneEdit->text().trimmed();

    // sprawdz czy wszystkie pola sa wypelnione
    if (first_name.isEmpty() || last_name.isEmpty() || email.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "Error", "All fields must be filled in.");
        return;
    }

    // walidacja imienia (wielka litera, tylko litery)
    QRegularExpression nameRegex(R"(^[A-ZĄĆĘŁŃÓŚŹŻ][a-ząćęłńóśźż]+$)");
    if (!nameRegex.match(first_name).hasMatch()) {
        QMessageBox::warning(this, "Error", "The first name must start with a capital letter and contain only letters.");
        return;
    }

    // walidacja nazwiska (wielka litera, tylko litery, dopuszcza podwojne nazwiska)
    QRegularExpression lastnameRegex(R"(^[A-ZĄĆĘŁŃÓŚŹŻ][a-ząćęłńóśźż]+(-[A-ZĄĆĘŁŃÓŚŹŻ][a-ząćęłńóśźż]+)?$)");
    if (!lastnameRegex.match(last_name).hasMatch()) {
        QMessageBox::warning(this, "Error", "The last name must start with a capital letter and contain only letters.");
        return;
    }

    // walidacja adresu e-mail
    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Error", "Please enter a valid email address.");
        return;
    }

    // walidacja numeru telefonu (min 9 cyfr, tylko cyfry)
    QRegularExpression phoneRegex(R"(^\d{9,}$)");
    if (!phoneRegex.match(phone).hasMatch()) {
        QMessageBox::warning(this, "Error", "The phone number should contain at least 9 digits.");
        return;
    }

    // dodanie klienta do bazy danych
    Client newClient(first_name, last_name, email, phone);
    if (db.addClient(newClient)) {
        QMessageBox::information(this, "Success", "Client added.");
        emit clientAdded();
        this->close();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add the client.");
    }
}
