# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/crystalized/cpp_project/myRender/myGraphicEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/crystalized/cpp_project/myRender/myGraphicEngine/build

# Include any dependencies generated for this target.
include Eigen/blas/testing/CMakeFiles/dblat1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Eigen/blas/testing/CMakeFiles/dblat1.dir/compiler_depend.make

# Include the progress variables for this target.
include Eigen/blas/testing/CMakeFiles/dblat1.dir/progress.make

# Include the compile flags for this target's objects.
include Eigen/blas/testing/CMakeFiles/dblat1.dir/flags.make

Eigen/blas/testing/CMakeFiles/dblat1.dir/dblat1.f.o: Eigen/blas/testing/CMakeFiles/dblat1.dir/flags.make
Eigen/blas/testing/CMakeFiles/dblat1.dir/dblat1.f.o: /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/blas/testing/dblat1.f
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building Fortran object Eigen/blas/testing/CMakeFiles/dblat1.dir/dblat1.f.o"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/blas/testing && /opt/homebrew/bin/gfortran $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -c /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/blas/testing/dblat1.f -o CMakeFiles/dblat1.dir/dblat1.f.o

Eigen/blas/testing/CMakeFiles/dblat1.dir/dblat1.f.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing Fortran source to CMakeFiles/dblat1.dir/dblat1.f.i"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/blas/testing && /opt/homebrew/bin/gfortran $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -E /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/blas/testing/dblat1.f > CMakeFiles/dblat1.dir/dblat1.f.i

Eigen/blas/testing/CMakeFiles/dblat1.dir/dblat1.f.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling Fortran source to assembly CMakeFiles/dblat1.dir/dblat1.f.s"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/blas/testing && /opt/homebrew/bin/gfortran $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -S /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/blas/testing/dblat1.f -o CMakeFiles/dblat1.dir/dblat1.f.s

# Object files for target dblat1
dblat1_OBJECTS = \
"CMakeFiles/dblat1.dir/dblat1.f.o"

# External object files for target dblat1
dblat1_EXTERNAL_OBJECTS =

Eigen/blas/testing/dblat1: Eigen/blas/testing/CMakeFiles/dblat1.dir/dblat1.f.o
Eigen/blas/testing/dblat1: Eigen/blas/testing/CMakeFiles/dblat1.dir/build.make
Eigen/blas/testing/dblat1: Eigen/blas/libeigen_blas.dylib
Eigen/blas/testing/dblat1: Eigen/blas/testing/CMakeFiles/dblat1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking Fortran executable dblat1"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/blas/testing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dblat1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Eigen/blas/testing/CMakeFiles/dblat1.dir/build: Eigen/blas/testing/dblat1
.PHONY : Eigen/blas/testing/CMakeFiles/dblat1.dir/build

Eigen/blas/testing/CMakeFiles/dblat1.dir/clean:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/blas/testing && $(CMAKE_COMMAND) -P CMakeFiles/dblat1.dir/cmake_clean.cmake
.PHONY : Eigen/blas/testing/CMakeFiles/dblat1.dir/clean

Eigen/blas/testing/CMakeFiles/dblat1.dir/depend:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crystalized/cpp_project/myRender/myGraphicEngine /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/blas/testing /Users/crystalized/cpp_project/myRender/myGraphicEngine/build /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/blas/testing /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/blas/testing/CMakeFiles/dblat1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Eigen/blas/testing/CMakeFiles/dblat1.dir/depend

