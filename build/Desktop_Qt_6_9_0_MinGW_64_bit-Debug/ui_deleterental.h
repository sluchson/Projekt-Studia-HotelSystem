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

class Ui_deleterental
{
public:
    QWidget *centralwidget;
    QTableView *tableViewRentalToDelete;
    QLabel *labelClients;
    QLineEdit *lineEdit_searchRentalId;
    QPushButton *pushButton_searchRental;
    QPushButton *pushButtonRefresh;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *deleterental)
    {
        if (deleterental->objectName().isEmpty())
            deleterental->setObjectName("deleterental");
        deleterental->resize(800, 600);
        centralwidget = new QWidget(deleterental);
        centralwidget->setObjectName("centralwidget");
        tableViewRentalToDelete = new QTableView(centralwidget);
        tableViewRentalToDelete->setObjectName("tableViewRentalToDelete");
        tableViewRentalToDelete->setGeometry(QRect(20, 70, 621, 401));
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(20, 10, 271, 41));
        QFont font;
        font.setPointSize(24);
        labelClients->setFont(font);
        lineEdit_searchRentalId = new QLineEdit(centralwidget);
        lineEdit_searchRentalId->setObjectName("lineEdit_searchRentalId");
        lineEdit_searchRentalId->setGeometry(QRect(280, 30, 251, 31));
        pushButton_searchRental = new QPushButton(centralwidget);
        pushButton_searchRental->setObjectName("pushButton_searchRental");
        pushButton_searchRental->setGeometry(QRect(530, 30, 80, 31));
        pushButtonRefresh = new QPushButton(centralwidget);
        pushButtonRefresh->setObjectName("pushButtonRefresh");
        pushButtonRefresh->setGeometry(QRect(610, 30, 31, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 10, 161, 16));
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
        pushButton_searchRental->setText(QCoreApplication::translate("deleterental", "Search", nullptr));
        pushButtonRefresh->setText(QCoreApplication::translate("deleterental", "\342\231\273\357\270\217", nullptr));
        label->setText(QCoreApplication::translate("deleterental", "Search and delete rental by id:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleterental: public Ui_deleterental {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETERENTAL_H
