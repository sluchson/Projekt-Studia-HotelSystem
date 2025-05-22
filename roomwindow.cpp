#include "roomwindow.h"
#include "ui_roomwindow.h"
#include "database.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QTextCharFormat>
#include <QCalendarWidget>

extern Database db;

roomwindow::roomwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::roomwindow)
{
    ui->setupUi(this);
    setWindowTitle("Hotel System - Rooms");
    ui->tableViewRooms->setModel(db.getRoomsModel());

    // obsluga klikniecia na wiersz tabeli pokoi
    connect(ui->tableViewRooms, &QTableView::clicked, this, &roomwindow::handleRoomRowClick);
    ui->tableViewRooms->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewRooms->setSortingEnabled(true);

    // filtrowanie po numerze pokoju i cenie
    connect(ui->lineEdit_searchRoomNumber, &QLineEdit::textChanged, this, &roomwindow::applyFilters);
    connect(ui->doubleSpinBox_priceFrom, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &roomwindow::applyFilters);
    connect(ui->doubleSpinBox_priceTo, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &roomwindow::applyFilters);

    // filtrowanie po statusie pokoju
    ui->comboBox_status->addItem("All");
    ui->comboBox_status->addItem("Available");
    ui->comboBox_status->addItem("Occupied");
    connect(ui->comboBox_status, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &roomwindow::applyFilters);
}

roomwindow::~roomwindow()
{
    delete ui;
}

// odswieza tabele pokoi po zmianach
void roomwindow::refreshRoomTable()
{
    static_cast<QSqlTableModel*>(ui->tableViewRooms->model())->select();
}

// wyswietla szczegoly pokoju i wypozyczen
void roomwindow::displayRoomDetails(QWidget *parent, const QString& roomNumber)
{
    QString roomInfo = db.searchRecord("rooms", "room_number", roomNumber);

    QString rentalInfo;
    QSqlQuery query;
    query.prepare("SELECT rental_id, client_id, check_in_date, check_out_date FROM rentals WHERE room_number = :room_number");
    query.bindValue(":room_number", roomNumber);

    if (query.exec()) {
        while (query.next()) {
            rentalInfo += "— Rental #" + query.value("rental_id").toString() +
                          ", client ID: " + query.value("client_id").toString() +
                          ", from: " + query.value("check_in_date").toString() +
                          ", to: " + query.value("check_out_date").toString() + "\n";
        }
    }

    QString fullInfo = roomInfo;

    if (!rentalInfo.isEmpty()) {
        fullInfo += "\n\nRoom rentals:\n" + rentalInfo.trimmed();
    } else if (!roomInfo.contains("Not found")) {
        fullInfo += "\n\nThis room has no assigned rentals.";
    }

    QMessageBox::information(parent, "Search result", fullInfo);
}

// obsluga klikniecia wiersza tabeli - pokazuje szczegoly i podswietla zajete dni
void roomwindow::handleRoomRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString roomNumber = ui->tableViewRooms->model()->data(ui->tableViewRooms->model()->index(index.row(), 0)).toString();
    roomwindow::displayRoomDetails(this, roomNumber);

    // podswietlanie zajetych dni w kalendarzu
    highlightReservedDates(roomNumber.toInt());
}

// filtrowanie pokojow po numerze, cenie i statusie
void roomwindow::applyFilters()
{
    QString roomPattern = ui->lineEdit_searchRoomNumber->text().trimmed();
    double priceFrom = ui->doubleSpinBox_priceFrom->value();
    double priceTo = ui->doubleSpinBox_priceTo->value();
    int statusIndex = ui->comboBox_status->currentIndex(); // 0: all, 1: available, 2: occupied

    QString filter;

    // filtr numeru pokoju
    if (!roomPattern.isEmpty()) {
        filter += QString("CAST(room_number AS TEXT) ILIKE '%%1%%'").arg(roomPattern);
    }

    // filtr ceny
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

    // filtr statusu pokoju
    if (statusIndex == 1) { // tylko wolne
        if (!filter.isEmpty()) filter += " AND ";
        filter += "is_available = true";
    } else if (statusIndex == 2) { // tylko zajete
        if (!filter.isEmpty()) filter += " AND ";
        filter += "is_available = false";
    }

    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewRooms->model());
    model->setFilter(filter);
}

// kolorowanie zajetych dni w kalendarzu dla wybranego pokoju
void roomwindow::highlightReservedDates(int roomNumber)
{
    // wyczysc wszystkie formatowania kalendarza
    ui->calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

    // pobierz zakresy zajetych dat dla pokoju
    QList<QPair<QDate, QDate>> reservedRanges = db.getReservedRangesForRoom(roomNumber);

    QTextCharFormat reservedFormat;
    reservedFormat.setBackground(Qt::red);
    reservedFormat.setForeground(Qt::white);

    // kolorowanie zajetych dni
    for (const auto& range : reservedRanges) {
        for (QDate d = range.first; d <= range.second; d = d.addDays(1)) {
            ui->calendarWidget->setDateTextFormat(d, reservedFormat);
        }
    }
}
