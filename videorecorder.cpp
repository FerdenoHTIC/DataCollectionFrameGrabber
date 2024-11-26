#include "videorecorder.h"
#include "ui_videorecorder.h"

VideoRecorder::VideoRecorder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoRecorder)
    , captureSession(new QMediaCaptureSession())
    , imageCapture(new QImageCapture(this))
    , mediaRecorder(new QMediaRecorder(this)) // Initialize mediaRecorder
    , camera(nullptr) // Initialize camera
    , cameraIndex(-1)

{
    ui->setupUi(this);

    ui->startCamera->setEnabled(false);
    ui->stopCamera->setEnabled(false);

    setAllButtonFalse();
    setDisableAllButtons();

    QStringList items = {"1st Trisemester", "2nd Trisemester (Target)", "3rd Trisemester"};

    ui->semesterCombo->addItems(items);
    ui->semesterCombo->setEnabled(false);
    setInVisibleAllButtons();

    ui->cameraCombo->addItem("None");
    const QList<QCameraDevice> availableCameras = QMediaDevices::videoInputs();

    for(const QCameraDevice &device : availableCameras){
        ui->cameraCombo->addItem(device.description());
    }
    ui->cameraCombo->setEnabled(false);


}

VideoRecorder::~VideoRecorder()
{
    if (camera && camera->isActive()) {
        mediaRecorder->stop();
        camera->stop();
    }
    delete ui;
}


void VideoRecorder::setDisableAllButtons(){

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

void VideoRecorder::setEnableAllButtons(){

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

void VideoRecorder::setVisibleAllButtons(){
    ui->Head->setVisible(true);
    ui->Face->setVisible(true);
    ui->Abdomen->setVisible(true);
    ui->Pelvis->setVisible(true);
    ui->Thorax->setVisible(true);
    ui->Spine->setVisible(true);
    ui->Upper_Extremities->setVisible(true);
    ui->Lower_Extremities->setVisible(true);
    ui->General->setVisible(true);
}

void VideoRecorder::setInVisibleAllButtons(){
    ui->Head->setVisible(false);
    ui->Face->setVisible(false);
    ui->Abdomen->setVisible(false);
    ui->Pelvis->setVisible(false);
    ui->Thorax->setVisible(false);
    ui->Spine->setVisible(false);
    ui->Upper_Extremities->setVisible(false);
    ui->Lower_Extremities->setVisible(false);
    ui->General->setVisible(false);
}

void VideoRecorder::on_startCamera_clicked()
{

    const QList<QCameraDevice> availableCameras = QMediaDevices::videoInputs();

    qDebug() << "Available camera: " << availableCameras.count();

    if (cameraIndex < 0 || cameraIndex > availableCameras.count()-1){
            QMessageBox::warning(this,
                             "Input Not Found",
                             "No Input is available to start. Please connect a Input Device and try again.");
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
    jsonObject["Semester"] = semesterText;
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
        setEnableAllButtons();
        ui->startCamera->setEnabled(false);
        ui->stopCamera->setEnabled(true);
        ui->LoadFolder->setEnabled(false);
        ui->semesterCombo->setEnabled(false);
        ui->cameraCombo->setEnabled(false);
    }
}


void VideoRecorder::on_stopCamera_clicked()
{
    setDisableAllButtons();
    resetAllButtonColor();
    ui->stopCamera->setEnabled(false);
    ui->startCamera->setEnabled(true);
    ui->LoadFolder->setEnabled(true);
    ui->semesterCombo->setEnabled(true);
    ui->cameraCombo->setEnabled(true);
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




void VideoRecorder::on_LoadFolder_clicked()
{
    // Open a dialog to let the user select a directory
    QString selectedDirectory = QFileDialog::getExistingDirectory(this,
                                                                  tr("Select Directory to save the video"),
                                                                  QCoreApplication::applicationDirPath(),
                                                                  QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // Check if the user selected a directory
    if (!selectedDirectory.isEmpty()) {
        saveDirectory = selectedDirectory;
        ui->semesterCombo->setEnabled(true);
        ui->cameraCombo->setEnabled(true);
    }
}



void VideoRecorder::on_semesterCombo_currentIndexChanged(int index)
{
    semesterIndex=index;

    enableStartRecordingButton();

    if(index==1)
        setVisibleAllButtons();
    else
        setInVisibleAllButtons();

}


void VideoRecorder::on_semesterCombo_currentTextChanged(const QString &arg1)
{
    semesterText = arg1;
}



void VideoRecorder::on_cameraCombo_activated(int index)
{
    const QList<QCameraDevice> availableCameras = QMediaDevices::videoInputs();

    // First, remove items from combo box that are no longer available, except for "None"
    for (int i = 1; i < ui->cameraCombo->count(); ++i) {  // Start from 1 to skip the "None" item
        QString cameraDescription = ui->cameraCombo->itemText(i);
        bool cameraAvailable = false;

        for (const QCameraDevice &device : availableCameras) {
            if (cameraDescription == device.description()) {
                cameraAvailable = true;
                break;
            }
        }

        // If the camera is not available, remove it
        if (!cameraAvailable) {
            ui->cameraCombo->removeItem(i);
            --i; // Adjust the index since we've removed an item
        }
    }

    // Now, add any new cameras that aren't in the combo box, except "None"
    for (const QCameraDevice &device : availableCameras) {
        if (ui->cameraCombo->findText(device.description()) == -1) {
            ui->cameraCombo->addItem(device.description());
        }
    }

    cameraIndex = index -1;
    enableStartRecordingButton();

}


void VideoRecorder::enableStartRecordingButton(){

    if(semesterIndex!=-1 && cameraIndex!=-1){
        ui->startCamera->setEnabled(true);
    }else{
        ui->startCamera->setEnabled(false);
    }
}


