#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QMainWindow>

namespace Ui {
class addclient;
}

class addclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit addclient(QWidget *parent = nullptr);
    ~addclient();

private:
    Ui::addclient *ui;

private slots:
    void on_addButton_clicked();

signals:
    void clientAdded();

};

#endif // ADDCLIENT_H
