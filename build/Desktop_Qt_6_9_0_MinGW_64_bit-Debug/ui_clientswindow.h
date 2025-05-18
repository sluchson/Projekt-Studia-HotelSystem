/********************************************************************************
** Form generated from reading UI file 'clientswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTSWINDOW_H
#define UI_CLIENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientswindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *clientswindow)
    {
        if (clientswindow->objectName().isEmpty())
            clientswindow->setObjectName("clientswindow");
        clientswindow->resize(800, 600);
        centralwidget = new QWidget(clientswindow);
        centralwidget->setObjectName("centralwidget");
        clientswindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(clientswindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        clientswindow->setMenuBar(menubar);
        statusbar = new QStatusBar(clientswindow);
        statusbar->setObjectName("statusbar");
        clientswindow->setStatusBar(statusbar);

        retranslateUi(clientswindow);

        QMetaObject::connectSlotsByName(clientswindow);
    } // setupUi

    void retranslateUi(QMainWindow *clientswindow)
    {
        clientswindow->setWindowTitle(QCoreApplication::translate("clientswindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientswindow: public Ui_clientswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTSWINDOW_H
