#ifndef ROOMWINDOW_H
#define ROOMWINDOW_H

#include <QMainWindow>

namespace Ui {
class roomwindow;
}

class roomwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit roomwindow(QWidget *parent = nullptr);
    ~roomwindow();
    static void displayRoomDetails(QWidget *parent, const QString& roomNumber);

private:
    Ui::roomwindow *ui;

private slots:
    void on_pushButton_searchRoom_clicked();
    void handleRoomRowClick(const QModelIndex &index);


    void on_pushButtonRefresh_clicked();
};

#endif // ROOMWINDOW_H
