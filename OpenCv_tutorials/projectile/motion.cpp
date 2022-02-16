#include "motion.h"
int Rd,Gr,Bl;
int bt1; // use trackbar as a button 
Mat cali_vid; // mat for calibration of colour
Mat cali_vid_dst;



void filter(int, void*); // defined function for trackbar

/*
=========================================================================
Start of Constructors
=========================================================================
*/
motion::motion()
{

    
}

motion::motion(int _b,int _g, int _r)
{
Blue=_b;
Red=_r;
Green=_g;

    
}

motion::~motion()
{

}
/*
=========================================================================
Start of Methods
=========================================================================
*/



/////////////////////////////////////////
// The method to calibate the RGB values
////////////////////////////////////////

int motion::calib()
{
   
    namedWindow("Cali_vid",WINDOW_AUTOSIZE);
    createTrackbar("R","Cali_vid",&Bl,128,filter);
    createTrackbar("G","Cali_vid",&Gr,128,filter);
    createTrackbar("B","Cali_vid",&Rd,128,filter);
    createTrackbar("Complete","Cali_vid",&bt1,128,filter);
    
    bt1=0;
    
    
    VideoCapture Stream(0);

    if(!Stream.isOpened())
    {
        cout<<"no video"<<endl;
    }

    else 
    {
    
        cout<<"entered filter loop"<<endl;
        cali_vid_dst=cali_vid.clone();// just make sure dst mat is of the same size 
        while (bt1<50)
        {
        Stream.read(cali_vid);
        //inRange(cali_vid,Scalar(Bl,Gr,Rd), Scalar((256-Bl),(256-Gr),(256-Rd)),cali_vid_dst);
        imshow("Cali_vid",cali_vid_dst);
        waitKey(10);   
        }
            
           
   
    

    }
Blue=Bl;
Green=Gr;
Red=Rd;
return Blue,Green,Red;

}
    // Function for trackbar
    void filter(int, void*)
    {
        
        inRange(cali_vid,Scalar(Rd,Gr,Bl), Scalar((256-Rd),(256-Gr),(256-Bl)),cali_vid_dst);
        //   imshow("Cali_vid",cali_vid_dst);
        //   waitKey(30);
        

    }

/////////////////////////////////////////
// The method to track the colored object
////////////////////////////////////////

void motion::track(int &Blue, int &Green, int &Red)
{



}

/////////////////////////////////////////
// The method to communicate with Arduino
////////////////////////////////////////

int motion::tran_ceiver(int _action)
{


return 0;

}



