#include <cstdint>
#include <opencv2/opencv.hpp>
#include "math.h"

using namespace std;
using namespace cv;

void pixel_access();
void split_merge();
void DFT();

int main(int argv, char **argc)
{
//pixel_access();
//split_merge();
//DFT();

   
    return 0;
}

 // =================================================

// Accesing individual pixels

// =================================================
void pixel_access()
{

    Mat src1,src2;
    Mat dst1,dst2;
    
    src1=imread("spacex.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    src2=imread("spacex.jpg");
    dst1=src1.clone();
    dst2=src2.clone();

    for(int r=0;r<dst1.rows;r++)
    {
        for(int c=0;c<dst1.cols;c++)
        {
            dst1.at<uint8_t>(r,c)=dst1.at<uint8_t>(r,c)*0.5;//unsigned int with 8 bits. cause value range from 0-255
            dst2.at<Vec3b>(r,c)[0]=dst2.at<Vec3b>(r,c)[0]*0;// vector 3 cols of byte(8 bits)

        }
    }

    // imshow("Original",src1);
    // imshow("Dst",dst1);
       imshow("Original2",src2);
       imshow("Dst2",dst2);
    waitKey(10);

    }



//==================================================================
//Splitting and merging images
//==================================================================

void split_merge()
{

   
    Mat original=imread("spacex.jpg");
    Mat Splittting[3];// mat with 3 channels
    Mat Merged;
    split(original,Splittting);

    Splittting[2]=Mat::zeros(Splittting[2].size(),CV_8UC1); // size of zeros mat is size of channel 2
    //                                             8 bits unsinged 1 channel
    
    merge(Splittting,3,Merged);
    //    input mat , 3 is no of output channels, output chanel

    imshow("Merged",Merged);
    waitKey();

}


//==================================================================
// DFT    
//==================================================================
void DFT(){
    Mat original;
    original= imread("spacex.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat originalFloat;
    original.convertTo(originalFloat,CV_32FC1,1.0/255.0); // Scaling the values from 0-255 to 0-1 and make it 

    Mat originalComplex[2]={originalFloat,Mat::zeros(originalFloat.size(),CV_32FC1)};
    Mat dftready;
    merge(originalComplex,2,dftready);

    waitKey();


}


