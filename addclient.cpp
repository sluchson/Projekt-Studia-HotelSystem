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


void addclient::on_addButton_clicked()
{
    QString first_name = ui->firstNameEdit->text().trimmed();
    QString last_name = ui->lastNameEdit->text().trimmed();
    QString email = ui->emailEdit->text().trimmed();
    QString phone = ui->phoneEdit->text().trimmed();

    // 1. Sprawdź czy pola są puste
    if (first_name.isEmpty() || last_name.isEmpty() || email.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione.");
        return;
    }

    QRegularExpression nameRegex(R"(^[A-ZĄĆĘŁŃÓŚŹŻ][a-ząćęłńóśźż]+$)");
    if (!nameRegex.match(first_name).hasMatch()) {
        QMessageBox::warning(this, "Błąd", "Imię musi zaczynać się wielką literą i zawierać tylko litery.");
        return;
    }

    QRegularExpression lastnameRegex(R"(^[A-ZĄĆĘŁŃÓŚŹŻ][a-ząćęłńóśźż]+(-[A-ZĄĆĘŁŃÓŚŹŻ][a-ząćęłńóśźż]+)?$)");
    if (!lastnameRegex.match(last_name).hasMatch()) {
        QMessageBox::warning(this, "Błąd", "Nazwisko musi zaczynać się wielką literą i zawierać tylko litery.");
        return;
    }


    // 2. Walidacja e-maila
    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Błąd", "Podaj poprawny adres e-mail.");
        return;
    }

    // 3. Walidacja telefonu (minimum 9 cyfr, tylko cyfry, można rozwinąć)
    QRegularExpression phoneRegex(R"(^\d{9,}$)");
    if (!phoneRegex.match(phone).hasMatch()) {
        QMessageBox::warning(this, "Błąd", "Numer telefonu powinien zawierać co najmniej 9 cyfr.");
        return;
    }

    // Możesz tu dodać inne walidacje, np. na wielkość liter w imieniu/nazwisku

    // 4. Dodawanie klienta
    Client newClient(first_name, last_name, email, phone);
    if (db.addClient(newClient)) {
        QMessageBox::information(this, "Sukces", "Dodano klienta.");
        emit clientAdded();
        this->close();
    } else {
        QMessageBox::critical(this, "Błąd", "Nie udało się dodać klienta.");
    }
}
