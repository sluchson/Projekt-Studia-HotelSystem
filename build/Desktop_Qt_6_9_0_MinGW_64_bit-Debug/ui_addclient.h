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
    QLabel *labelClients;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lastNameEdit;
    QLabel *label_3;
    QLineEdit *emailEdit;
    QLabel *label_4;
    QLineEdit *phoneEdit;
    QPushButton *addButton;
    QLineEdit *firstNameEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *addclient)
    {
        if (addclient->objectName().isEmpty())
            addclient->setObjectName("addclient");
        addclient->resize(800, 600);
        addclient->setAutoFillBackground(false);
        centralwidget = new QWidget(addclient);
        centralwidget->setObjectName("centralwidget");
        labelClients = new QLabel(centralwidget);
        labelClients->setObjectName("labelClients");
        labelClients->setGeometry(QRect(20, 10, 261, 49));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        labelClients->setFont(font);
        labelClients->setAutoFillBackground(false);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 110, 71, 16));
        QFont font1;
        font1.setBold(true);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 170, 81, 16));
        label_2->setFont(font1);
        lastNameEdit = new QLineEdit(centralwidget);
        lastNameEdit->setObjectName("lastNameEdit");
        lastNameEdit->setGeometry(QRect(320, 190, 181, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 230, 71, 16));
        label_3->setFont(font1);
        emailEdit = new QLineEdit(centralwidget);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setGeometry(QRect(320, 250, 181, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(320, 290, 71, 16));
        label_4->setFont(font1);
        phoneEdit = new QLineEdit(centralwidget);
        phoneEdit->setObjectName("phoneEdit");
        phoneEdit->setGeometry(QRect(320, 310, 181, 31));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(360, 360, 101, 61));
        addButton->setFont(font1);
        firstNameEdit = new QLineEdit(centralwidget);
        firstNameEdit->setObjectName("firstNameEdit");
        firstNameEdit->setGeometry(QRect(320, 130, 181, 31));
        addclient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(addclient);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        addclient->setMenuBar(menubar);
        statusbar = new QStatusBar(addclient);
        statusbar->setObjectName("statusbar");
        addclient->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        label->setBuddy(firstNameEdit);
        label_2->setBuddy(lastNameEdit);
        label_3->setBuddy(emailEdit);
        label_4->setBuddy(phoneEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(addclient);

        QMetaObject::connectSlotsByName(addclient);
    } // setupUi

    void retranslateUi(QMainWindow *addclient)
    {
        addclient->setWindowTitle(QCoreApplication::translate("addclient", "Add Client", nullptr));
        labelClients->setText(QCoreApplication::translate("addclient", "ADD CLIENT", nullptr));
        label->setText(QCoreApplication::translate("addclient", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("addclient", "Surrname:", nullptr));
        label_3->setText(QCoreApplication::translate("addclient", "Email:", nullptr));
        label_4->setText(QCoreApplication::translate("addclient", "Phone:", nullptr));
        addButton->setText(QCoreApplication::translate("addclient", "Add Client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addclient: public Ui_addclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLIENT_H
