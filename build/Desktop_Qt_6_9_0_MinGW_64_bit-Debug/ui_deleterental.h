/********************************************************************************
** Form generated from reading UI file 'deleterental.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETERENTAL_H
#define UI_DELETERENTAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleterental
{
public:
    QWidget *centralwidget;
    QTableView *tableViewRentalToDelete;
    QLabel *labelClients;
    QLineEdit *lineEdit_searchRental;
    QDateEdit *dateEdit_from;
    QLabel *label_4;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *deleterental)
    {
        if (deleterental->objectName().isEmpty())
            deleterental->setObjectName("deleterental");
        deleterental->resize(800, 600);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        deleterental->setWindowIcon(icon);
        centralwidget = new QWidget(deleterental);
        centralwidget->setObjectName("centralwidget");
        tableViewRentalToDelete = new QTableView(centralwidget);
        tableViewRentalToDelete->setObjectName("tableViewRentalToDelete");
        tableViewRentalToDelete->setGeometry(QRect(20, 70, 621, 401));
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(20, 10, 311, 41));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(false);
        labelClients->setFont(font);
        lineEdit_searchRental = new QLineEdit(centralwidget);
        lineEdit_searchRental->setObjectName("lineEdit_searchRental");
        lineEdit_searchRental->setGeometry(QRect(390, 30, 251, 31));
        dateEdit_from = new QDateEdit(centralwidget);
        dateEdit_from->setObjectName("dateEdit_from");
        dateEdit_from->setGeometry(QRect(660, 30, 110, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(390, 10, 181, 16));
        QFont font1;
        font1.setBold(true);
        label_4->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(660, 10, 81, 16));
        label_3->setFont(font1);
        deleterental->setCentralWidget(centralwidget);
        menubar = new QMenuBar(deleterental);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        deleterental->setMenuBar(menubar);
        statusbar = new QStatusBar(deleterental);
        statusbar->setObjectName("statusbar");
        deleterental->setStatusBar(statusbar);

        retranslateUi(deleterental);

        QMetaObject::connectSlotsByName(deleterental);
    } // setupUi

    void retranslateUi(QMainWindow *deleterental)
    {
        deleterental->setWindowTitle(QCoreApplication::translate("deleterental", "MainWindow", nullptr));
        labelClients->setText(QCoreApplication::translate("deleterental", "DELETE RENTAL", nullptr));
        label_4->setText(QCoreApplication::translate("deleterental", "Search by id or client id:", nullptr));
        label_3->setText(QCoreApplication::translate("deleterental", "From date:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleterental: public Ui_deleterental {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETERENTAL_H
