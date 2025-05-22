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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLineEdit *lineEdit_searchRoomNumber;
    QLabel *labelClients;
    QDoubleSpinBox *doubleSpinBox_priceFrom;
    QDoubleSpinBox *doubleSpinBox_priceTo;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_status;
    QLabel *label_4;
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
        tableViewRooms->setGeometry(QRect(20, 70, 601, 401));
        lineEdit_searchRoomNumber = new QLineEdit(centralwidget);
        lineEdit_searchRoomNumber->setObjectName("lineEdit_searchRoomNumber");
        lineEdit_searchRoomNumber->setGeometry(QRect(220, 30, 251, 31));
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(20, 10, 181, 41));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(true);
        labelClients->setFont(font);
        doubleSpinBox_priceFrom = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_priceFrom->setObjectName("doubleSpinBox_priceFrom");
        doubleSpinBox_priceFrom->setGeometry(QRect(630, 30, 101, 31));
        doubleSpinBox_priceFrom->setDecimals(4);
        doubleSpinBox_priceFrom->setMaximum(9999.989999999999782);
        doubleSpinBox_priceFrom->setSingleStep(5.000000000000000);
        doubleSpinBox_priceTo = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_priceTo->setObjectName("doubleSpinBox_priceTo");
        doubleSpinBox_priceTo->setGeometry(QRect(630, 80, 101, 31));
        doubleSpinBox_priceTo->setDecimals(4);
        doubleSpinBox_priceTo->setMaximum(9999.989999999999782);
        doubleSpinBox_priceTo->setSingleStep(5.000000000000000);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 10, 191, 20));
        QFont font1;
        font1.setBold(true);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(630, 10, 101, 20));
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(630, 60, 101, 21));
        label_3->setFont(font1);
        comboBox_status = new QComboBox(centralwidget);
        comboBox_status->setObjectName("comboBox_status");
        comboBox_status->setGeometry(QRect(490, 30, 121, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(490, 10, 101, 20));
        label_4->setFont(font1);
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
        labelClients->setText(QCoreApplication::translate("roomwindow", "ROOMS", nullptr));
        label->setText(QCoreApplication::translate("roomwindow", "Search by room number:", nullptr));
        label_2->setText(QCoreApplication::translate("roomwindow", "Price from:", nullptr));
        label_3->setText(QCoreApplication::translate("roomwindow", "to:", nullptr));
        label_4->setText(QCoreApplication::translate("roomwindow", "Status:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roomwindow: public Ui_roomwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMWINDOW_H
