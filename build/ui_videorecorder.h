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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoRecorder
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startCamera;
    QPushButton *stopCamera;
    QVideoWidget *displayvideo;

    void setupUi(QMainWindow *VideoRecorder)
    {
        if (VideoRecorder->objectName().isEmpty())
            VideoRecorder->setObjectName("VideoRecorder");
        VideoRecorder->resize(1162, 881);
        centralwidget = new QWidget(VideoRecorder);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 660, 1031, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        startCamera = new QPushButton(layoutWidget);
        startCamera->setObjectName("startCamera");

        horizontalLayout_2->addWidget(startCamera);

        stopCamera = new QPushButton(layoutWidget);
        stopCamera->setObjectName("stopCamera");

        horizontalLayout_2->addWidget(stopCamera);

        displayvideo = new QVideoWidget(centralwidget);
        displayvideo->setObjectName("displayvideo");
        displayvideo->setGeometry(QRect(70, 20, 1031, 621));
        VideoRecorder->setCentralWidget(centralwidget);

        retranslateUi(VideoRecorder);

        QMetaObject::connectSlotsByName(VideoRecorder);
    } // setupUi

    void retranslateUi(QMainWindow *VideoRecorder)
    {
        VideoRecorder->setWindowTitle(QCoreApplication::translate("VideoRecorder", "MainWindow", nullptr));
        startCamera->setText(QCoreApplication::translate("VideoRecorder", "Start Camera", nullptr));
        stopCamera->setText(QCoreApplication::translate("VideoRecorder", "Stop Camera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoRecorder: public Ui_VideoRecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEORECORDER_H
