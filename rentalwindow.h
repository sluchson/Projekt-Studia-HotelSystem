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

    void on_pushButton_searchRental_clicked();

    void handleRentalRowClick(const QModelIndex &index);

    void on_pushButtonRefresh_clicked();
};
#endif // RENTALWINDOW_H
