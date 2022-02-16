#include <iostream>
#include "stdio.h"
#include "motion.h"
using namespace std;



int main()
{

cout<<"Main loop initiated"<< endl;

motion *Start_Calib=new motion(0,0,0);

Start_Calib->calib();

delete Start_Calib;// delete the memory after use 




};
