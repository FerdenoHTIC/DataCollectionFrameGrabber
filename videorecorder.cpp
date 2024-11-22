#include "videorecorder.h"
#include "ui_videorecorder.h"

VideoRecorder::VideoRecorder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoRecorder)
    , captureSession(new QMediaCaptureSession())
    , imageCapture(new QImageCapture(this))
    , mediaRecorder(new QMediaRecorder(this)) // Initialize mediaRecorder
    , camera(nullptr) // Initialize camera
    , isButton1On(false)
    , isButton2On(false)
    , isButton3On(false)

{
    ui->setupUi(this);


    ui->startCamera->setEnabled(true);
    ui->stopCamera->setEnabled(false);

    disableAllButtons();

}

VideoRecorder::~VideoRecorder()
{
    if (camera && camera->isActive()) {
        mediaRecorder->stop();
        camera->stop();
    }
    delete ui;
}


void VideoRecorder::disableAllButtons(){
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

void VideoRecorder::enableAllButtons(){
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
}



void VideoRecorder::on_startCamera_clicked()
{


    const QList<QCameraDevice> availableCameras = QMediaDevices::videoInputs();

    int cameraIndex = -1;
    bool isFrameGrabberFound = false;
    for(const QCameraDevice &device : availableCameras){
        cameraIndex++;
        if(device.description() == "USB 2.0 Webcam Device"){ // "USB 2.0 Webcam Device" or "AV.io HD+"
            isFrameGrabberFound = true;
            break;
        }
    }



    if (!isFrameGrabberFound) {
        QMessageBox::warning(this,
                             "Camera Not Found",
                             "No camera is available to start. Please connect a camera and try again.");
        camera = nullptr;
        return;
    }

    camera = new QCamera(availableCameras[cameraIndex], this);




    // Select the first camera in the list

    // Set up the camera with the capture session
    captureSession->setCamera(camera);

    // imageCapture->setQuality(QImageCapture::VeryHighQuality);
    captureSession->setImageCapture(imageCapture);

    captureSession->setRecorder(mediaRecorder);
    mediaRecorder->setQuality(QMediaRecorder::VeryHighQuality); // Set quality to Very High


    captureSession->setVideoOutput(ui->displayvideo);

    QString saveDirectory = QCoreApplication::applicationDirPath() + "/SaveVideo";

    // Create the directory if it does not exist
    QDir dir(saveDirectory);
    if (!dir.exists()) {
        dir.mkpath("."); // Create the directory if it doesn't exist
    }

    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");


    //creates a directory with videoname
    QString saveDirectoryVideo = saveDirectory + "/Video_" + timestamp;

    QDir Videodir(saveDirectoryVideo);
    if(!Videodir.exists()){
        Videodir.mkpath(".");
    }

    // Generate a timestamped filename
    savePath = saveDirectoryVideo + "/Video_" + timestamp + ".mp4";  // Change extension if needed


    jsonFilePath = saveDirectoryVideo + "/Video_" + timestamp + ".json";


    mediaRecorder->setOutputLocation(QUrl::fromLocalFile(savePath));
    qDebug() << "Output location set to:" << mediaRecorder->outputLocation();

    qDebug() << "Json File Path: " << jsonFilePath;


    QJsonObject jsonObject;
    jsonObject["VideoName"] = QString("Video_") + timestamp;
    jsonObject["VideoPath"] = savePath;
    jsonObject["Class"] = {};


    QJsonDocument jsonDocument(jsonObject);
    QFile jsonFile(jsonFilePath);
    if(jsonFile.open(QIODevice::WriteOnly)){
        jsonFile.write(jsonDocument.toJson());
        jsonFile.close();
    }

    if(camera->isAvailable()){
        camera->start();
        // Save the initial timestamp to track the video start time
        videoStartTimer.start();  // Start counting the time from now
        mediaRecorder->record();
        resetAllButtonColor();
        enableAllButtons();
        ui->startCamera->setEnabled(false);
        ui->stopCamera->setEnabled(true);
    }
}


void VideoRecorder::on_stopCamera_clicked()
{
    disableAllButtons();
    ui->stopCamera->setEnabled(false);
    ui->startCamera->setEnabled(true);
    mediaRecorder->stop();
    camera->stop();

}


void VideoRecorder::writeJsonWithClass()
{

    qint64 elapsedMilliseconds = videoStartTimer.elapsed();  // Time in milliseconds since start
    // Calculate hours, minutes, seconds, and milliseconds
    int hours = (elapsedMilliseconds / 3600000); // 1 hour = 3,600,000 ms
    int minutes = (elapsedMilliseconds % 3600000) / 60000; // 1 minute = 60,000 ms
    int seconds = (elapsedMilliseconds % 60000) / 1000; // 1 second = 1,000 ms
    int milliseconds = elapsedMilliseconds % 1000; // Remaining milliseconds

    // Format the time as HH:MM:SS:MS
    QString formattedTime = QString("%1:%2:%3:%4")
                                .arg(hours, 2, 10, QChar('0'))
                                .arg(minutes, 2, 10, QChar('0'))
                                .arg(seconds, 2, 10, QChar('0'))
                                .arg(milliseconds, 3, 10, QChar('0'));

    // Open the JSON file for reading
    QFile jsonFile(jsonFilePath);
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open JSON file for reading:" << jsonFilePath;
        return;
    }

    // Read and parse the JSON file
    QByteArray jsonData = jsonFile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    jsonFile.close();

    if (jsonDoc.isNull() || !jsonDoc.isObject()) {
        qDebug() << "Invalid JSON file:" << jsonFilePath;
        return;
    }

    // Get the root JSON object
    QJsonObject jsonObject = jsonDoc.object();

    // Modify the JSON object (example: adding a new class entry)
    QString className;
    switch (currentClass) {
    case Button1:
        className = "Class1";
        break;
    case Button2:
        className = "Class2";
        break;
    case Button3:
        className = "Class3";
        break;
    default:
        qDebug() << "No class selected. JSON not updated.";
        return;
    }

    // Update the "Class" array in the JSON
    QJsonArray classArray = jsonObject["Class"].toArray();

    QJsonObject classEntry;
    classEntry["ClassName"] = className;
    classEntry["Timestamp"] = formattedTime;  // Store the formatted timestamp

    classArray.append(classEntry);
    jsonObject["Class"] = classArray;

    // Write the modified JSON object back to the file
    QJsonDocument updatedDoc(jsonObject);
    if (!jsonFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open JSON file for writing:" << jsonFilePath;
        return;
    }

    jsonFile.write(updatedDoc.toJson());
    jsonFile.close();

    qDebug() << "JSON file updated successfully with class:" << className;
}


void VideoRecorder::on_pushButton_clicked()
{


    if(!isButton1On){
        resetAllButtonColor();
        ui->pushButton->setStyleSheet("background-color: green");
        isButton1On=true;
        currentClass = Button1;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();

    }


}


void VideoRecorder::on_pushButton_2_clicked()
{
    if(!isButton2On){
        resetAllButtonColor();
        ui->pushButton_2->setStyleSheet("background-color: green");
        isButton2On=true;
        currentClass = Button2;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();

    }
}


void VideoRecorder::on_pushButton_3_clicked()
{
    if(!isButton3On){
        resetAllButtonColor();
        ui->pushButton_3->setStyleSheet("background-color: green");
        isButton3On=true;
        currentClass = Button3;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();

    }
}


void VideoRecorder::resetAllButtonColor()
{
    currentClass = None;

    isButton1On = false;
    ui->pushButton->setStyleSheet("background-color: red");

    isButton2On = false;
    ui->pushButton_2->setStyleSheet("background-color: red");

    isButton3On = false;
    ui->pushButton_3->setStyleSheet("background-color: red");
}

