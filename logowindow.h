#ifndef LOGOWINDOW_H
#define LOGOWINDOW_H

#include <QMainWindow>

namespace Ui {
class LogoWindow;
}

class LogoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogoWindow(QWidget *parent = nullptr);
    ~LogoWindow();

private:
    Ui::LogoWindow *ui;
};

#endif // LOGOWINDOW_H
