#ifndef DELETERENTAL_H
#define DELETERENTAL_H

#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class deleterental;
}

class deleterental : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleterental(QWidget *parent = nullptr);
    ~deleterental();
    bool deleteRentalById(const QString& rentalId);


private:
    Ui::deleterental *ui;
    QSqlTableModel *rentalsModel;

private slots:
    void handleRowClick(const QModelIndex &index);

    void applyCombinedFilter();
    void on_lineEdit_searchRental_textChanged(const QString &);
    void on_dateEdit_from_dateChanged(const QDate &);

signals:
    void rentalDeleted();  // sygnał informujący o usunięciu klienta
};

#endif // DELETERENTAL_H
