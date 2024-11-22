#include "logowindow.h"
#include "ui_logowindow.h"

LogoWindow::LogoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LogoWindow)
{
    ui->setupUi(this);

}

LogoWindow::~LogoWindow()
{
    delete ui;
}
