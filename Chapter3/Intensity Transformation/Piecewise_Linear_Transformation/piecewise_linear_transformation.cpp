#include "piecewise_linear_transformation.h"

Piecewise_Linear_Transformation::Piecewise_Linear_Transformation(const std::string& filepath)
{
    image = cv::imread(filepath, cv::IMREAD_GRAYSCALE);
}
//contrast stretch
void Piecewise_Linear_Transformation::contrast_stretching(const cv::Point& p1, const cv::Point& p2)
{
    for(auto it = image.begin<uchar>(); it != image.end<uchar>(); ++it){
        if(*it <= p1.x){
            *it *= p1.y/p1.x;
        }else if(*it <= p2.x){
            *it = static_cast<uchar>(p1.y + ((p2.y - p1.y)/(p2.x - p1.x)) * (*it - p1.x));
        }else{
            *it = static_cast<uchar>(p2.y + ((L-1 - p2.y)/(L-1 - p2.x)) * (*it - p2.x));
        }
    }
}
//bit-plane slicing
void Piecewise_Linear_Transformation::bitPlane_slicing_255_0(int bitPlane){
    for(auto it = image.begin<uchar>(); it != image.end<uchar>(); ++it){
        *it = static_cast<uchar>((static_cast<int>(*it)>>(bitPlane-1) & 1) == 1 ? 255 : 0);   //Notice!!!
    }                                                                                         //比一个数大不一定包含它，所以不能简单 >=
}                                                                                             //而要先移位，再用 位与& 和1进行比较
void Piecewise_Linear_Transformation::bitPlane_slicing_bitValue_0(int bitPlane){
    for(auto it = image.begin<uchar>(); it != image.end<uchar>(); ++it){
        *it = static_cast<uchar>((static_cast<int>(*it)>>(bitPlane-1) & 1) == 1 ? (1<<(bitPlane-1)) : 0);
    }
}

uchar Piecewise_Linear_Transformation::maxIntensity(){
    uchar max = 0;
    for(auto it = image.begin<uchar>(); it != image.end<uchar>(); ++it){
        if(*it > max){
            max = *it;
        }
    }
    return max;
}
uchar Piecewise_Linear_Transformation::minIntensity(){
    uchar min = L-1;
    for(auto it = image.begin<uchar>(); it != image.end<uchar>(); ++it){
        if(*it < min){
            min = *it;
        }
    }
    return min;
}
uchar Piecewise_Linear_Transformation::madianIntensity(){
    std::vector<uchar> uvec;
    for(auto it = image.begin<uchar>(); it != image.end<uchar>(); ++it){
        uvec.push_back(*it);
    }
    std::sort(uvec.begin(), uvec.end());
    return *(uvec.begin() + (uvec.end()-uvec.begin())/2);
}

//get image
cv::Mat Piecewise_Linear_Transformation::getImage(){
    return image;
}
//imshow
void Piecewise_Linear_Transformation::imshow(const std::string& overlay, const std::string& windowName)
{
    cv::namedWindow(windowName);
    cv::displayOverlay(windowName, overlay, 0);
    cv::imshow(windowName, image);
}
