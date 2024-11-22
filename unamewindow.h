#ifndef UNAMEWINDOW_H
#define UNAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class UnameWindow;
}

class UnameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UnameWindow(QWidget *parent = nullptr);
    ~UnameWindow();


signals:
    void emit_uname_page(int);

private slots:

    void login_clicked();

    void set_focus_login();



    void on_auth_login_clicked();

private:
    Ui::UnameWindow *ui;
};

#endif // UNAMEWINDOW_H
