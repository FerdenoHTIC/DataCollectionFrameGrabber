#include "videorecorder.h"
#include "ui_videorecorder.h"

VideoRecorder::VideoRecorder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoRecorder)
    , captureSession(new QMediaCaptureSession())
    , imageCapture(new QImageCapture(this))
    , mediaRecorder(new QMediaRecorder(this)) // Initialize mediaRecorder
    , camera(nullptr) // Initialize camera

{
    ui->setupUi(this);

    ui->startCamera->setEnabled(true);
    ui->stopCamera->setEnabled(false);

    setAllButtonFalse();
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

    ui->Head->setEnabled(false);
    ui->Face->setEnabled(false);
    ui->Abdomen->setEnabled(false);
    ui->Pelvis->setEnabled(false);
    ui->Thorax->setEnabled(false);
    ui->Spine->setEnabled(false);
    ui->Upper_Extremities->setEnabled(false);
    ui->Lower_Extremities->setEnabled(false);
    ui->General->setEnabled(false);
}

void VideoRecorder::enableAllButtons(){

    ui->Head->setEnabled(true);
    ui->Face->setEnabled(true);
    ui->Abdomen->setEnabled(true);
    ui->Pelvis->setEnabled(true);
    ui->Thorax->setEnabled(true);
    ui->Spine->setEnabled(true);
    ui->Upper_Extremities->setEnabled(true);
    ui->Lower_Extremities->setEnabled(true);
    ui->General->setEnabled(true);
}

void VideoRecorder::setAllButtonFalse(){

    isHeadOn = false;
    isFaceOn = false;
    isAbdomenOn = false;
    isPelvisOn = false;
    isThoraxOn = false;
    isSpineOn = false;
    isUpper_ExtremitiesOn = false;
    isLower_ExtremitiesOn = false;
    isGeneralOn = false;
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
    resetAllButtonColor();
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
    case Head:
        className = "Head";
        break;
    case Face:
        className = "Face";
        break;
    case Abdomen:
        className = "Abdomen";
        break;
    case Pelvis:
        className = "Pelvis";
        break;
    case Thorax:
        className = "Thorax";
        break;
    case Spine:
        className = "Spine";
        break;
    case Upper_Extremities:
        className = "Upper_Extremities";
        break;
    case Lower_Extremities:
        className = "Lower_Extremities";
        break;
    case General:
        className = "General";
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


void VideoRecorder::on_Head_clicked()
{
    if(!isHeadOn){
        resetAllButtonColor();
        ui->Head->setStyleSheet("background-color: rgb(85, 138, 10)");
        isHeadOn = true;
        currentClass = Head;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();
    }
}


void VideoRecorder::on_Face_clicked()
{
    if(!isFaceOn){
        resetAllButtonColor();
        ui->Face->setStyleSheet("background-color: rgb(85, 138, 10)");
        isFaceOn = true;
        currentClass = Face;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();
    }
}


void VideoRecorder::on_Abdomen_clicked()
{
    if(!isAbdomenOn){
        resetAllButtonColor();
        ui->Abdomen->setStyleSheet("background-color: rgb(85, 138, 10)");
        isAbdomenOn = true;
        currentClass = Abdomen;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();
    }
}

void VideoRecorder::on_Pelvis_clicked()
{
    if(!isPelvisOn){
        resetAllButtonColor();
        ui->Pelvis->setStyleSheet("background-color: rgb(85, 138, 10)");
        isPelvisOn = true;
        currentClass = Pelvis;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();
    }
}


void VideoRecorder::on_Thorax_clicked()
{
    if(!isThoraxOn){
        resetAllButtonColor();
        ui->Thorax->setStyleSheet("background-color: rgb(85, 138, 10)");
        isThoraxOn = true;
        currentClass = Thorax;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();
    }
}


void VideoRecorder::on_Spine_clicked()
{
    if(!isSpineOn){
        resetAllButtonColor();
        ui->Spine->setStyleSheet("background-color: rgb(85, 138, 10)");
        isSpineOn = true;
        currentClass = Spine;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();
    }
}


void VideoRecorder::on_Upper_Extremities_clicked()
{
    if(!isUpper_ExtremitiesOn){
        resetAllButtonColor();
        ui->Upper_Extremities->setStyleSheet("background-color: rgb(85, 138, 10)");
        isUpper_ExtremitiesOn = true;
        currentClass = Upper_Extremities;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();
    }
}


void VideoRecorder::on_Lower_Extremities_clicked()
{
    if(!isLower_ExtremitiesOn){
        resetAllButtonColor();
        ui->Lower_Extremities->setStyleSheet("background-color: rgb(85, 138, 10)");
        isLower_ExtremitiesOn = true;
        currentClass = Lower_Extremities;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();
    }
}


void VideoRecorder::on_General_clicked()
{
    if(!isGeneralOn){
        resetAllButtonColor();
        ui->General->setStyleSheet("background-color: rgb(85, 138, 10)");
        isGeneralOn = true;
        currentClass = General;
        writeJsonWithClass();
    }else{
        resetAllButtonColor();
    }
}

void VideoRecorder::resetAllButtonColor()
{
    currentClass = None;

    setAllButtonFalse();

    ui->Head->setStyleSheet("background-color: rgb(84, 84, 84)");

    ui->Face->setStyleSheet("background-color: rgb(84, 84, 84)");

    ui->Abdomen->setStyleSheet("background-color: rgb(84, 84, 84)");

    ui->Pelvis->setStyleSheet("background-color: rgb(84, 84, 84)");

    ui->Thorax->setStyleSheet("background-color: rgb(84, 84, 84)");

    ui->Spine->setStyleSheet("background-color: rgb(84, 84, 84)");

    ui->Upper_Extremities->setStyleSheet("background-color: rgb(84, 84, 84)");

    ui->Lower_Extremities->setStyleSheet("background-color: rgb(84, 84, 84)");

    ui->General->setStyleSheet("background-color: rgb(84, 84, 84)");

}







