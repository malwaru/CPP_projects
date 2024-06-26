#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/aruco.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/calib3d.hpp"

#include <iostream>
#include <sstream>
#include <fstream>



using namespace std;
using namespace cv;

const float calibSquareDimension;


void create_aruco();

int main(int argv , char** argc)
{

create_aruco();

return 0;
}

void create_aruco()
{
Mat outputMarker;
//create dictionary object to save the templates of aruco. we chose the 5x5 by 50 images
Ptr<aruco::Dictionary> markerDictionary = aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME::DICT_4X4_50);

for(int i=0;i<50;i++)
{
    // chose no of pixels as 500 not sure why.
     aruco::drawMarker(markerDictionary,i,500,outputMarker,1);  

      
      ostringstream convert;
        string imageName="4x4Marker_";
       convert << imageName << i <<".jpg";
               // convert to a string
       imwrite(convert.str(),outputMarker);
       
}

}