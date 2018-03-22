#include "../config.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    const std::string ruta = config::sourceDir + "/ejemplos/Lenna.png";

    Mat image;
    image = imread(ruta, 1);

    if (image.data == nullptr) {
        throw std::runtime_error("No se puedo cargar la imagen");
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey();

    return 0;
}
