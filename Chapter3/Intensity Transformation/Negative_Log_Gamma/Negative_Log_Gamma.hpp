#ifndef NEGATIVE_LOG_GAMMA_HPP
#define NEGATIVE_LOG_GAMMA_HPP

#include <opencv2/opencv.hpp>

#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT 980

class Negative_Log_Gamma{
    public:
        Negative_Log_Gamma() = default;
        Negative_Log_Gamma(const std::string& filepath);
        Negative_Log_Gamma(cv::Mat& img): image(img) {}

        //negative
        void image_Negative();
        //gamma
        void gamma_transformation(double c, double gamma);

        cv::Mat getImage();
        void imshow(const std::string& overlay, const std::string& windowName);
  private:
        cv::Mat image;

};

#endif // NEGATIVE_LOG_GAMMA_HPP
