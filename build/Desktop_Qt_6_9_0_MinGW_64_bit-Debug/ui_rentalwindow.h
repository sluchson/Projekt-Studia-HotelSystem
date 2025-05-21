/********************************************************************************
** Form generated from reading UI file 'rentalwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENTALWINDOW_H
#define UI_RENTALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rentalwindow
{
public:
    QWidget *centralwidget;
    QTableView *tableViewRentals;
    QPushButton *pushButtonAddRental;
    QPushButton *pushButtonDeleteRental;
    QLineEdit *lineEdit_searchRentalId;
    QPushButton *pushButton_searchRental;
    QLabel *labelClients;
    QPushButton *pushButtonRefresh;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *rentalwindow)
    {
        if (rentalwindow->objectName().isEmpty())
            rentalwindow->setObjectName("rentalwindow");
        rentalwindow->resize(800, 600);
        centralwidget = new QWidget(rentalwindow);
        centralwidget->setObjectName("centralwidget");
        tableViewRentals = new QTableView(centralwidget);
        tableViewRentals->setObjectName("tableViewRentals");
        tableViewRentals->setGeometry(QRect(20, 70, 621, 401));
        pushButtonAddRental = new QPushButton(centralwidget);
        pushButtonAddRental->setObjectName("pushButtonAddRental");
        pushButtonAddRental->setGeometry(QRect(20, 490, 111, 61));
        pushButtonDeleteRental = new QPushButton(centralwidget);
        pushButtonDeleteRental->setObjectName("pushButtonDeleteRental");
        pushButtonDeleteRental->setGeometry(QRect(150, 490, 111, 61));
        lineEdit_searchRentalId = new QLineEdit(centralwidget);
        lineEdit_searchRentalId->setObjectName("lineEdit_searchRentalId");
        lineEdit_searchRentalId->setGeometry(QRect(280, 30, 251, 31));
        pushButton_searchRental = new QPushButton(centralwidget);
        pushButton_searchRental->setObjectName("pushButton_searchRental");
        pushButton_searchRental->setGeometry(QRect(530, 30, 83, 31));
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(20, 10, 181, 41));
        QFont font;
        font.setPointSize(24);
        labelClients->setFont(font);
        pushButtonRefresh = new QPushButton(centralwidget);
        pushButtonRefresh->setObjectName("pushButtonRefresh");
        pushButtonRefresh->setGeometry(QRect(610, 30, 31, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 10, 111, 16));
        rentalwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(rentalwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        rentalwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(rentalwindow);
        statusbar->setObjectName("statusbar");
        rentalwindow->setStatusBar(statusbar);

        retranslateUi(rentalwindow);

        QMetaObject::connectSlotsByName(rentalwindow);
    } // setupUi

    void retranslateUi(QMainWindow *rentalwindow)
    {
        rentalwindow->setWindowTitle(QCoreApplication::translate("rentalwindow", "MainWindow", nullptr));
        pushButtonAddRental->setText(QCoreApplication::translate("rentalwindow", "Add rental", nullptr));
        pushButtonDeleteRental->setText(QCoreApplication::translate("rentalwindow", "Delete rental", nullptr));
        pushButton_searchRental->setText(QCoreApplication::translate("rentalwindow", "Search", nullptr));
        labelClients->setText(QCoreApplication::translate("rentalwindow", "RENTALS", nullptr));
        pushButtonRefresh->setText(QCoreApplication::translate("rentalwindow", "\342\231\273\357\270\217", nullptr));
        label->setText(QCoreApplication::translate("rentalwindow", "Serach rental by id:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rentalwindow: public Ui_rentalwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENTALWINDOW_H
