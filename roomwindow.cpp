#include "roomwindow.h"
#include "ui_roomwindow.h"
#include "database.h"
#include <QMessageBox>
#include <QSqlQuery>

extern Database db;

roomwindow::roomwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::roomwindow)
{
    ui->setupUi(this);
    ui->tableViewRooms->setModel(db.getRoomsModel());

    connect(ui->tableViewRooms, &QTableView::clicked, this, &roomwindow::handleRoomRowClick);
    ui->tableViewRooms->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

roomwindow::~roomwindow()
{
    delete ui;
}

void roomwindow::displayRoomDetails(QWidget *parent, const QString& roomNumber)
{
    QString roomInfo = db.searchRecord("rooms", "room_number", roomNumber);

    QString rentalInfo;
    QSqlQuery query;
    query.prepare("SELECT rental_id, client_id, check_in_date, check_out_date FROM rentals WHERE room_number = :room_number");
    query.bindValue(":room_number", roomNumber);

    if (query.exec()) {
        while (query.next()) {
            rentalInfo += "— Wypożyczenie #" + query.value("rental_id").toString() +
                          ", klient ID: " + query.value("client_id").toString() +
                          ", od: " + query.value("check_in_date").toString() +
                          ", do: " + query.value("check_out_date").toString() + "\n";
        }
    }

    QString fullInfo = roomInfo;

    if (!rentalInfo.isEmpty()) {
        fullInfo += "\n\nWypożyczenia pokoju:\n" + rentalInfo.trimmed();
    } else if (!roomInfo.contains("Nie znaleziono")) {
        fullInfo += "\n\nPokój nie ma przypisanych wypożyczeń.";
    }

    QMessageBox::information(parent, "Wynik wyszukiwania", fullInfo);
}

void roomwindow::on_pushButton_searchRoom_clicked()
{
    QString roomNumber = ui->lineEdit_searchRoomNumber->text().trimmed();
    if (roomNumber.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wprowadź numer pokoju do wyszukania.");
        return;
    }

    roomwindow::displayRoomDetails(this, roomNumber);
}


void roomwindow::handleRoomRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString roomNumber = ui->tableViewRooms->model()->data(ui->tableViewRooms->model()->index(index.row(), 0)).toString();
    roomwindow::displayRoomDetails(this, roomNumber);
}

void roomwindow::on_pushButtonRefresh_clicked()
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewRooms->model());
    db.refreshExistingModel(model);
}

