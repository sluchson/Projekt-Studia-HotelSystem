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
        tableViewClientToDelete->setGeometry(QRect(20, 20, 731, 401));
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
    } // retranslateUi

};

namespace Ui {
    class deleteclient: public Ui_deleteclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECLIENT_H
