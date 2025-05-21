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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_roomwindow
{
public:
    QWidget *centralwidget;
    QTableView *tableViewRooms;
    QLineEdit *lineEdit_searchRoomNumber;
    QPushButton *pushButton_searchRoom;
    QLabel *labelClients;
    QPushButton *pushButtonRefresh;
    QLabel *label;
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
        tableViewRooms->setGeometry(QRect(20, 70, 621, 401));
        lineEdit_searchRoomNumber = new QLineEdit(centralwidget);
        lineEdit_searchRoomNumber->setObjectName("lineEdit_searchRoomNumber");
        lineEdit_searchRoomNumber->setGeometry(QRect(280, 30, 251, 31));
        pushButton_searchRoom = new QPushButton(centralwidget);
        pushButton_searchRoom->setObjectName("pushButton_searchRoom");
        pushButton_searchRoom->setGeometry(QRect(530, 30, 83, 31));
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(20, 10, 181, 41));
        QFont font;
        font.setPointSize(24);
        labelClients->setFont(font);
        pushButtonRefresh = new QPushButton(centralwidget);
        pushButtonRefresh->setObjectName("pushButtonRefresh");
        pushButtonRefresh->setGeometry(QRect(610, 30, 31, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 10, 101, 16));
        roomwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(roomwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        pushButton_searchRoom->setText(QCoreApplication::translate("roomwindow", "Search", nullptr));
        labelClients->setText(QCoreApplication::translate("roomwindow", "ROOMS", nullptr));
        pushButtonRefresh->setText(QCoreApplication::translate("roomwindow", "\342\231\273\357\270\217", nullptr));
        label->setText(QCoreApplication::translate("roomwindow", "Search room by id:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roomwindow: public Ui_roomwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMWINDOW_H
