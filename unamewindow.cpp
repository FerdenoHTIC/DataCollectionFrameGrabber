#include "unamewindow.h"
#include "ui_unamewindow.h"
#include <QMessageBox>

UnameWindow::UnameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UnameWindow)
{
    ui->setupUi(this);

}

UnameWindow::~UnameWindow()
{
    delete ui;
}
void UnameWindow::login_clicked()
{
    QString username=ui->username_text->text();
    QString password=ui->password_text->text();

    if(username=="anu" && password =="anu")
    {
        // QMessageBox::information(this,"Login","Login successful");

        emit emit_uname_page(2);

    }
    else
    {
        ui->username_text->clear();
        ui->password_text->clear();

        QMessageBox msg;
        // QMessageBox::warning(this,"Login","Login unsuccessful");
        msg.setText("Warning:Login unsuccessful");
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("Error");

        // Accessing internal widgets and applying the stylesheet to the dialog components
        QWidget *msgBoxWidget = msg.findChild<QWidget *>();
        if (msgBoxWidget) {
            msgBoxWidget->setStyleSheet(

                "QMessageBox {"
                "    background-color: #212121;"
                "    color: white;"
                "    border: 2px solid #555555;"
                "}"
                "QLabel {"
                "    color: white;"
                "    font-size: 14px;"
                "}"
                "QPushButton {"
                "    background-color: #555555;"
                "    color: white;"
                "    padding: 10px 20px;"
                "    border-radius: 5px;"
                "    min-width: 80px;"
                "}"
                "QPushButton:hover {"
                "    background-color: #666666;"
                "}"
                );
        }

        // Increase the size of the message box
        msg.setMinimumSize(400, 200);
        msg.exec();
    }

}

void UnameWindow::set_focus_login()
{
    ui->username_text->setFocus();
}




void UnameWindow::on_auth_login_clicked()
{
    login_clicked();
}
