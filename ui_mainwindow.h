/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *MyButton;
    QLineEdit *lineEdit_hunningtudengji;
    QLineEdit *lineEdit_zhanglakongzhixishu;
    QLabel *label;
    QLabel *label_2;
    QPushButton *But_daying;
    QPushButton *but_txt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MyButton = new QPushButton(centralwidget);
        MyButton->setObjectName(QString::fromUtf8("MyButton"));
        MyButton->setGeometry(QRect(300, 240, 80, 20));
        lineEdit_hunningtudengji = new QLineEdit(centralwidget);
        lineEdit_hunningtudengji->setObjectName(QString::fromUtf8("lineEdit_hunningtudengji"));
        lineEdit_hunningtudengji->setGeometry(QRect(250, 110, 113, 20));
        lineEdit_zhanglakongzhixishu = new QLineEdit(centralwidget);
        lineEdit_zhanglakongzhixishu->setObjectName(QString::fromUtf8("lineEdit_zhanglakongzhixishu"));
        lineEdit_zhanglakongzhixishu->setGeometry(QRect(250, 190, 113, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 190, 101, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 110, 91, 16));
        But_daying = new QPushButton(centralwidget);
        But_daying->setObjectName(QString::fromUtf8("But_daying"));
        But_daying->setGeometry(QRect(90, 240, 80, 20));
        but_txt = new QPushButton(centralwidget);
        but_txt->setObjectName(QString::fromUtf8("but_txt"));
        but_txt->setGeometry(QRect(90, 300, 80, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        MyButton->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250py", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\274\240\346\213\211\346\216\247\345\210\266\345\274\272\345\272\246\347\263\273\346\225\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\267\267\345\207\235\345\234\237\345\274\272\345\272\246\347\255\211\347\272\247", nullptr));
        But_daying->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260", nullptr));
        but_txt->setText(QApplication::translate("MainWindow", "txt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
