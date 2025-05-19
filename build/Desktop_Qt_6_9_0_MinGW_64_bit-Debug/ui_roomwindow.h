/********************************************************************************
** Form generated from reading UI file 'roomwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMWINDOW_H
#define UI_ROOMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_roomwindow
{
public:
    QWidget *centralwidget;
    QTableView *tableViewRooms;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *roomwindow)
    {
        if (roomwindow->objectName().isEmpty())
            roomwindow->setObjectName("roomwindow");
        roomwindow->resize(800, 600);
        centralwidget = new QWidget(roomwindow);
        centralwidget->setObjectName("centralwidget");
        tableViewRooms = new QTableView(centralwidget);
        tableViewRooms->setObjectName("tableViewRooms");
        tableViewRooms->setGeometry(QRect(10, 30, 661, 321));
        roomwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(roomwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        roomwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(roomwindow);
        statusbar->setObjectName("statusbar");
        roomwindow->setStatusBar(statusbar);

        retranslateUi(roomwindow);

        QMetaObject::connectSlotsByName(roomwindow);
    } // setupUi

    void retranslateUi(QMainWindow *roomwindow)
    {
        roomwindow->setWindowTitle(QCoreApplication::translate("roomwindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roomwindow: public Ui_roomwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMWINDOW_H
