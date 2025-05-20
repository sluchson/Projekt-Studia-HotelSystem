/********************************************************************************
** Form generated from reading UI file 'addrental.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRENTAL_H
#define UI_ADDRENTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addrental
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_add_rental;
    QComboBox *comboBox_client;
    QDateEdit *dateEdit_checkin;
    QDateEdit *dateEdit_checkout;
    QComboBox *comboBox_room;
    QLineEdit *lineEdit_price;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *addrental)
    {
        if (addrental->objectName().isEmpty())
            addrental->setObjectName("addrental");
        addrental->resize(800, 600);
        centralwidget = new QWidget(addrental);
        centralwidget->setObjectName("centralwidget");
        pushButton_add_rental = new QPushButton(centralwidget);
        pushButton_add_rental->setObjectName("pushButton_add_rental");
        pushButton_add_rental->setGeometry(QRect(320, 410, 141, 81));
        comboBox_client = new QComboBox(centralwidget);
        comboBox_client->setObjectName("comboBox_client");
        comboBox_client->setGeometry(QRect(300, 60, 201, 31));
        dateEdit_checkin = new QDateEdit(centralwidget);
        dateEdit_checkin->setObjectName("dateEdit_checkin");
        dateEdit_checkin->setGeometry(QRect(330, 200, 110, 29));
        dateEdit_checkout = new QDateEdit(centralwidget);
        dateEdit_checkout->setObjectName("dateEdit_checkout");
        dateEdit_checkout->setGeometry(QRect(330, 260, 110, 29));
        comboBox_room = new QComboBox(centralwidget);
        comboBox_room->setObjectName("comboBox_room");
        comboBox_room->setGeometry(QRect(300, 120, 201, 31));
        lineEdit_price = new QLineEdit(centralwidget);
        lineEdit_price->setObjectName("lineEdit_price");
        lineEdit_price->setGeometry(QRect(330, 330, 113, 28));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 30, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 100, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(330, 180, 63, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(330, 240, 91, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(330, 310, 91, 20));
        addrental->setCentralWidget(centralwidget);
        menubar = new QMenuBar(addrental);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        addrental->setMenuBar(menubar);
        statusbar = new QStatusBar(addrental);
        statusbar->setObjectName("statusbar");
        addrental->setStatusBar(statusbar);

        retranslateUi(addrental);

        QMetaObject::connectSlotsByName(addrental);
    } // setupUi

    void retranslateUi(QMainWindow *addrental)
    {
        addrental->setWindowTitle(QCoreApplication::translate("addrental", "MainWindow", nullptr));
        pushButton_add_rental->setText(QCoreApplication::translate("addrental", "Add rental", nullptr));
        label->setText(QCoreApplication::translate("addrental", "Client:", nullptr));
        label_2->setText(QCoreApplication::translate("addrental", "Room:", nullptr));
        label_3->setText(QCoreApplication::translate("addrental", "Check in:", nullptr));
        label_4->setText(QCoreApplication::translate("addrental", "Check out:", nullptr));
        label_5->setText(QCoreApplication::translate("addrental", "Total price:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addrental: public Ui_addrental {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRENTAL_H
