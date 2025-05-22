/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ClientsButton;
    QPushButton *RoomsButton;
    QPushButton *RentalsButton;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(801, 600);
        MainWindow->setMaximumSize(QSize(801, 600));
        MainWindow->setMouseTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ClientsButton = new QPushButton(centralwidget);
        ClientsButton->setObjectName("ClientsButton");
        ClientsButton->setGeometry(QRect(180, 270, 111, 61));
        QFont font;
        font.setBold(true);
        ClientsButton->setFont(font);
        RoomsButton = new QPushButton(centralwidget);
        RoomsButton->setObjectName("RoomsButton");
        RoomsButton->setGeometry(QRect(340, 270, 111, 61));
        RoomsButton->setFont(font);
        RentalsButton = new QPushButton(centralwidget);
        RentalsButton->setObjectName("RentalsButton");
        RentalsButton->setGeometry(QRect(500, 270, 111, 61));
        RentalsButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 110, 411, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(true);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 220, 161, 16));
        label_2->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 801, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ClientsButton->setText(QCoreApplication::translate("MainWindow", "Clients", nullptr));
        RoomsButton->setText(QCoreApplication::translate("MainWindow", "Rooms", nullptr));
        RentalsButton->setText(QCoreApplication::translate("MainWindow", "Rentals", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hotel System", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Maciej Pere\305\233lucha -177139", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
