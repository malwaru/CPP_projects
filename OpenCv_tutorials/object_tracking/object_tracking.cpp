// Good format for licensing

//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software")
//, to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
//and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//IN THE SOFTWARE.

//Libraries

#include <string>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "math.h"

// Namespaces
using namespace cv;
using namespace std;

// Variables 
Mat frame;
Mat frame_filetered;
int H_max,H_min,S_max,S_min,V_max,V_min; // the HSV values used for filtering
bool calib_done=false; // check to see if calibration is done
int X_O,Y_O;// origin location of the object/default capture width and height
stringstream ss_x; // the same x_o and y_o as a string to printed
stringstream ss_y;
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;
//max number of objects to be detected in frame
const int MAX_NUM_OBJECTS=40;
//minimum and maximum object area
const int MIN_OBJECT_AREA = 20*20;
const int MAX_OBJECT_AREA = floor(FRAME_HEIGHT*FRAME_WIDTH /1.5); // if
// area detected is larger than the 2/3 of the frame its probabaly a 
// bad filter



//Functions
void calibration(bool &calib_done);
void trackbar_callback( int, void* );
void drawObject(int x, int y,Mat &frame);
void trackObject();
void button_click_1(int event, int x, int y, int flags, void* userdata);


//Main function
int main(int argv,char** argc)
{


 

    calibration(calib_done);
    //delete &calib_done;
    cout<<"the H S V values are " <<" H Max"<<H_max<<" H Min "<<H_min<<" S Max "<<S_max<<" S Min "<<S_min<<" V Max "<<V_max<<" V Min "<<V_min<<endl;

    trackObject();





    return 0;    
}





void calibration(bool &calib_done)
{
    Mat original,dst,button;
    VideoCapture stream1(0);
    namedWindow("Filter",WINDOW_AUTOSIZE);
    namedWindow("Filtered Image",WINDOW_AUTOSIZE);
    resizeWindow("Filter",500,500);
    setMouseCallback("Filter",button_click_1);
    button=Mat::zeros(500,500,CV_8UC3);

    Rect RectangleToDraw3(50,20,400,400); // the coordinates of starting point and lenght and width

    rectangle(button, RectangleToDraw3, Scalar(0, 250, 0), 1 ,8, 0); // the image matrix button , the defined rectangle , BGR colour , line properties  
    imshow("Filter",button);
    
    //initalize H S V values 
    H_max=256;
    S_max=256;
    V_max=256;
    
    createTrackbar("H Min","Filter",&H_min,256,trackbar_callback);
    createTrackbar("H Max","Filter",&H_max,256,trackbar_callback);    
    createTrackbar("S Min","Filter",&S_min,256,trackbar_callback);
    createTrackbar("S Max","Filter",&S_max,256,trackbar_callback);    
    createTrackbar("V Min","Filter",&V_min,256,trackbar_callback);
    createTrackbar("V Max","Filter",&V_max,256,trackbar_callback);
    trackbar_callback(H_max,0);

    while((!calib_done) && (stream1.isOpened()))
    {
    
        stream1.read(original);
        cvtColor(original,original,CV_BGR2HSV);

        inRange(original,Scalar(H_min,S_min,V_min),Scalar(H_max,S_max,V_max),dst); // filter out the HSV values 
        imshow("Filtered Image",dst);

        
        waitKey(30);

    }
    destroyAllWindows();
    
    
}





