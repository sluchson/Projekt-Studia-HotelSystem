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
#include <QtWidgets/QPushButton>
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
    QLineEdit *lineEdit_searchClientId;
    QPushButton *pushButton_searchClient;
    QPushButton *pushButtonRefresh;
    QLabel *label;
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
        labelClients->setGeometry(QRect(20, 10, 251, 41));
        QFont font;
        font.setPointSize(24);
        labelClients->setFont(font);
        lineEdit_searchClientId = new QLineEdit(centralwidget);
        lineEdit_searchClientId->setObjectName("lineEdit_searchClientId");
        lineEdit_searchClientId->setGeometry(QRect(280, 30, 251, 31));
        pushButton_searchClient = new QPushButton(centralwidget);
        pushButton_searchClient->setObjectName("pushButton_searchClient");
        pushButton_searchClient->setGeometry(QRect(530, 30, 80, 31));
        pushButtonRefresh = new QPushButton(centralwidget);
        pushButtonRefresh->setObjectName("pushButtonRefresh");
        pushButtonRefresh->setGeometry(QRect(610, 30, 31, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 10, 161, 16));
        deleteclient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(deleteclient);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        pushButton_searchClient->setText(QCoreApplication::translate("deleteclient", "Search", nullptr));
        pushButtonRefresh->setText(QCoreApplication::translate("deleteclient", "\342\231\273\357\270\217", nullptr));
        label->setText(QCoreApplication::translate("deleteclient", "Search and delete client by id:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteclient: public Ui_deleteclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECLIENT_H
