cmake_minimum_required(VERSION 3.0)
## Setting the project name
project( qrcodereader )

##asking it to find required packages
find_package( OpenCV REQUIRED )

##Add executable
add_executable( qrread qrcode.cpp )
target_link_libraries( qrread ${OpenCV_LIBS} )
