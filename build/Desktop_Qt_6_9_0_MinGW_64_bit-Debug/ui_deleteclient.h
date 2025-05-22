/********************************************************************************
** Form generated from reading UI file 'deleteclient.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETECLIENT_H
#define UI_DELETECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteclient
{
public:
    QWidget *centralwidget;
    QTableView *tableViewClientToDelete;
    QLabel *labelClients;
    QLineEdit *lineEdit_searchClient;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *deleteclient)
    {
        if (deleteclient->objectName().isEmpty())
            deleteclient->setObjectName("deleteclient");
        deleteclient->resize(800, 600);
        centralwidget = new QWidget(deleteclient);
        centralwidget->setObjectName("centralwidget");
        tableViewClientToDelete = new QTableView(centralwidget);
        tableViewClientToDelete->setObjectName("tableViewClientToDelete");
        tableViewClientToDelete->setGeometry(QRect(20, 70, 621, 401));
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(20, 10, 291, 41));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(true);
        labelClients->setFont(font);
        lineEdit_searchClient = new QLineEdit(centralwidget);
        lineEdit_searchClient->setObjectName("lineEdit_searchClient");
        lineEdit_searchClient->setGeometry(QRect(390, 30, 251, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(390, 10, 211, 16));
        QFont font1;
        font1.setBold(true);
        label_4->setFont(font1);
        deleteclient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(deleteclient);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        deleteclient->setMenuBar(menubar);
        statusbar = new QStatusBar(deleteclient);
        statusbar->setObjectName("statusbar");
        deleteclient->setStatusBar(statusbar);

        retranslateUi(deleteclient);

        QMetaObject::connectSlotsByName(deleteclient);
    } // setupUi

    void retranslateUi(QMainWindow *deleteclient)
    {
        deleteclient->setWindowTitle(QCoreApplication::translate("deleteclient", "MainWindow", nullptr));
        labelClients->setText(QCoreApplication::translate("deleteclient", "DELETE CLIENT", nullptr));
        label_4->setText(QCoreApplication::translate("deleteclient", "Search by name or surrname:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteclient: public Ui_deleteclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECLIENT_H
