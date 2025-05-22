/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

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

class Ui_clientwindow
{
public:
    QWidget *centralwidget;
    QTableView *tableViewClients;
    QLabel *labelClients;
    QPushButton *pushButtonAddClient;
    QPushButton *pushButtonDeleteClient;
    QLineEdit *lineEdit_searchClient;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *clientwindow)
    {
        if (clientwindow->objectName().isEmpty())
            clientwindow->setObjectName("clientwindow");
        clientwindow->setEnabled(true);
        clientwindow->resize(800, 600);
        centralwidget = new QWidget(clientwindow);
        centralwidget->setObjectName("centralwidget");
        tableViewClients = new QTableView(centralwidget);
        tableViewClients->setObjectName("tableViewClients");
        tableViewClients->setEnabled(true);
        tableViewClients->setGeometry(QRect(20, 70, 621, 401));
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(20, 10, 181, 41));
        QFont font;
        font.setPointSize(24);
        labelClients->setFont(font);
        pushButtonAddClient = new QPushButton(centralwidget);
        pushButtonAddClient->setObjectName("pushButtonAddClient");
        pushButtonAddClient->setGeometry(QRect(20, 490, 101, 61));
        pushButtonDeleteClient = new QPushButton(centralwidget);
        pushButtonDeleteClient->setObjectName("pushButtonDeleteClient");
        pushButtonDeleteClient->setGeometry(QRect(140, 490, 101, 61));
        lineEdit_searchClient = new QLineEdit(centralwidget);
        lineEdit_searchClient->setObjectName("lineEdit_searchClient");
        lineEdit_searchClient->setGeometry(QRect(390, 30, 251, 31));
        clientwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(clientwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        clientwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(clientwindow);
        statusbar->setObjectName("statusbar");
        clientwindow->setStatusBar(statusbar);

        retranslateUi(clientwindow);

        QMetaObject::connectSlotsByName(clientwindow);
    } // setupUi

    void retranslateUi(QMainWindow *clientwindow)
    {
        clientwindow->setWindowTitle(QCoreApplication::translate("clientwindow", "MainWindow", nullptr));
        labelClients->setText(QCoreApplication::translate("clientwindow", "CLIENTS", nullptr));
        pushButtonAddClient->setText(QCoreApplication::translate("clientwindow", "Add client", nullptr));
        pushButtonDeleteClient->setText(QCoreApplication::translate("clientwindow", "Delete client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientwindow: public Ui_clientwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
