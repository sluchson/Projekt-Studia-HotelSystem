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

private:
    Ui::deleterental *ui;
    QSqlTableModel *rentalsModel;
    bool deleteRentalById(const QString& rentalId);

private slots:
    void handleRowClick(const QModelIndex &index);

    void on_pushButton_searchRental_clicked();


    void on_pushButtonRefresh_clicked();
};

#endif // DELETERENTAL_H
