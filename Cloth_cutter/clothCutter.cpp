#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>


using namespace cv;
using namespace std;

int fil1_min,fil1_max,erosion_size,fil1_proceed;


int thres_max,thres_min,conto;



Mat imgOri,imgGray,imgErode,imgBlur,imgEdge,imgHSV;
Mat dst;
Mat canny_output;
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
RNG rng(12345);

void filterOne(int , void*);

void trackMax(int , void*);
void trackMin(int , void*);
void contoFind(int , void*);
void edgefind(int &thresmax_ ,int &thresmin_);




int main(int argc, char** argv)
{

    

    imgOri=imread("cloth2.jpg");
    if ( !imgOri.data )
    {
        cout<<"No Image "<<endl;
        return -1;
    }

    thres_min=0;
    thres_max=100;
    fil1_max=255;
    
    fil1_proceed=1;// this stops it from moving foward in the loop 
    
    
    dst.create(imgOri.size(),imgOri.type());
    cvtColor(imgOri,imgGray,CV_RGB2GRAY);
    dst=imgOri;
   // namedWindow("Original", WINDOW_NORMAL);
   // resizeWindow("Original",1000,2000);
   // imshow("Original",imgGray);


    // Filterout the white patches and black lines


    namedWindow("Filter1", WINDOW_NORMAL);
    resizeWindow("Filter1",1000,2000);
    createTrackbar("Max Value","Filter1",&fil1_max,255,filterOne);
    createTrackbar("Min Value","Filter1",&fil1_min,125,filterOne);
    createTrackbar("Erosion Kernal","Filter1",&erosion_size,21,filterOne);
    createTrackbar("Edge","Filter1",&fil1_proceed,300,filterOne);

    filterOne(0 , 0);
    
    blur(imgGray,imgBlur,Size(3,3));

    waitKey(0);

    return 0;
    



}

void filterOne(int , void*)
{
    inRange(imgGray, Scalar(fil1_min), Scalar(fil1_max),dst);
    
    Mat element = getStructuringElement(MORPH_CROSS,Size(2*erosion_size+1,2*erosion_size+1),Point(erosion_size,erosion_size));
        
    erode( dst,imgErode, element );
    imshow("Filter1",imgErode);

    if(fil1_proceed>50)
    {
        blur(imgErode,imgBlur,Size(3,3)); 
    
    // canny edge 
        namedWindow("Display Image", WINDOW_NORMAL);
        createTrackbar("Max Value","Display Image",&thres_max,255,trackMax);
        createTrackbar("Min Value","Display Image",&thres_min,100,trackMin);
        createTrackbar("Contour","Display Image",&conto,300,contoFind);
    

        edgefind(thres_max,thres_min);


    }
    


}


void edgefind(int &thresmax_ , int &thresmin_)
{
    
    
if(fil1_proceed>50)
{
    

    Canny(imgBlur,imgEdge,thresmin_,thres_max,3);    
    resizeWindow("Display Image",1000,2000);
    imshow("Display Image",imgEdge);
    //dst = Scalar::all(0);
    //imgOri.copyTo( dst, imgEdge); // i think this is a masking function. adding all non zero values to the empty dst mat
}
      

}

void trackMax(int , void*)
{
    edgefind(thres_max,thres_min);

    

}

void trackMin(int , void*)
{
    edgefind(thres_max,thres_min);

}

void contoFind(int , void*)
{

if(conto>=50)
{
findContours(imgEdge, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

  /// Draw contours
  Mat drawing = Mat::zeros( imgEdge.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
     }

  /// Show in a window
  namedWindow( "Contours", WINDOW_NORMAL );
  resizeWindow("Contours",100,200);
  imshow("Contours",drawing );
}


}