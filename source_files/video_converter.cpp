#include "../header_files/header.hpp"

VideoConverter::VideoConverter(){
}

int VideoConverter::changeSpaceColor(int slider){
    int space_color;

    switch (slider){
    case 0:
        // RGB
        cout << "cambiando a RGB..." << endl;
        space_color = COLOR_BGR2RGB;
        break;
    case 1:
        // HSV
        cout << "cambiando a HSV..." << endl;
        space_color = COLOR_BGR2HSV;
        break;
    case 2:
        // LAB
        cout << "cambiando a LAB..." << endl;
        space_color = COLOR_BGR2Lab;
        break;
    case 3:
        // YCrCb
        cout << "cambiando a YCrCb..." << endl;
        space_color = COLOR_BGR2YCrCb;
        break;
    case 4:
        //Gray
        cout << "cambiando a Escala de Grises..." << endl;
        space_color = COLOR_BGR2GRAY;
    default:
        break;
    }

    return space_color;
}

void VideoConverter::saveCapture(cv::Mat image){
    fs::create_directory("../images");

    auto time = std::chrono::system_clock::now();
    std::time_t captureTime = std::chrono::system_clock::to_time_t(time);
    string stringTime = to_string(captureTime);
    cout << stringTime << endl;

    cv::imwrite("../images/"+stringTime+".png", image);
}