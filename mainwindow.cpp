#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDate>
#include<QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // this->showFullScreen();

    init_objects();

    init_stack_widget();

    connect_signal_slot();

    update_date_time();

    datetime_timer=new QTimer();
    connect(datetime_timer,SIGNAL(timeout()),this,SLOT(update_date_time()));
    datetime_timer->start(1000);

    this->installEventFilter(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{

    if(event->type() == QEvent::MouseButtonRelease && ui->stackedWidget->currentIndex() == 0)
    {
        receive_change_page(1);
    }
    return QObject::eventFilter(obj, event);
}

void MainWindow::receive_change_page(int index)
{
    ui->stackedWidget->setCurrentIndex(index);

    if(index==1)
        emit emit_focus_login();
    (index>1)?ui->top_frame->show():ui->top_frame->hide();

    // change_label(index);

}
void MainWindow::init_objects()
{
    logoWindow=new LogoWindow();
    unameWindow=new UnameWindow();
    videoRecorder = new VideoRecorder();

}
void MainWindow::init_stack_widget()
{
    ui->stackedWidget->addWidget(logoWindow);//index 0
    ui->stackedWidget->addWidget(unameWindow);//index 1
    ui->stackedWidget->addWidget(videoRecorder);//index 3
    receive_change_page(2);
}
void MainWindow::connect_signal_slot()
{
    connect(this,SIGNAL(emit_focus_login()),unameWindow,SLOT(set_focus_login()),Qt::QueuedConnection);
    connect(unameWindow,SIGNAL(emit_uname_page(int)),this,SLOT(receive_change_page(int)),Qt::QueuedConnection);
}
void MainWindow::update_date_time()
{
    ui->date_label->setText(QDate::currentDate().toString("dd MM yyyy"));
    ui->time_label->setText(QTime::currentTime().toString("hh : mm AP"));
}

void MainWindow::change_label(int state)
{
    switch (state) {
    case 2:
        ui->title_label->setText("Annotate The Class");
        break;
    case 3:
        ui->title_label->setText("Annotation Using Template");
        break;
    default:
        ui->title_label->clear();
        break;
    }
}
