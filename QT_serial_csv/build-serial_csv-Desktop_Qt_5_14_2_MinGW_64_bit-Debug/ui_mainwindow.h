/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *SPUPORT;
    QComboBox *SPUBAUD;
    QPushButton *BEGINBUTTON;
    QTextBrowser *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SPUPORT = new QComboBox(centralwidget);
        SPUPORT->setObjectName(QString::fromUtf8("SPUPORT"));
        SPUPORT->setGeometry(QRect(630, 100, 87, 22));
        SPUBAUD = new QComboBox(centralwidget);
        SPUBAUD->setObjectName(QString::fromUtf8("SPUBAUD"));
        SPUBAUD->setGeometry(QRect(630, 130, 87, 22));
        BEGINBUTTON = new QPushButton(centralwidget);
        BEGINBUTTON->setObjectName(QString::fromUtf8("BEGINBUTTON"));
        BEGINBUTTON->setGeometry(QRect(630, 180, 93, 28));
        plainTextEdit = new QTextBrowser(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(520, 240, 271, 261));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        BEGINBUTTON->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
