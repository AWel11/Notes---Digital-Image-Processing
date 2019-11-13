#include <iostream>
#include <opencv2/opencv.hpp>
#include "Negative_Log_Gamma.hpp"

using namespace std;

void Image_Nagetive(cv::Mat& image);

int main()
{
    //negative
//    Negative_Log_Gamma negative("D:/image/imageProcessing/DIP3E_Original_Images_CH03/Fig0304(a)(breast_digital_Xray).tif");
//    negative.imshow("Original image", "Window_original");
//    cv::moveWindow("Window_original", SCREEN_WIDTH/2-negative.getImage().cols, SCREEN_HEIGHT/2-negative.getImage().rows/2);
//    negative.image_Negative();
//    negative.imshow("Negative image", "Window_negative");
//    cv::moveWindow("Window_negative", SCREEN_WIDTH/2, SCREEN_HEIGHT/2-negative.getImage().rows/2);

    //gamma1
    Negative_Log_Gamma gamma("D:/image/imageProcessing/DIP3E_Original_Images_CH03/Fig0308(a)(fractured_spine).tif");
    gamma.imshow("Original image", "Window_original");
    cv::moveWindow("Window_original", SCREEN_WIDTH/2-gamma.getImage().cols, SCREEN_HEIGHT/2-gamma.getImage().rows/2);
    //0.6
    Negative_Log_Gamma gamma_copy1(gamma);
    gamma_copy1.gamma_transformation(1, 0.6);
    gamma_copy1.imshow("gamma : 0.6", "Window_gamma_0.6");
    cv::moveWindow("Window_gamma_0.6", SCREEN_WIDTH/2, SCREEN_HEIGHT/2-gamma.getImage().rows/2);
    cv::waitKey(0);
    //0.4
    Negative_Log_Gamma gamma_copy2(gamma);
    gamma_copy2.gamma_transformation(1, 0.4);
    gamma_copy2.imshow("gamma : 0.4", "Window_gamma_0.4");
    cv::moveWindow("Window_gamma_0.4",  SCREEN_WIDTH/2-gamma.getImage().cols, SCREEN_HEIGHT/2-gamma.getImage().rows/2);
    //0.3
    Negative_Log_Gamma gamma_copy3(gamma);
    gamma_copy3.gamma_transformation(1, 0.3);
    gamma_copy3.imshow("gamma : 0.3", "Window_gamma_0.3");
    cv::moveWindow("Window_gamma_0.3", SCREEN_WIDTH/2, SCREEN_HEIGHT/2-gamma.getImage().rows/2);

    cv::waitKey(0);
}
