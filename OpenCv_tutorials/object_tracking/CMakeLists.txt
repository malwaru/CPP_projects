cmake_minimum_required(VERSION 2.8)
## Setting the project name
project( object_tracking )

##asking it to find required packages
find_package( OpenCV REQUIRED )

##Add executable
add_executable( OpenCv1 object_tracking.cpp )
target_link_libraries( OpenCv1 ${OpenCV_LIBS} )
