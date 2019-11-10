#include <opencv2/opencv.hpp>
#include "Negative_Log_Gamma.hpp"

void Image_Nagetive(){

    cv::Mat image = cv::imread("D:/image/imageProcessing/DIP3E_Original_Images_CH03/Fig0304(a)(breast_digital_Xray).tif", cv::IMREAD_GRAYSCALE);
    cv::namedWindow("Window");

    //show original image
    cv::displayOverlay("Window", "Original image", 0);
    cv::imshow("Window", image);
    cv::waitKey(0);

    //negative

    //1.subtract directly
    /*
     * image = 255 - image;
     */
    //2.access by pointer
    /*
     * for(int i = 0; i != image.rows; ++i){
     *  for(int j = 0; j != image.cols; ++j){
     *       *image.ptr<uchar>(i, j) = 255 - *image.ptr<uchar>(i, j);
     *   }
     * }
     */
    //3.access by iterator
    for(cv::MatIterator_<uchar> it = image.begin<uchar>(); it != image.end<uchar>(); ++it){
        *it = 255 - *it;
    }

    //show negative image
    cv::displayOverlay("Window", "Negative image", 0);
    cv::imshow("Window", image);
    cv::waitKey(0);
}
