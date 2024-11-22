/********************************************************************************
** Form generated from reading UI file 'logowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGOWINDOW_H
#define UI_LOGOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogoWindow
{
public:
    QWidget *centralwidget;
    QLabel *logo_label;

    void setupUi(QMainWindow *LogoWindow)
    {
        if (LogoWindow->objectName().isEmpty())
            LogoWindow->setObjectName("LogoWindow");
        LogoWindow->resize(1920, 1080);
        LogoWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(LogoWindow);
        centralwidget->setObjectName("centralwidget");
        logo_label = new QLabel(centralwidget);
        logo_label->setObjectName("logo_label");
        logo_label->setGeometry(QRect(250, 140, 900, 400));
        logo_label->setStyleSheet(QString::fromUtf8("image: url(:/img/images/anu.png);"));
        LogoWindow->setCentralWidget(centralwidget);

        retranslateUi(LogoWindow);

        QMetaObject::connectSlotsByName(LogoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LogoWindow)
    {
        LogoWindow->setWindowTitle(QCoreApplication::translate("LogoWindow", "MainWindow", nullptr));
        logo_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LogoWindow: public Ui_LogoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOWINDOW_H
