#ifndef ADDRENTAL_H
#define ADDRENTAL_H

#include <QMainWindow>

namespace Ui {
class addrental;
}

class addrental : public QMainWindow
{
    Q_OBJECT

public:
    explicit addrental(QWidget *parent = nullptr);
    ~addrental();

private:
    Ui::addrental *ui;

private slots:
    void on_pushButton_add_rental_clicked();
    void updateTotalPrice();


signals:
    void rentalAdded();
};

#endif // ADDRENTAL_H
