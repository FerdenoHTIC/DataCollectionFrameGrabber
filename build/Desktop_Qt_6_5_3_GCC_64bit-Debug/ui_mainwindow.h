/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QFrame *top_frame;
    QLabel *title_label;
    QLabel *label;
    QFrame *bottom_frame;
    QLabel *time_label;
    QLabel *date_label;
    QFrame *top_line;
    QFrame *bottom_line;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(40, 80, 1840, 920));
        stackedWidget->setLayoutDirection(Qt::LeftToRight);
        stackedWidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 0);"));
        top_frame = new QFrame(centralwidget);
        top_frame->setObjectName("top_frame");
        top_frame->setGeometry(QRect(0, 0, 1920, 65));
        top_frame->setFrameShape(QFrame::StyledPanel);
        top_frame->setFrameShadow(QFrame::Raised);
        title_label = new QLabel(top_frame);
        title_label->setObjectName("title_label");
        title_label->setGeometry(QRect(470, 20, 610, 40));
        label = new QLabel(top_frame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 70, 55));
        label->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/img/images/anu.png);"));
        bottom_frame = new QFrame(centralwidget);
        bottom_frame->setObjectName("bottom_frame");
        bottom_frame->setGeometry(QRect(0, 1030, 1901, 50));
        bottom_frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        bottom_frame->setFrameShape(QFrame::StyledPanel);
        bottom_frame->setFrameShadow(QFrame::Raised);
        time_label = new QLabel(bottom_frame);
        time_label->setObjectName("time_label");
        time_label->setGeometry(QRect(1600, 0, 150, 30));
        QFont font;
        font.setPointSize(16);
        time_label->setFont(font);
        date_label = new QLabel(bottom_frame);
        date_label->setObjectName("date_label");
        date_label->setGeometry(QRect(1740, 0, 150, 30));
        date_label->setFont(font);
        date_label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        top_line = new QFrame(centralwidget);
        top_line->setObjectName("top_line");
        top_line->setGeometry(QRect(0, 70, 1920, 1));
        top_line->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 31, 31);"));
        top_line->setFrameShape(QFrame::HLine);
        top_line->setFrameShadow(QFrame::Sunken);
        bottom_line = new QFrame(centralwidget);
        bottom_line->setObjectName("bottom_line");
        bottom_line->setGeometry(QRect(0, 1020, 1920, 1));
        bottom_line->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 31, 31);"));
        bottom_line->setFrameShape(QFrame::HLine);
        bottom_line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        title_label->setText(QString());
        label->setText(QString());
        time_label->setText(QString());
        date_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
