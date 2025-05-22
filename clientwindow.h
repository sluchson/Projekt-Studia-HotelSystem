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

    void on_lineEdit_searchClient_textChanged(const QString &text);

    void handleClientRowClick(const QModelIndex &index);


private:
    Ui::clientwindow *ui;
};

#endif // CLIENTWINDOW_H
