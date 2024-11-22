#ifndef VIDEORECORDER_H
#define VIDEORECORDER_H

#include <QMainWindow>
#include <QCamera>
#include <QMediaDevices>
#include <QImageCapture>
#include <QMediaCaptureSession>
#include <QMediaRecorder>
#include <QFileDialog> // To open a file dialog for selecting the save location
#include <QCameraFormat>
#include <QDateTime>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QElapsedTimer>

namespace Ui {
class VideoRecorder;
}


enum ClassName{
    None,
    Button1,
    Button2,
    Button3
};


class VideoRecorder : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoRecorder(QWidget *parent = nullptr);
    ~VideoRecorder();


private slots:
    void on_startCamera_clicked();

    void on_stopCamera_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::VideoRecorder *ui;
    QCamera *camera;
    QMediaCaptureSession *captureSession;
    QImageCapture *imageCapture;
    QMediaRecorder *mediaRecorder; // Add mediaRecorder as a private member

    ClassName currentClass;
    void resetAllButtonColor();

    bool isButton1On;
    bool isButton2On;
    bool isButton3On;

    QString jsonFilePath;

    QString savePath;

    void writeJsonWithClass();

    QElapsedTimer videoStartTimer;

};

#endif // VIDEORECORDER_H
