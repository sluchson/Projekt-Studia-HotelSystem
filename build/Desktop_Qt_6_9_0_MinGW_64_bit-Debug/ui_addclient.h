/********************************************************************************
** Form generated from reading UI file 'addclient.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCLIENT_H
#define UI_ADDCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addclient
{
public:
    QWidget *centralwidget;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QLineEdit *emailEdit;
    QLineEdit *phoneEdit;
    QPushButton *addButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *addclient)
    {
        if (addclient->objectName().isEmpty())
            addclient->setObjectName("addclient");
        addclient->resize(800, 600);
        centralwidget = new QWidget(addclient);
        centralwidget->setObjectName("centralwidget");
        firstNameEdit = new QLineEdit(centralwidget);
        firstNameEdit->setObjectName("firstNameEdit");
        firstNameEdit->setGeometry(QRect(30, 60, 113, 24));
        lastNameEdit = new QLineEdit(centralwidget);
        lastNameEdit->setObjectName("lastNameEdit");
        lastNameEdit->setGeometry(QRect(30, 130, 113, 24));
        emailEdit = new QLineEdit(centralwidget);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setGeometry(QRect(30, 210, 113, 24));
        phoneEdit = new QLineEdit(centralwidget);
        phoneEdit->setObjectName("phoneEdit");
        phoneEdit->setGeometry(QRect(30, 280, 113, 24));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(30, 350, 121, 61));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 110, 71, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 190, 71, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 260, 71, 16));
        addclient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(addclient);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        addclient->setMenuBar(menubar);
        statusbar = new QStatusBar(addclient);
        statusbar->setObjectName("statusbar");
        addclient->setStatusBar(statusbar);

        retranslateUi(addclient);

        QMetaObject::connectSlotsByName(addclient);
    } // setupUi

    void retranslateUi(QMainWindow *addclient)
    {
        addclient->setWindowTitle(QCoreApplication::translate("addclient", "Add Client", nullptr));
        addButton->setText(QCoreApplication::translate("addclient", "Add Client", nullptr));
        label->setText(QCoreApplication::translate("addclient", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("addclient", "Surrname:", nullptr));
        label_3->setText(QCoreApplication::translate("addclient", "Email:", nullptr));
        label_4->setText(QCoreApplication::translate("addclient", "Phone:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addclient: public Ui_addclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLIENT_H
