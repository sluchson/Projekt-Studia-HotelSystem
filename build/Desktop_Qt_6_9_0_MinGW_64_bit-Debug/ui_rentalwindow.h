/********************************************************************************
** Form generated from reading UI file 'rentalwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENTALWINDOW_H
#define UI_RENTALWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
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
    QLineEdit *lineEdit_searchRental;
    QPushButton *pushButton_searchRental;
    QLabel *labelClients;
    QDateEdit *dateEdit_from;
    QLabel *label_3;
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
        lineEdit_searchRental = new QLineEdit(centralwidget);
        lineEdit_searchRental->setObjectName("lineEdit_searchRental");
        lineEdit_searchRental->setGeometry(QRect(280, 30, 251, 31));
        pushButton_searchRental = new QPushButton(centralwidget);
        pushButton_searchRental->setObjectName("pushButton_searchRental");
        pushButton_searchRental->setGeometry(QRect(530, 30, 83, 31));
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(20, 10, 181, 41));
        QFont font;
        font.setPointSize(24);
        labelClients->setFont(font);
        dateEdit_from = new QDateEdit(centralwidget);
        dateEdit_from->setObjectName("dateEdit_from");
        dateEdit_from->setGeometry(QRect(650, 30, 110, 25));
        dateEdit_from->setDate(QDate(2025, 1, 1));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(650, 10, 49, 16));
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
        label_3->setText(QCoreApplication::translate("rentalwindow", "From:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rentalwindow: public Ui_rentalwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENTALWINDOW_H
