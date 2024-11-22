/********************************************************************************
** Form generated from reading UI file 'unamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNAMEWINDOW_H
#define UI_UNAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnameWindow
{
public:
    QWidget *centralwidget;
    QLabel *logo_image;
    QFrame *frame;
    QLineEdit *password_text;
    QPushButton *auth_login;
    QLineEdit *username_text;
    QLabel *label;

    void setupUi(QMainWindow *UnameWindow)
    {
        if (UnameWindow->objectName().isEmpty())
            UnameWindow->setObjectName("UnameWindow");
        UnameWindow->resize(1920, 1080);
        UnameWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(UnameWindow);
        centralwidget->setObjectName("centralwidget");
        logo_image = new QLabel(centralwidget);
        logo_image->setObjectName("logo_image");
        logo_image->setGeometry(QRect(20, 230, 400, 400));
        logo_image->setStyleSheet(QString::fromUtf8("image: url(:/img/images/anu.png);"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(480, 250, 811, 370));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        password_text = new QLineEdit(frame);
        password_text->setObjectName("password_text");
        password_text->setGeometry(QRect(170, 120, 595, 60));
        QFont font;
        font.setPointSize(18);
        password_text->setFont(font);
        password_text->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        password_text->setStyleSheet(QString::fromUtf8("#password_text {\n"
"  color:#FFFFFF;\n"
"background-color:#212121;\n"
"border: none;\n"
"border-radius:10px;\n"
"padding:10px;\n"
"}\n"
"\n"
"#password_text:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#password_text:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        password_text->setEchoMode(QLineEdit::EchoMode::Password);
        auth_login = new QPushButton(frame);
        auth_login->setObjectName("auth_login");
        auth_login->setGeometry(QRect(240, 260, 460, 60));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        auth_login->setFont(font1);
        auth_login->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        auth_login->setStyleSheet(QString::fromUtf8("#auth_login {\n"
"color:#ffffff;\n"
"background-color:#558a0a;\n"
"border: none;\n"
"border-radius:10px;\n"
"padding:10px;\n"
"}\n"
"\n"
"#auth_login:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#auth_login:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        username_text = new QLineEdit(frame);
        username_text->setObjectName("username_text");
        username_text->setGeometry(QRect(170, 30, 595, 60));
        username_text->setFont(font);
        username_text->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        username_text->setStyleSheet(QString::fromUtf8("#username_text {\n"
"color:#FFFFFF;\n"
"background-color:#212121;\n"
"border: none;\n"
"border-radius:10px;\n"
"padding:10px;\n"
"}\n"
"\n"
"#username_text:hover {\n"
"    background-color: #555555;\n"
"}\n"
"\n"
"#username_text:pressed {\n"
"    background-color: #222222;\n"
"}\n"
""));
        username_text->setEchoMode(QLineEdit::EchoMode::Normal);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(390, 130, 910, 70));
        QFont font2;
        font2.setPointSize(20);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color:#D1D1D1;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        UnameWindow->setCentralWidget(centralwidget);

        retranslateUi(UnameWindow);

        QMetaObject::connectSlotsByName(UnameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UnameWindow)
    {
        UnameWindow->setWindowTitle(QCoreApplication::translate("UnameWindow", "MainWindow", nullptr));
        logo_image->setText(QString());
        password_text->setText(QString());
        password_text->setPlaceholderText(QCoreApplication::translate("UnameWindow", "Password", nullptr));
        auth_login->setText(QCoreApplication::translate("UnameWindow", "Log in", nullptr));
        username_text->setText(QString());
        username_text->setPlaceholderText(QCoreApplication::translate("UnameWindow", "User Name", nullptr));
        label->setText(QCoreApplication::translate("UnameWindow", "Welcome!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UnameWindow: public Ui_UnameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNAMEWINDOW_H
