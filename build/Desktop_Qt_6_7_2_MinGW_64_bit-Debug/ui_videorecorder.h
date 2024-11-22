/********************************************************************************
** Form generated from reading UI file 'videorecorder.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEORECORDER_H
#define UI_VIDEORECORDER_H

#include <QtCore/QVariant>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoRecorder
{
public:
    QWidget *centralwidget;
    QVideoWidget *displayvideo;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startCamera;
    QPushButton *stopCamera;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *VideoRecorder)
    {
        if (VideoRecorder->objectName().isEmpty())
            VideoRecorder->setObjectName("VideoRecorder");
        VideoRecorder->resize(1920, 1080);
        VideoRecorder->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(VideoRecorder);
        centralwidget->setObjectName("centralwidget");
        displayvideo = new QVideoWidget(centralwidget);
        displayvideo->setObjectName("displayvideo");
        displayvideo->setGeometry(QRect(10, 10, 1031, 621));
        displayvideo->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 255, 161)"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 660, 1031, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        startCamera = new QPushButton(layoutWidget);
        startCamera->setObjectName("startCamera");
        QFont font;
        font.setPointSize(19);
        font.setWeight(QFont::Medium);
        startCamera->setFont(font);
        startCamera->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        horizontalLayout_2->addWidget(startCamera);

        stopCamera = new QPushButton(layoutWidget);
        stopCamera->setObjectName("stopCamera");
        QFont font1;
        font1.setPointSize(20);
        font1.setWeight(QFont::Medium);
        stopCamera->setFont(font1);
        stopCamera->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        horizontalLayout_2->addWidget(stopCamera);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(1140, 270, 321, 91));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: Red;\n"
"}\n"
""));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: Red;\n"
"}\n"
""));
        pushButton->setIconSize(QSize(20, 20));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: Red;\n"
"}\n"
""));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        VideoRecorder->setCentralWidget(centralwidget);

        retranslateUi(VideoRecorder);

        QMetaObject::connectSlotsByName(VideoRecorder);
    } // setupUi

    void retranslateUi(QMainWindow *VideoRecorder)
    {
        VideoRecorder->setWindowTitle(QCoreApplication::translate("VideoRecorder", "MainWindow", nullptr));
        startCamera->setText(QCoreApplication::translate("VideoRecorder", "Start Camera", nullptr));
        stopCamera->setText(QCoreApplication::translate("VideoRecorder", "Stop Camera", nullptr));
        pushButton_3->setText(QCoreApplication::translate("VideoRecorder", "3", nullptr));
        pushButton->setText(QCoreApplication::translate("VideoRecorder", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("VideoRecorder", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoRecorder: public Ui_VideoRecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEORECORDER_H
