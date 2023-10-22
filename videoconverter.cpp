#include "videoconverter.h"
#include <iostream>
#include <string>
#include <vector>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QProcess>

using namespace std;

VideoConverter::VideoConverter() {
    // Create GUI elements
    inputLabel = new QLabel("Input video file:");
    inputLineEdit = new QLineEdit();
    inputButton = new QPushButton("Browse...");
    outputLabel = new QLabel("Output video file:");
    outputLineEdit = new QLineEdit();
    outputButton = new QPushButton("Browse..."); // Add Browse button for output path
    convertButton = new QPushButton("Convert");
//    errorLabel = new QLabel("");
//    successLabel = new QLabel("");
    successErrorLabel = new QLabel("<font><b>Your process will be shown here</b><font>");

    // Connect signals and slots
    connectSignalsAndSlots();

    // Layout GUI elements
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(inputLabel);
    layout->addWidget(inputLineEdit);
    layout->addWidget(inputButton);
    layout->addWidget(outputLabel);
    layout->addWidget(outputLineEdit);
    layout->addWidget(outputButton); // Add Browse button
    layout->addWidget(convertButton);
//    layout->addWidget(errorLabel);
//    layout->addWidget(successLabel);
    layout->addWidget(successErrorLabel);

    // Set window title
    setWindowTitle("Video Converter");

    // Set layout
    setLayout(layout);
}

void VideoConverter::connectSignalsAndSlots() {
    QObject::connect(inputButton, &QPushButton::clicked, [this]() {
        QString inputPath = QFileDialog::getOpenFileName(nullptr, "Select input video file", "", "*.avi *.mkv *.mov *.wmv *.flv");
        inputLineEdit->setText(inputPath);
    });

    QObject::connect(outputButton, &QPushButton::clicked, [this]() {
        QString outputPath = QFileDialog::getSaveFileName(nullptr, "Select output video file", "", "MP4 Files (*.mp4)");
        outputLineEdit->setText(outputPath);
    });

    QObject::connect(convertButton, &QPushButton::clicked, [this]() {
        QString inputPath = inputLineEdit->text();
        QString outputPath = outputLineEdit->text();

        // Check if input path is empty
        if (inputPath.isEmpty()) {
            successErrorLabel->setText("<font color='red'><b>Please select an input video file.</b><font>");
            return;
        }

        // Check if output path is empty
        if (outputPath.isEmpty()) {
            successErrorLabel->setText("<font color='red'><b>Please select an output video file.</b><font>");
            return;
        }

        // Convert video to MP4 using FFmpeg
//        string command = "ffmpeg -i \"" + inputPath.toStdString() + "\" -c:v copy -c:a aac \"" + outputPath.toStdString() + "\" 2>&1";
//        int result = system(command.c_str());

//        if (result == 0) {
//            successErrorLabel->setText("<font color='green'><b>Video converted to MP4 successfully.</b><font>");
//            cout << "Video converted successfully" << endl;
//        } else {
//            successErrorLabel->setText("<font color='red'><b>Video conversion failed.</b><font>");
//            cout << "Video conversion failed" << endl;
//        }
        QProcess process;
        QStringList arguments;
        arguments << "-i" << inputPath << "-c:v" << "copy" << "-c:a" << "aac" << outputPath;
        process.start("ffmpeg", arguments);
        process.waitForFinished();

        if (process.exitCode() == 0) {
            successErrorLabel->setText("<font color='green'><b>Video converted to MP4 successfully.</b><font>");
            cout << "Video converted successfully" << endl;
        } else {
            successErrorLabel->setText("<font color='red'><b>Video conversion failed.</b><font>");
            cout << "Video conversion failed" << endl;
        }
    });
}
