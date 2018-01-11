#include "testclass.h"
#include "mainwindow.h"

#include "opencv2/calib3d.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

TestClass::TestClass(QWidget *parent) : QWidget(parent)
{

}

TestClass::~TestClass() {}

void TestClass::showCVLogo()
{
    // QString filename = "logo.png";
    Mat pic = imread("logo.png", CV_LOAD_IMAGE_COLOR);
    imshow("Testbild", pic);
}


void TestClass::closeCVLogo()
{
    cvDestroyWindow("Testbild");
}
