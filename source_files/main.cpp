#include "../header_files/header.hpp"

Mat frame;
Mat newFrame;
VideoConverter converter;

const int MAX_SPACE_COLOR = 4;
int slider = 0;
int spaceColor;

void onTrackbar(int v, void *data){
    spaceColor = converter.changeSpaceColor(slider);
}

void onMouseCallback(int event, int x, int y, int flag, void* userData){
    if  ( event == EVENT_LBUTTONDOWN ) {
        converter.saveCapture(newFrame);
    }
}

int main(int, char**) {
    VideoCapture video(0);

    if(video.isOpened()){
        namedWindow("Video Original", WINDOW_AUTOSIZE);
        namedWindow("Video Nuevo", WINDOW_AUTOSIZE);

        while(3==3){
            video >> frame;
            flip(frame, frame, 1);

            if(newFrame.empty()){
                newFrame = frame.clone();
            }
            
            createTrackbar("Colorspace", "Video Original", &slider, MAX_SPACE_COLOR, onTrackbar);
            cvtColor(frame, newFrame, spaceColor);
            imshow("Video Original", frame);
            imshow("Video Nuevo", newFrame);

            setMouseCallback("Video Nuevo", onMouseCallback, NULL);

            if(waitKey(23) == 27){
                break;
            }
        }

        video.release();
    }

    waitKey(0); 
    destroyAllWindows();

    return 0;
}
