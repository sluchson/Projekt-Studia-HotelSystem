#include "deleterental.h"
#include "ui_deleterental.h"
#include "rentalwindow.h"
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


bool deleterental::deleteRentalById(const QString& rentalId)
{
    for (int row = 0; row < rentalsModel->rowCount(); ++row) {
        QString modelRentalId = rentalsModel->data(rentalsModel->index(row, 0)).toString();
        if (modelRentalId == rentalId) {
            if (!rentalsModel->removeRow(row)) {
                QMessageBox::warning(this, "Błąd", "Nie udało się usunąć wypożyczenia.");
                return false;
            }

            if (!rentalsModel->submitAll()) {
                QMessageBox::warning(this, "Błąd", "Nie udało się zapisać zmian:\n" + rentalsModel->lastError().text());
                rentalsModel->revertAll();
                return false;
            }

            return true;
        }
    }

    QMessageBox::warning(this, "Błąd", "Nie znaleziono wypożyczenia o podanym ID.");
    return false;
}


void deleterental::handleRowClick(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString rentalId = rentalsModel->data(rentalsModel->index(index.row(), 0)).toString(); // kol. 0 = rental_id

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Potwierdzenie",
        QString("Czy na pewno chcesz usunąć wypożyczenie #%1?").arg(rentalId),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (deleteRentalById(rentalId)) {
            QMessageBox::information(this, "Sukces", "Wypożyczenie zostało usunięte.");
        }
    }
}


void deleterental::on_pushButton_searchRental_clicked()
{
    QString rentalId = ui->lineEdit_searchRentalId->text().trimmed();
    if (rentalId.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wprowadź ID wypożyczenia do wyszukania.");
        return;
    }

    // Opcjonalnie: pokaż dane wypożyczenia
    rentalwindow::displayRentalDetails(this, rentalId);

    // Potwierdzenie usunięcia
    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Potwierdzenie usunięcia",
        "Czy chcesz usunąć to wypożyczenie?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (deleteRentalById(rentalId)) {
            QMessageBox::information(this, "Sukces", "Wypożyczenie zostało usunięte.");
        }
    }
}


void deleterental::on_pushButtonRefresh_clicked()
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableViewRentalToDelete->model());
    db.refreshExistingModel(model);
}

