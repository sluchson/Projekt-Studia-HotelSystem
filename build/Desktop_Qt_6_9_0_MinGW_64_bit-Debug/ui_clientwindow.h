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
        tableViewClients->setGeometry(QRect(10, 80, 771, 301));
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(10, 20, 161, 31));
        QFont font;
        font.setPointSize(28);
        labelClients->setFont(font);
        pushButtonAddClient = new QPushButton(centralwidget);
        pushButtonAddClient->setObjectName("pushButtonAddClient");
        pushButtonAddClient->setGeometry(QRect(310, 420, 131, 91));
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
    } // retranslateUi

};

namespace Ui {
    class clientwindow: public Ui_clientwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
