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

private slots:
    void on_pushButtonAddRental_clicked();

    void on_pushButtonDeleteRental_clicked();

     void on_pushButton_searchRental_clicked();

private:
    Ui::rentalwindow *ui;
};

#endif // RENTALWINDOW_H
