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
    ui->tableViewRooms->setSortingEnabled(true);

    // Po wpisaniu tekstu do lineEdit
    connect(ui->lineEdit_searchRoomNumber, &QLineEdit::textChanged, this, &roomwindow::applyFilters);
    connect(ui->doubleSpinBox_priceFrom, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &roomwindow::applyFilters);
    connect(ui->doubleSpinBox_priceTo, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &roomwindow::applyFilters);

    ui->comboBox_status->addItem("All");
    ui->comboBox_status->addItem("Available");
    ui->comboBox_status->addItem("Occupied");
    connect(ui->comboBox_status, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &roomwindow::applyFilters);
}

roomwindow::~roomwindow()
{
    delete ui;
}

void roomwindow::refreshRoomTable()
{
    static_cast<QSqlTableModel*>(ui->tableViewRooms->model())->select();
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




void roomwindow::applyFilters()
{
    QString roomPattern = ui->lineEdit_searchRoomNumber->text().trimmed();
    double priceFrom = ui->doubleSpinBox_priceFrom->value();
    double priceTo = ui->doubleSpinBox_priceTo->value();
    int statusIndex = ui->comboBox_status->currentIndex(); // 0: Wszystkie, 1: Wolne, 2: Zajęte

    QString filter;

    // Numer pokoju
    if (!roomPattern.isEmpty()) {
        filter += QString("CAST(room_number AS TEXT) ILIKE '%%1%%'").arg(roomPattern);
    }

    // Cena
    if (priceFrom > 0 || priceTo > 0) {
        if (!filter.isEmpty()) filter += " AND ";
        if (priceFrom > 0 && priceTo > 0) {
            filter += QString("price_per_night BETWEEN %1 AND %2").arg(priceFrom).arg(priceTo);
        } else if (priceFrom > 0) {
            filter += QString("price_per_night >= %1").arg(priceFrom);
        } else if (priceTo > 0) {
            filter += QString("price_per_night <= %1").arg(priceTo);
        }
    }

    // Status pokoju
    if (statusIndex == 1) { // tylko wolne
        if (!filter.isEmpty()) filter += " AND ";
        filter += "is_available = true";
    } else if (statusIndex == 2) { // tylko zajęte
        if (!filter.isEmpty()) filter += " AND ";
        filter += "is_available = false";
    }

    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewRooms->model());
    model->setFilter(filter);
}

