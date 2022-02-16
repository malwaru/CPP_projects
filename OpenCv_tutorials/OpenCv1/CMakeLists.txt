cmake_minimum_required(VERSION 2.8)
## Setting the project name
project( OpenCv1 )

##asking it to find required packages
find_package( OpenCV REQUIRED )

##Add executable
add_executable( OpenCv1 OpenCv1.cpp )
target_link_libraries( OpenCv1 ${OpenCV_LIBS} )
