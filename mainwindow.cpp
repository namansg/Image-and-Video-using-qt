#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDisplay_Image_triggered()
{
    cv::Mat inputImage = cv::imread("/home/naman/lena.jpg");
    cv::imshow("Display Image",inputImage);
}

void MainWindow::on_actionRecord_Video_triggered()
{
    cvNamedWindow( "Display Video", CV_WINDOW_AUTOSIZE );
   // CvCapture* capture = cvCreateFileCapture("/home/naman/video.mp4" );
    CvCapture *capture=   cvCreateCameraCapture(0);
    IplImage* frame;
    while(1) {
        frame = cvQueryFrame( capture );
        if( !frame ) break;
        cvShowImage( "Display Video" , frame );
        char c = cvWaitKey(33);
        if( c == 27 ) break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Display Video" );
}

void MainWindow::on_actionDisplay_Video_triggered()
{
    cvNamedWindow( "Display Video", CV_WINDOW_AUTOSIZE );
    CvCapture* capture = cvCreateFileCapture("/home/naman/video.mp4" );
    //CvCapture *capture=cvCreateCameraCapture(0);
    IplImage* frame;
    while(1) {
        frame = cvQueryFrame( capture );
        if( !frame ) break;
        cvShowImage( "Display Video", frame );
        char c = cvWaitKey(33);
        if( c == 27 ) break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Display Video" );
}
