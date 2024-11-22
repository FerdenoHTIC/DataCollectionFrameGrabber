/********************************************************************************
** Form generated from reading UI file 'annotatewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANNOTATEWINDOW_H
#define UI_ANNOTATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnnotateWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QFrame *frame_2;
    QPushButton *moveButton;
    QPushButton *pointButton;
    QPushButton *lineButton;
    QPushButton *recButton;
    QPushButton *circleButton;
    QPushButton *polygonButton;
    QFrame *frame_3;
    QLabel *loaded_image;
    QFrame *frame_4;
    QPushButton *undobutton;
    QPushButton *redobutton;
    QPushButton *clearbutton;

    void setupUi(QMainWindow *AnnotateWindow)
    {
        if (AnnotateWindow->objectName().isEmpty())
            AnnotateWindow->setObjectName("AnnotateWindow");
        AnnotateWindow->resize(1840, 920);
        AnnotateWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(AnnotateWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(160, 630, 801, 80));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        loadButton = new QPushButton(frame);
        loadButton->setObjectName("loadButton");
        loadButton->setGeometry(QRect(0, 10, 401, 51));
        loadButton->setStyleSheet(QString::fromUtf8("#loadButton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"    border: 1px solid #212121;\n"
"    border-radius: 10px;\n"
"    padding: 8px 12px;\n"
"    font:20px \"Roboto\";\n"
"}\n"
"\n"
"#loadButton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#loadButton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        saveButton = new QPushButton(frame);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(410, 10, 391, 51));
        saveButton->setStyleSheet(QString::fromUtf8("#saveButton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"    border: 1px solid #212121;\n"
"    border-radius: 10px;\n"
"    padding: 8px 12px;\n"
"    font:20px \"Roboto\";\n"
"}\n"
"\n"
"#saveButton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#saveButton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(40, 200, 91, 431));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        moveButton = new QPushButton(frame_2);
        moveButton->setObjectName("moveButton");
        moveButton->setGeometry(QRect(10, 20, 70, 50));
        moveButton->setStyleSheet(QString::fromUtf8("#moveButton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"	image: url(:/img/images/expand-arrows.png);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}\n"
"\n"
"#moveButton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#moveButton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        pointButton = new QPushButton(frame_2);
        pointButton->setObjectName("pointButton");
        pointButton->setGeometry(QRect(10, 90, 70, 50));
        pointButton->setStyleSheet(QString::fromUtf8("#pointButton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"	image: url(:/img/images/list.png);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}\n"
"\n"
"#pointButton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#pointButton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        lineButton = new QPushButton(frame_2);
        lineButton->setObjectName("lineButton");
        lineButton->setGeometry(QRect(10, 160, 70, 50));
        lineButton->setStyleSheet(QString::fromUtf8("#lineButton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"	image: url(:/img/images/line.png);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}\n"
"\n"
"#lineButton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#lineButton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        recButton = new QPushButton(frame_2);
        recButton->setObjectName("recButton");
        recButton->setGeometry(QRect(10, 230, 70, 50));
        recButton->setStyleSheet(QString::fromUtf8("#recButton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"	image: url(:/img/images/rectangle.png);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}\n"
"\n"
"#recButton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#recButton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        circleButton = new QPushButton(frame_2);
        circleButton->setObjectName("circleButton");
        circleButton->setGeometry(QRect(10, 300, 70, 50));
        circleButton->setStyleSheet(QString::fromUtf8("#circleButton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"	image: url(:/img/images/rec.png);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}\n"
"\n"
"#circleButton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#circleButton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        polygonButton = new QPushButton(frame_2);
        polygonButton->setObjectName("polygonButton");
        polygonButton->setGeometry(QRect(10, 370, 70, 50));
        polygonButton->setStyleSheet(QString::fromUtf8("#polygonButton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"	image: url(:/img/images/polygon.png);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}\n"
"\n"
"#polygonButton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#polygonButton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(160, 60, 801, 541));
        frame_3->setStyleSheet(QString::fromUtf8("#frame_3{\n"
"    background-color: #000000;\n"
"    color: white;\n"
"    border: 2px solid #212121 ;\n"
"    border-radius: 10px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        loaded_image = new QLabel(frame_3);
        loaded_image->setObjectName("loaded_image");
        loaded_image->setGeometry(QRect(10, 10, 781, 521));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(990, 250, 101, 271));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        undobutton = new QPushButton(frame_4);
        undobutton->setObjectName("undobutton");
        undobutton->setGeometry(QRect(10, 30, 70, 50));
        undobutton->setStyleSheet(QString::fromUtf8("#undobutton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"	image: url(:/img/images/undo.png);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}\n"
"\n"
"#undobutton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#undobutton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        redobutton = new QPushButton(frame_4);
        redobutton->setObjectName("redobutton");
        redobutton->setGeometry(QRect(10, 110, 70, 50));
        redobutton->setStyleSheet(QString::fromUtf8("#redobutton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"	image: url(:/img/images/redo.png);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}\n"
"\n"
"#redobutton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#redobutton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        clearbutton = new QPushButton(frame_4);
        clearbutton->setObjectName("clearbutton");
        clearbutton->setGeometry(QRect(10, 190, 70, 50));
        clearbutton->setStyleSheet(QString::fromUtf8("#clearbutton{\n"
"    background-color: #212121;\n"
"    color: white;\n"
"	image: url(:/img/images/clear.png);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 12px;\n"
"    font: bold 20px \"Roboto\";\n"
"}\n"
"\n"
"#clearbutton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#clearbutton:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        AnnotateWindow->setCentralWidget(centralwidget);

        retranslateUi(AnnotateWindow);

        QMetaObject::connectSlotsByName(AnnotateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AnnotateWindow)
    {
        AnnotateWindow->setWindowTitle(QCoreApplication::translate("AnnotateWindow", "MainWindow", nullptr));
        loadButton->setText(QCoreApplication::translate("AnnotateWindow", "Load Image", nullptr));
        saveButton->setText(QCoreApplication::translate("AnnotateWindow", "Save", nullptr));
#if QT_CONFIG(tooltip)
        moveButton->setToolTip(QCoreApplication::translate("AnnotateWindow", "<html><head/><body><p>Move</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        moveButton->setText(QString());
#if QT_CONFIG(tooltip)
        pointButton->setToolTip(QCoreApplication::translate("AnnotateWindow", "<html><head/><body><p>Point</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pointButton->setText(QString());
#if QT_CONFIG(tooltip)
        lineButton->setToolTip(QCoreApplication::translate("AnnotateWindow", "<html><head/><body><p>Line</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineButton->setText(QString());
#if QT_CONFIG(tooltip)
        recButton->setToolTip(QCoreApplication::translate("AnnotateWindow", "<html><head/><body><p>Rectangle</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        recButton->setText(QString());
#if QT_CONFIG(tooltip)
        circleButton->setToolTip(QCoreApplication::translate("AnnotateWindow", "<html><head/><body><p>Circle</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        circleButton->setText(QString());
#if QT_CONFIG(tooltip)
        polygonButton->setToolTip(QCoreApplication::translate("AnnotateWindow", "<html><head/><body><p>Polygon</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        polygonButton->setText(QString());
        loaded_image->setText(QString());
#if QT_CONFIG(tooltip)
        undobutton->setToolTip(QCoreApplication::translate("AnnotateWindow", "<html><head/><body><p>Undo</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        undobutton->setText(QString());
#if QT_CONFIG(tooltip)
        redobutton->setToolTip(QCoreApplication::translate("AnnotateWindow", "<html><head/><body><p>Redo</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        redobutton->setText(QString());
#if QT_CONFIG(tooltip)
        clearbutton->setToolTip(QCoreApplication::translate("AnnotateWindow", "<html><head/><body><p>Clear</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        clearbutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AnnotateWindow: public Ui_AnnotateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANNOTATEWINDOW_H
