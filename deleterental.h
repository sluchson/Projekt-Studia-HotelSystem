#ifndef DELETERENTAL_H
#define DELETERENTAL_H

#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class deleterental;
}

class deleterental : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleterental(QWidget *parent = nullptr);
    ~deleterental();

private slots:
    void handleRowClick(const QModelIndex &index);

private:
    Ui::deleterental *ui;
    QSqlTableModel *rentalsModel;
};

#endif // DELETERENTAL_H
