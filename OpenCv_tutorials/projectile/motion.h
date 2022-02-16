#include "math.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include <cstdint>
#include <stdio.h>

using namespace cv;
using namespace std;

class motion
{


private:


int Blue,Green,Red;

int tran_ceiver(int _action);

void track(int &Blue, int &Green, int &Red);

//int filter(int _red, int _green, int _blue);


public: 

motion();

motion(int _b, int _g, int _r);

~motion(); // Destructor class

int calib();

};