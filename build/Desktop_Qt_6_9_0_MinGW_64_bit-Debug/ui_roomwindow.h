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
#include <QtWidgets/QDoubleSpinBox>
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
    QDoubleSpinBox *doubleSpinBox_priceFrom;
    QDoubleSpinBox *doubleSpinBox_priceTo;
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
        doubleSpinBox_priceFrom = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_priceFrom->setObjectName("doubleSpinBox_priceFrom");
        doubleSpinBox_priceFrom->setGeometry(QRect(660, 70, 101, 25));
        doubleSpinBox_priceFrom->setDecimals(4);
        doubleSpinBox_priceFrom->setMaximum(9999.989999999999782);
        doubleSpinBox_priceFrom->setSingleStep(5.000000000000000);
        doubleSpinBox_priceTo = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_priceTo->setObjectName("doubleSpinBox_priceTo");
        doubleSpinBox_priceTo->setGeometry(QRect(660, 120, 101, 25));
        doubleSpinBox_priceTo->setDecimals(4);
        doubleSpinBox_priceTo->setMaximum(9999.989999999999782);
        doubleSpinBox_priceTo->setSingleStep(5.000000000000000);
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
    } // retranslateUi

};

namespace Ui {
    class roomwindow: public Ui_roomwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMWINDOW_H