void trackObject()
{

    Mat frame,temp,morphed;
    namedWindow("tracked",WINDOW_AUTOSIZE);
    resizeWindow("tracked",FRAME_WIDTH,FRAME_HEIGHT);

    VideoCapture stream2(0);
    stream2.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
    stream2.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
    
    while (true)
    {
        stream2.read(frame);
        cvtColor(frame,temp,COLOR_BGR2HSV);
        /*
        H_max=95;
        S_max=188;
        V_max=198;
        H_min=46;
        S_min=43;
        V_min=49;
        */
        // Filter out the image to find contours
        inRange(temp,Scalar(H_min,S_min,V_min),Scalar(H_max,S_max,V_max),temp);
        Mat erode_element=getStructuringElement(MORPH_RECT,Size(3,3));
        Mat dilate_element=getStructuringElement( MORPH_RECT,Size(3,3));

        erode(temp,morphed,erode_element);
        erode(morphed,morphed,erode_element);
        dilate(morphed,morphed,dilate_element);
        dilate(morphed,morphed,dilate_element);
         

        //Finding the contours and moments
        vector <vector<Point>> contours; // each contour as an vector of points . 
                                        // all the above contour vectors are in a vector.
                                        // hence the vector of vector points
        vector <Vec4i> hierachy; // [Next, Previous, First_Child, Parent] 
                                 // hence a vector containing vectors each with 4 int values

        findContours(morphed,contours,hierachy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE);


        double refArea=0; // when iterating through all detected contours this make
                          // sure we are only output the largest area i.e. the target
        
        bool objectFound=false;
       
       if(hierachy.size()>0 && hierachy.size()<MAX_NUM_OBJECTS)
       {
           int numObjects=hierachy.size();


           /* hierarchy – Optional output vector, containing information about the image topology. It 
                has as many elements as the number of contours. For each i-th contour
                 contours[i] , the elements hierarchy[i][0] , hiearchy[i][1] , hiearchy[i][2] , and hiearchy[i][3]
                  are set to 0-based indices in contours of the next and previous contours at the same hierarchical level, 
                  the first child contour and the parent contour, respectively.
                   If for the contour i there are no next, previous, parent, or nested contours, 
                   the corresponding elements of hierarchy[i] will be negative.
                */

               // Therefore the index changed until it becomes negative i.e no more contours

           for(int index=0;index>=0;index=hierachy[index][0])
           {
             Moments moment = moments((cv::Mat)contours[index]);
             double area = moment.m00;

             // check if its bigger than 20*20 , less than 2/3 area and bigger than the 
                    // previous calculated area
            
          

             if(area>MIN_OBJECT_AREA && area<MAX_OBJECT_AREA && area>refArea)
             {


                 /* M moments
                        m p,q = ∑ I ( x i , y i ) x (p) *y (q)
                        i=1
                        In this expression, the moment m p,q is defined as a sum over all of the pixels in the
                        object, in which the value of the pixel at point x, y is multiplied by the factor x p y q . In
                        the case of the m 00 moment, this factor is equal to 1 —so if the image is a binary image
                        (i.e., one in which every pixel is either 0 or 1 ), then m 00 is just the area of the nonzero

                        */
                   X_O=moment.m10/area;
                   Y_O=moment.m01/area;
                        
                   objectFound=true;
                   refArea=area;


                

             }

             else
             {
                 objectFound=false;
             }
             



           }
           
            // if object found is true
            if(objectFound)
            {

                putText(frame,"Tracking Object",Point(0,50),2,1,Scalar(0,255,0),2);
                 //draw object location on screen
                drawObject(X_O,Y_O,frame);
               
                

            }



            else
            {
                putText(frame,"Object not detected",Point(100,200),1,2,Scalar(0,200,0),2);
                
            }

           
        






       

       }
      else
      {
          putText(frame,"Too much noise!! Adjust filter",Point(100,200),1,2,Scalar(0,0,255),2);
          
      }
      
 

       // imshow("tracked",morphed);
        imshow("new",frame);

        waitKey(10);

    }



}

    
    
void drawObject(int x, int y,Mat &frame)
{

    circle(frame,Point(x,y),20,Scalar(0,0,255),2);
    if(y-25>0)
    line(frame,Point(x,y),Point(x,y-25),Scalar(0,255,0),2);
    else line(frame,Point(x,y),Point(x,0),Scalar(0,255,0),2);
    if(y+25<FRAME_HEIGHT)
    line(frame,Point(x,y),Point(x,y+25),Scalar(0,255,0),2);
    else line(frame,Point(x,y),Point(x,FRAME_HEIGHT),Scalar(0,255,0),2);
    if(x-25>0)
    line(frame,Point(x,y),Point(x-25,y),Scalar(0,255,0),2);
    else line(frame,Point(x,y),Point(0,y),Scalar(0,255,0),2);
    if(x+25<FRAME_WIDTH)
    line(frame,Point(x,y),Point(x+25,y),Scalar(0,255,0),2);
    else line(frame,Point(x,y),Point(FRAME_WIDTH,y),Scalar(0,255,0),2);

    putText(frame,to_string(x)+","+to_string(y),Point(x,y+30),1,1,Scalar(0,255,0),2);



}





// Auxilary functions


void trackbar_callback(int , void*)
{
   

}

void button_click_1(int event, int x_ROI, int y_ROI, int flags, void* userdata)
{



    if((event==EVENT_LBUTTONDOWN) && ((50<x_ROI<450)&&(20<y_ROI<420))) // the borders of the button 
    {
        //cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
        calib_done=true; // if button is clicked calibration is done

    }


}
