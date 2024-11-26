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
#include <QComboBox>

namespace Ui {
class VideoRecorder;
}


enum ClassName{

    None,
    Head,
    Face,
    Abdomen,
    Pelvis,
    Thorax,
    Spine,
    Upper_Extremities,
    Lower_Extremities,
    General
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


    void on_Head_clicked();

    void on_Face_clicked();

    void on_Abdomen_clicked();



    void on_Pelvis_clicked();

    void on_Thorax_clicked();

    void on_Spine_clicked();

    void on_Upper_Extremities_clicked();

    void on_Lower_Extremities_clicked();

    void on_General_clicked();

    void on_LoadFolder_clicked();

    void on_semesterCombo_currentIndexChanged(int index);

    void on_semesterCombo_currentTextChanged(const QString &arg1);

    void on_cameraCombo_activated(int index);

private:
    Ui::VideoRecorder *ui;
    QCamera *camera;
    QMediaCaptureSession *captureSession;
    QImageCapture *imageCapture;
    QMediaRecorder *mediaRecorder; // Add mediaRecorder as a private member

    int cameraIndex;
    ClassName currentClass;
    void resetAllButtonColor();

    bool isHeadOn;
    bool isFaceOn;
    bool isAbdomenOn;
    bool isPelvisOn;
    bool isThoraxOn;
    bool isSpineOn;
    bool isUpper_ExtremitiesOn;
    bool isLower_ExtremitiesOn;
    bool isGeneralOn;

    QString jsonFilePath;

    QString savePath;

    QString saveDirectory;

    void writeJsonWithClass();

    QElapsedTimer videoStartTimer;

    void setDisableAllButtons();

    void setEnableAllButtons();

    void setAllButtonFalse();

    void setVisibleAllButtons();

    void setInVisibleAllButtons();

    int semesterIndex;

    QString semesterText;

    void on_comboBoxClicked();

    void enableStartRecordingButton();


};

#endif // VIDEORECORDER_H
