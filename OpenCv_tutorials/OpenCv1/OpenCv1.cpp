#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
// g++ OpenCv1.cpp -o output `pkg-config --cflags --libs opencv`

/*
Instead of above GCC can use cmake for the same to do the same thing 
Step 1 : create a txt filed lablled "CMakeLists.txt" and type the following and save it. In here I used "Opencv1" as the project name

        cmake_minimum_required(VERSION 2.8)
        ## Setting the project name
        project( OpenCv1 )

        ##asking it to find required packages
        find_package( OpenCV REQUIRED )

        ##Add executable
        add_executable( OpenCv1 OpenCv1.cpp )
        target_link_libraries( OpenCv1 ${OpenCV_LIBS} )


Step 2: In the terminal cd into the directory with the source code

Step 3: Type "cmake ."
        Remember the dot at the end is important

Step 4 : Type "make"
         After this all the exceutbales are created in this case the name of the exceutable is also Opencv1
Step 5 : Type "./OpenCv1"

*/

int main(int argc, char** argv )
{
   
    Mat image;
    //image = imread( argv[1], 1 );
    image =imread("spacex.jpg");
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    Mat grey;

    cvtColor(image,grey,COLOR_BGR2GRAY);
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    namedWindow("Grey Image", WINDOW_AUTOSIZE );
    
    imshow("Display Image", image);
    imshow("Grey Image",grey);

    waitKey(0);

    return 0;
}



   

    
