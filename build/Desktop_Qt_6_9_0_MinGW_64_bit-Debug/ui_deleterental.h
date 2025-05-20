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
        tableViewRentalToDelete->setGeometry(QRect(30, 30, 731, 411));
        deleterental->setCentralWidget(centralwidget);
        menubar = new QMenuBar(deleterental);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
    } // retranslateUi

};

namespace Ui {
    class deleterental: public Ui_deleterental {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETERENTAL_H
