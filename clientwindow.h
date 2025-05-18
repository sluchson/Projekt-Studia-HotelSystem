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

private:
    Ui::clientwindow *ui;
};

#endif // CLIENTWINDOW_H
