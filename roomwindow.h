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
    void refreshRoomTable();


private:
    Ui::roomwindow *ui;
    void applyFilters();
    void highlightReservedDates(int roomNumber);

private slots:
    void handleRoomRowClick(const QModelIndex &index);

};

#endif // ROOMWINDOW_H
