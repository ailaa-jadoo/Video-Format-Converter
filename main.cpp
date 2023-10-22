#include <iostream>
#include <QApplication>
#include "videoconverter.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    VideoConverter *converter = new VideoConverter();
    converter->resize(250, 250);
    converter->show();

    return app.exec();
}
