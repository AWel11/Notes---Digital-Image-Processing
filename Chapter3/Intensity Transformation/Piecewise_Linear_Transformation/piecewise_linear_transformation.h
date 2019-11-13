#ifndef PIECEWISE_LINEAR_TRANSFORMATION_H
#define PIECEWISE_LINEAR_TRANSFORMATION_H

#include <opencv2/opencv.hpp>

#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT 1080
#define       L        256

class Piecewise_Linear_Transformation
{
public:
    Piecewise_Linear_Transformation(const Piecewise_Linear_Transformation& pie): image(pie.image) {}
    Piecewise_Linear_Transformation(const std::string& filepath);
    Piecewise_Linear_Transformation(const cv::Mat& img): image(img) {}

    //contrast stretching
    void contrast_stretching(const cv::Point& p1, const cv::Point& p2);

    //intensity-level slicing

    //bit-plane slicing
    void bitPlane_slicing_255_0(int bitPlane);       //该位为1就赋为255
    void bitPlane_slicing_bitValue_0(int bitPlane);  //该位为1就赋为1<<(bitPlane-1)

    uchar maxIntensity();
    uchar minIntensity();
    uchar madianIntensity();

    //get image
    cv::Mat getImage();
    //show image
    void imshow(const std::string& overlay, const std::string& windowName);
private:
    cv::Mat image;

};

#endif // PIECEWISE_LINEAR_TRANSFORMATION_H
