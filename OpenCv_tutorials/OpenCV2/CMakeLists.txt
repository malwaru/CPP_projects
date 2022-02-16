cmake_minimum_required(VERSION 2.8)
## Setting the project name
project( OpenCv2 )

##asking it to find required packages
find_package( OpenCV REQUIRED )

##Add executable
add_executable( DisplayWebcam OpenCV2.cpp )
target_link_libraries( DisplayWebcam ${OpenCV_LIBS} )
