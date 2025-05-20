#include "deleterental.h"
#include "ui_deleterental.h"
#include "database.h"
#include <QMessageBox>
#include <QSqlError>

extern Database db;

deleterental::deleterental(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deleterental)
{
    ui->setupUi(this);
    rentalsModel = db.getRentalsModel();
    ui->tableViewRentalToDelete->setModel(rentalsModel);

    connect(ui->tableViewRentalToDelete, &QTableView::clicked, this, &deleterental::handleRowClick);

}

deleterental::~deleterental()
{
    delete ui;
}


void deleterental::handleRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    int row = index.row();
    QString rentalId = rentalsModel->data(rentalsModel->index(row, 0)).toString(); // zakładamy: kol. 0 = rental_id

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Potwierdzenie",
        "Czy na pewno chcesz usunąć wypożyczenie?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (!rentalsModel->removeRow(row)) {
            QMessageBox::warning(this, "Błąd", "Nie udało się usunąć wiersza z modelu.");
            return;
        }

        if (!rentalsModel->submitAll()) {
            QMessageBox::warning(this, "Błąd", "Nie udało się zapisać zmian:\n" + rentalsModel->lastError().text());
            rentalsModel->revertAll();
            return;
        }

        QMessageBox::information(this, "Sukces", "Wypożyczenie zostało usunięte.");
    }
}
