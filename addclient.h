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

private slots:
    void on_addButton_clicked();

signals:
    void clientAdded();
private:
    Ui::addclient *ui;
};

#endif // ADDCLIENT_H
