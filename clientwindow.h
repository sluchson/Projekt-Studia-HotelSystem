#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class clientwindow;
}

class clientwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = nullptr);
    ~clientwindow();
    static void displayClientDetails(QWidget *parent, const QString& clientId);

private slots:
    void on_pushButtonAddClient_clicked();

    void on_pushButtonDeleteClient_clicked();

    void on_pushButton_searchClient_clicked();

    void handleClientRowClick(const QModelIndex &index);

    void on_pushButtonRefresh_clicked();

private:
    Ui::clientwindow *ui;
};

#endif // CLIENTWINDOW_H
