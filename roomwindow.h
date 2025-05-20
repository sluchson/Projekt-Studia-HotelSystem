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

private slots:
    void on_pushButton_searchRoom_clicked();

private:
    Ui::roomwindow *ui;
};

#endif // ROOMWINDOW_H
