#include "addclient.h"
#include "ui_addclient.h"
#include "client.h"
#include "database.h"
#include <QMessageBox>

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

    QString firstName = ui->firstNameEdit->text();
    QString lastName = ui->lastNameEdit->text();
    QString email = ui->emailEdit->text();
    QString phone = ui->phoneEdit->text();

    if (firstName.isEmpty() || lastName.isEmpty() || email.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione.");
        return;
    }

    Client newClient(firstName, lastName, email, phone);
    if (db.addClient(newClient)) {
        QMessageBox::information(this, "Sukces", "Dodano klienta.");
        emit clientAdded();  // powiadamia clientwindow o dodaniu
        this->close();       // zamyka formularz
    } else {
        QMessageBox::critical(this, "Błąd", "Nie udało się dodać klienta.");
    }
}
