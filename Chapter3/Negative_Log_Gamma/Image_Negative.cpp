#include <opencv2/opencv.hpp>
#include "Negative_Log_Gamma.hpp"

//imread constructor
Negative_Log_Gamma::Negative_Log_Gamma(const std::string& filepath){
    image = cv::imread(filepath, cv::IMREAD_GRAYSCALE);
}

//get the image
cv::Mat Negative_Log_Gamma::getImage(){
    return image;
}

//negative
void Negative_Log_Gamma::image_Negative(){

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
}
//gamma
void Negative_Log_Gamma::gamma_transformation(double c, double gamma){
    for(auto it = image.begin<uchar>(); it != image.end<uchar>(); ++it){
        *it = static_cast<uchar>(c * std::pow(*it, gamma));
    }
    cv::normalize(image, image, 0, 255, cv::NORM_MINMAX, -1, cv::noArray());
}

//imshow
void Negative_Log_Gamma::imshow(const std::string& overlay, const std::string& windowName){
    cv::namedWindow(windowName);
    cv::displayOverlay(windowName, overlay, 0);
    cv::imshow(windowName, image);
}
