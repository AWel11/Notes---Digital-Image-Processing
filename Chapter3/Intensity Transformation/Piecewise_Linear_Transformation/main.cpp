#include <iostream>
#include <opencv2/opencv.hpp>
#include "piecewise_linear_transformation.h"

using namespace std;

int main()
{
    //Contrast Stretch
//    Piecewise_Linear_Transformation image("D:/image/imageProcessing/DIP3E_Original_Images_CH03/Fig0310(b)(washed_out_pollen_image).tif");
//    image.imshow("Original image", "Window_original");
//    cv::waitKey(0);
//    //contrast stretch with MaxMin
//    Piecewise_Linear_Transformation contrast_stretching_MaxMin(image);
//    contrast_stretching_MaxMin.contrast_stretching(cv::Point(contrast_stretching_MaxMin.minIntensity(), 0),
//                                            cv::Point(contrast_stretching_MaxMin.maxIntensity(), L-1));
//    contrast_stretching_MaxMin.imshow("Contrast stretching MaxMin image", "Window_contrast_stretching_MaxMin");
//    cv::waitKey(0);
//    //contrast stretch with threshold(Madian)
//    Piecewise_Linear_Transformation contrast_stretching_Madian(image);
//    contrast_stretching_Madian.contrast_stretching(cv::Point(contrast_stretching_Madian.madianIntensity(), 0),
//                                                   cv::Point(contrast_stretching_Madian.madianIntensity(), L-1));
//    contrast_stretching_Madian.imshow("Contrast stretch Madian image", "Window_contrast_stretching_Madian");

    //Bit-Plane Slicing
    Piecewise_Linear_Transformation image ("D:/image/imageProcessing/DIP3E_Original_Images_CH03/Fig0314(a)(100-dollars).tif");
    image.imshow("Original image", "Window_original");
    cv::waitKey(0);

    for(int i = 1; i <= 8; ++i){
        Piecewise_Linear_Transformation bitPlane_slicing("D:/image/imageProcessing/DIP3E_Original_Images_CH03/Fig0314(a)(100-dollars).tif");
        bitPlane_slicing.bitPlane_slicing_255_0(i);
        std::string overlay = "Bit plane " + std::to_string(i);
        bitPlane_slicing.imshow(overlay, "Window "+overlay);
        cv::waitKey(0);
    }

    //Image reconstructed using 8，7    8，7，6    8，7，6，5
    cv::Mat reconstructed = cv::Mat::zeros(image.getImage().rows, image.getImage().cols, CV_8UC1);
    cv::namedWindow("Reconstructed");
    for(int i = 8; i >= 5; --i){
        Piecewise_Linear_Transformation bitPlane_slicing("D:/image/imageProcessing/DIP3E_Original_Images_CH03/Fig0314(a)(100-dollars).tif");
        bitPlane_slicing.bitPlane_slicing_bitValue_0(i);
        reconstructed += bitPlane_slicing.getImage();
        if(i != 8){
            cv::displayOverlay("Reconstructed", "Bit Plane 8~" + std::to_string(i), 0);
            cv::imshow("Reconstructed", reconstructed);
            cv::waitKey(0);
        }
    }

    return 0;
}
