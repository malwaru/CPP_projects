# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/malika/Documents/MyProjects/Learn/Cpp/PCL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/malika/Documents/MyProjects/Learn/Cpp/PCL/build

# Include any dependencies generated for this target.
include CMakeFiles/detect_plane.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/detect_plane.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/detect_plane.dir/flags.make

CMakeFiles/detect_plane.dir/src/plane_detection.cpp.o: CMakeFiles/detect_plane.dir/flags.make
CMakeFiles/detect_plane.dir/src/plane_detection.cpp.o: ../src/plane_detection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malika/Documents/MyProjects/Learn/Cpp/PCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/detect_plane.dir/src/plane_detection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/detect_plane.dir/src/plane_detection.cpp.o -c /home/malika/Documents/MyProjects/Learn/Cpp/PCL/src/plane_detection.cpp

CMakeFiles/detect_plane.dir/src/plane_detection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/detect_plane.dir/src/plane_detection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malika/Documents/MyProjects/Learn/Cpp/PCL/src/plane_detection.cpp > CMakeFiles/detect_plane.dir/src/plane_detection.cpp.i

CMakeFiles/detect_plane.dir/src/plane_detection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/detect_plane.dir/src/plane_detection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malika/Documents/MyProjects/Learn/Cpp/PCL/src/plane_detection.cpp -o CMakeFiles/detect_plane.dir/src/plane_detection.cpp.s

# Object files for target detect_plane
detect_plane_OBJECTS = \
"CMakeFiles/detect_plane.dir/src/plane_detection.cpp.o"

# External object files for target detect_plane
detect_plane_EXTERNAL_OBJECTS =

detect_plane: CMakeFiles/detect_plane.dir/src/plane_detection.cpp.o
detect_plane: CMakeFiles/detect_plane.dir/build.make
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_apps.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_outofcore.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_people.so
detect_plane: /usr/lib/x86_64-linux-gnu/libboost_system.so
detect_plane: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
detect_plane: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
detect_plane: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
detect_plane: /usr/lib/x86_64-linux-gnu/libboost_regex.so
detect_plane: /usr/lib/x86_64-linux-gnu/libqhull.so
detect_plane: /usr/lib/libOpenNI.so
detect_plane: /usr/lib/libOpenNI2.so
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkChartsCore-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkInfovisCore-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libfreetype.so
detect_plane: /usr/lib/x86_64-linux-gnu/libz.so
detect_plane: /usr/lib/x86_64-linux-gnu/libjpeg.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpng.so
detect_plane: /usr/lib/x86_64-linux-gnu/libtiff.so
detect_plane: /usr/lib/x86_64-linux-gnu/libexpat.so
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkIOGeometry-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkIOLegacy-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkIOPLY-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkRenderingLOD-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkViewsContext2D-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkViewsCore-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkRenderingContextOpenGL2-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkRenderingOpenGL2-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_surface.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_keypoints.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_tracking.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_recognition.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_registration.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_stereo.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_segmentation.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_features.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_filters.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_sample_consensus.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_ml.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_visualization.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_search.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_kdtree.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_io.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_octree.so
detect_plane: /usr/lib/x86_64-linux-gnu/libpcl_common.so
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkInteractionWidgets-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkFiltersModeling-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkInteractionStyle-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkFiltersExtraction-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkFiltersStatistics-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkImagingFourier-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkalglib-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkFiltersHybrid-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkImagingGeneral-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkImagingSources-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkImagingHybrid-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkRenderingAnnotation-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkImagingColor-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkRenderingVolume-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkIOXML-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkIOXMLParser-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkIOCore-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkRenderingContext2D-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkRenderingFreeType-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libfreetype.so
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkImagingCore-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkRenderingCore-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkCommonColor-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeometry-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkFiltersSources-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeneral-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkCommonComputationalGeometry-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkFiltersCore-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkIOImage-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkCommonExecutionModel-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkCommonDataModel-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkCommonTransforms-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkCommonMisc-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkCommonMath-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkCommonSystem-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkCommonCore-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtksys-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkDICOMParser-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libvtkmetaio-7.1.so.7.1p.1
detect_plane: /usr/lib/x86_64-linux-gnu/libz.so
detect_plane: /usr/lib/x86_64-linux-gnu/libGLEW.so
detect_plane: /usr/lib/x86_64-linux-gnu/libSM.so
detect_plane: /usr/lib/x86_64-linux-gnu/libICE.so
detect_plane: /usr/lib/x86_64-linux-gnu/libX11.so
detect_plane: /usr/lib/x86_64-linux-gnu/libXext.so
detect_plane: /usr/lib/x86_64-linux-gnu/libXt.so
detect_plane: CMakeFiles/detect_plane.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/malika/Documents/MyProjects/Learn/Cpp/PCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable detect_plane"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/detect_plane.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/detect_plane.dir/build: detect_plane

.PHONY : CMakeFiles/detect_plane.dir/build

CMakeFiles/detect_plane.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/detect_plane.dir/cmake_clean.cmake
.PHONY : CMakeFiles/detect_plane.dir/clean

CMakeFiles/detect_plane.dir/depend:
	cd /home/malika/Documents/MyProjects/Learn/Cpp/PCL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/malika/Documents/MyProjects/Learn/Cpp/PCL /home/malika/Documents/MyProjects/Learn/Cpp/PCL /home/malika/Documents/MyProjects/Learn/Cpp/PCL/build /home/malika/Documents/MyProjects/Learn/Cpp/PCL/build /home/malika/Documents/MyProjects/Learn/Cpp/PCL/build/CMakeFiles/detect_plane.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/detect_plane.dir/depend

