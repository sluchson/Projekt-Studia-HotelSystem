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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rentalwindow
{
public:
    QWidget *centralwidget;
    QTableView *tableViewRentals;
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
        tableViewRentals->setGeometry(QRect(10, 20, 571, 511));
        rentalwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(rentalwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
    } // retranslateUi

};

namespace Ui {
    class rentalwindow: public Ui_rentalwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENTALWINDOW_H
