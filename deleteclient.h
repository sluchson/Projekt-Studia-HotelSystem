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
    bool deleteClientById(const QString& clientId);

private slots:
    void handleRowClick(const QModelIndex &index);
    void on_lineEdit_searchClient_textChanged(const QString &text);

signals:
    void clientDeleted();  // sygnał informujący o usunięciu klienta

};

#endif // DELETECLIENT_H
