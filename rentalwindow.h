#ifndef RENTALWINDOW_H
#define RENTALWINDOW_H

#include <QMainWindow>

namespace Ui {
class rentalwindow;
}

class rentalwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit rentalwindow(QWidget *parent = nullptr);
    ~rentalwindow();
    static void displayRentalDetails(QWidget *parent, const QString& rentalId);

private:
    Ui::rentalwindow *ui;


private slots:
    void on_pushButtonAddRental_clicked();

    void on_pushButtonDeleteRental_clicked();

    void on_lineEdit_searchRental_textChanged(const QString &text);

    void on_dateEdit_from_dateChanged(const QDate &date);

    void applyCombinedFilter();

    void handleRentalRowClick(const QModelIndex &index);


};
#endif // RENTALWINDOW_H
