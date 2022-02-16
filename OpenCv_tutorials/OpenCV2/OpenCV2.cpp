// This program takes in video streams from two video cameras and apply canny edge detedtion for that.

#include <iostream>
#include <stdio.h> // Library to get key inputs
#include <opencv2/opencv.hpp>
#include <time.h>
#include <vector>

using namespace std;
using namespace cv;
using std::vector;
using std::to_string;


void displayWindows(vector<Mat>& frames)
{
    // iterate through the frames
    for(int index = 0; index < frames.size(); ++index)
    {
        // index allows us to assign a unique name to each window
        // windows will be titled 'Window 0', 'Window 1', 'Window 2'... until frames.size()-1
        String windowTitle = "Camera " + to_string(index);

        imshow(windowTitle,frames[index]);
    }
}




int main(int argc, char** argv)
{
    VideoCapture stream2(2);
    VideoCapture stream1(0);
    Mat gray,edge,gray2,edge2;
    Mat frame1,frame2,frame3;

    clock_t start = clock();
    double elapsed=0;
    if(!stream1.isOpened()){

        cout <<"Camera not opened" << endl;
    }
    else{
        while(elapsed<1000)
        {
        stream1.read(frame1);
        stream2.read(frame2);
        
        printf("Camera capturing....\n");

        cvtColor(frame1, gray, CV_BGR2GRAY); //
        blur(gray,edge, Size(5,5));        //
        Canny(edge,edge, 1, 12);            //

        
       // imshow("Capture",edge);
        waitKey(30);

        cvtColor(frame2, gray2, CV_BGR2GRAY); //
        blur(gray2,edge2, Size(5,5));        //
        Canny(edge2,edge2, 1, 12);            //

    
       
        vector<Mat>images{edge,edge2};

        displayWindows(images);
       

        waitKey(30);
        clock_t stop = clock();

        elapsed = double(stop - start) / CLOCKS_PER_SEC;
        
        }

    }
    
    return 0;





}