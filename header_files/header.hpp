#include <iostream>
#include <cstdlib>
#include <cstring>
#include <experimental/filesystem>

#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp> 
#include <opencv2/video/video.hpp> 
#include <opencv2/videoio/videoio.hpp> 

using namespace std;
using namespace cv;

namespace fs = std::experimental::filesystem;


class VideoConverter{
    private:

    public:
        VideoConverter();
        int changeSpaceColor(int);
        void saveCapture(cv::Mat);
};

