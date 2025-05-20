#ifndef DELETECLIENT_H
#define DELETECLIENT_H
#include <QSqlTableModel>
#include <QMainWindow>

namespace Ui {
class deleteclient;
}

class deleteclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteclient(QWidget *parent = nullptr);
    ~deleteclient();

private:
    Ui::deleteclient *ui;
    QSqlTableModel *clientsModel;

private slots:
    void handleRowClick(const QModelIndex &index);
};

#endif // DELETECLIENT_H
