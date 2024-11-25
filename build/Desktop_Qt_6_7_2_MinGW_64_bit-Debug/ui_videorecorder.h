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
#include <QtWidgets/QComboBox>
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
    QPushButton *LoadFolder;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *Abdomen;
    QPushButton *Lower_Extremities;
    QPushButton *Head;
    QPushButton *Upper_Extremities;
    QPushButton *Thorax;
    QPushButton *Spine;
    QPushButton *Pelvis;
    QPushButton *Face;
    QPushButton *General;
    QComboBox *semesterCombo;

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
        displayvideo->setGeometry(QRect(30, 60, 611, 401));
        displayvideo->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 255, 161)"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 510, 621, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        startCamera = new QPushButton(layoutWidget);
        startCamera->setObjectName("startCamera");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startCamera->sizePolicy().hasHeightForWidth());
        startCamera->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        font.setWeight(QFont::Medium);
        startCamera->setFont(font);
        startCamera->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));
        startCamera->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(startCamera);

        stopCamera = new QPushButton(layoutWidget);
        stopCamera->setObjectName("stopCamera");
        sizePolicy.setHeightForWidth(stopCamera->sizePolicy().hasHeightForWidth());
        stopCamera->setSizePolicy(sizePolicy);
        stopCamera->setFont(font);
        stopCamera->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        horizontalLayout_2->addWidget(stopCamera);

        LoadFolder = new QPushButton(layoutWidget);
        LoadFolder->setObjectName("LoadFolder");
        sizePolicy.setHeightForWidth(LoadFolder->sizePolicy().hasHeightForWidth());
        LoadFolder->setSizePolicy(sizePolicy);
        LoadFolder->setFont(font);
        LoadFolder->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        horizontalLayout_2->addWidget(LoadFolder);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(750, 160, 471, 431));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Abdomen = new QPushButton(layoutWidget1);
        Abdomen->setObjectName("Abdomen");
        sizePolicy.setHeightForWidth(Abdomen->sizePolicy().hasHeightForWidth());
        Abdomen->setSizePolicy(sizePolicy);
        Abdomen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(84, 84, 84);\n"
"}\n"
""));

        gridLayout->addWidget(Abdomen, 1, 0, 1, 1);

        Lower_Extremities = new QPushButton(layoutWidget1);
        Lower_Extremities->setObjectName("Lower_Extremities");
        sizePolicy.setHeightForWidth(Lower_Extremities->sizePolicy().hasHeightForWidth());
        Lower_Extremities->setSizePolicy(sizePolicy);
        Lower_Extremities->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(84, 84, 84);\n"
"}\n"
""));

        gridLayout->addWidget(Lower_Extremities, 4, 1, 1, 1);

        Head = new QPushButton(layoutWidget1);
        Head->setObjectName("Head");
        sizePolicy.setHeightForWidth(Head->sizePolicy().hasHeightForWidth());
        Head->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setKerning(true);
        Head->setFont(font1);
        Head->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(84, 84, 84);\n"
"}\n"
""));
        Head->setIconSize(QSize(20, 20));

        gridLayout->addWidget(Head, 0, 0, 1, 1);

        Upper_Extremities = new QPushButton(layoutWidget1);
        Upper_Extremities->setObjectName("Upper_Extremities");
        sizePolicy.setHeightForWidth(Upper_Extremities->sizePolicy().hasHeightForWidth());
        Upper_Extremities->setSizePolicy(sizePolicy);
        Upper_Extremities->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(84, 84, 84);\n"
"}\n"
""));

        gridLayout->addWidget(Upper_Extremities, 4, 0, 1, 1);

        Thorax = new QPushButton(layoutWidget1);
        Thorax->setObjectName("Thorax");
        sizePolicy.setHeightForWidth(Thorax->sizePolicy().hasHeightForWidth());
        Thorax->setSizePolicy(sizePolicy);
        Thorax->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(84, 84, 84);\n"
"}\n"
""));

        gridLayout->addWidget(Thorax, 2, 0, 1, 1);

        Spine = new QPushButton(layoutWidget1);
        Spine->setObjectName("Spine");
        sizePolicy.setHeightForWidth(Spine->sizePolicy().hasHeightForWidth());
        Spine->setSizePolicy(sizePolicy);
        Spine->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(84, 84, 84);\n"
