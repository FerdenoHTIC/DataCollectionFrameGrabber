#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <logowindow.h>
#include <unamewindow.h>
#include <videorecorder.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTimer *datetime_timer;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    virtual bool eventFilter( QObject * watched, QEvent * event ) override;

signals:
    void emit_focus_login();

private slots:
    void init_objects();

    void init_stack_widget();

    void connect_signal_slot();

    void update_date_time();

    void receive_change_page(int);

    void change_label(int);

private:
    Ui::MainWindow *ui;
    LogoWindow *logoWindow;
    UnameWindow *unameWindow;
    VideoRecorder *videoRecorder;

};
#endif // MAINWINDOW_H