"}\n"
""));

        gridLayout->addWidget(Spine, 2, 1, 1, 1);

        Pelvis = new QPushButton(layoutWidget1);
        Pelvis->setObjectName("Pelvis");
        sizePolicy.setHeightForWidth(Pelvis->sizePolicy().hasHeightForWidth());
        Pelvis->setSizePolicy(sizePolicy);
        Pelvis->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(84, 84, 84);\n"
"}\n"
""));

        gridLayout->addWidget(Pelvis, 1, 1, 1, 1);

        Face = new QPushButton(layoutWidget1);
        Face->setObjectName("Face");
        sizePolicy.setHeightForWidth(Face->sizePolicy().hasHeightForWidth());
        Face->setSizePolicy(sizePolicy);
        Face->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(84, 84, 84);\n"
"}\n"
""));

        gridLayout->addWidget(Face, 0, 1, 1, 1);

        General = new QPushButton(layoutWidget1);
        General->setObjectName("General");
        sizePolicy.setHeightForWidth(General->sizePolicy().hasHeightForWidth());
        General->setSizePolicy(sizePolicy);
        General->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(84, 84, 84);\n"
"}\n"
""));

        gridLayout->addWidget(General, 5, 0, 1, 1);

        semesterCombo = new QComboBox(centralwidget);
        semesterCombo->setObjectName("semesterCombo");
        semesterCombo->setGeometry(QRect(750, 70, 461, 61));
        semesterCombo->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"    background-color: rgb(84, 84, 84);\n"
"    text-align: center;\n"
"}"));
        semesterCombo->setInsertPolicy(QComboBox::InsertPolicy::InsertAtBottom);
        semesterCombo->setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        VideoRecorder->setCentralWidget(centralwidget);
        QWidget::setTabOrder(Head, Abdomen);
        QWidget::setTabOrder(Abdomen, Face);
        QWidget::setTabOrder(Face, Pelvis);
        QWidget::setTabOrder(Pelvis, Thorax);
        QWidget::setTabOrder(Thorax, Spine);
        QWidget::setTabOrder(Spine, Upper_Extremities);
        QWidget::setTabOrder(Upper_Extremities, Lower_Extremities);
        QWidget::setTabOrder(Lower_Extremities, General);

        retranslateUi(VideoRecorder);

        QMetaObject::connectSlotsByName(VideoRecorder);
    } // setupUi

    void retranslateUi(QMainWindow *VideoRecorder)
    {
        VideoRecorder->setWindowTitle(QCoreApplication::translate("VideoRecorder", "MainWindow", nullptr));
        startCamera->setText(QCoreApplication::translate("VideoRecorder", "Start Recording", nullptr));
        stopCamera->setText(QCoreApplication::translate("VideoRecorder", "Stop Recording", nullptr));
        LoadFolder->setText(QCoreApplication::translate("VideoRecorder", "Load Folder", nullptr));
        Abdomen->setText(QCoreApplication::translate("VideoRecorder", "Abdomen", nullptr));
        Lower_Extremities->setText(QCoreApplication::translate("VideoRecorder", " Lower Extremities", nullptr));
        Head->setText(QCoreApplication::translate("VideoRecorder", "Head", nullptr));
        Upper_Extremities->setText(QCoreApplication::translate("VideoRecorder", " Upper Extremities", nullptr));
        Thorax->setText(QCoreApplication::translate("VideoRecorder", "Thorax", nullptr));
        Spine->setText(QCoreApplication::translate("VideoRecorder", "Spine", nullptr));
        Pelvis->setText(QCoreApplication::translate("VideoRecorder", "Pelvis", nullptr));
        Face->setText(QCoreApplication::translate("VideoRecorder", "Face", nullptr));
        General->setText(QCoreApplication::translate("VideoRecorder", "General", nullptr));
        semesterCombo->setPlaceholderText(QCoreApplication::translate("VideoRecorder", "Select a option", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoRecorder: public Ui_VideoRecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEORECORDER_H
