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
include Eigen/test/CMakeFiles/fastmath.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Eigen/test/CMakeFiles/fastmath.dir/compiler_depend.make

# Include the progress variables for this target.
include Eigen/test/CMakeFiles/fastmath.dir/progress.make

# Include the compile flags for this target's objects.
include Eigen/test/CMakeFiles/fastmath.dir/flags.make

Eigen/test/CMakeFiles/fastmath.dir/fastmath.cpp.o: Eigen/test/CMakeFiles/fastmath.dir/flags.make
Eigen/test/CMakeFiles/fastmath.dir/fastmath.cpp.o: /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/fastmath.cpp
Eigen/test/CMakeFiles/fastmath.dir/fastmath.cpp.o: Eigen/test/CMakeFiles/fastmath.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Eigen/test/CMakeFiles/fastmath.dir/fastmath.cpp.o"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Eigen/test/CMakeFiles/fastmath.dir/fastmath.cpp.o -MF CMakeFiles/fastmath.dir/fastmath.cpp.o.d -o CMakeFiles/fastmath.dir/fastmath.cpp.o -c /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/fastmath.cpp

Eigen/test/CMakeFiles/fastmath.dir/fastmath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fastmath.dir/fastmath.cpp.i"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/fastmath.cpp > CMakeFiles/fastmath.dir/fastmath.cpp.i

Eigen/test/CMakeFiles/fastmath.dir/fastmath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fastmath.dir/fastmath.cpp.s"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/fastmath.cpp -o CMakeFiles/fastmath.dir/fastmath.cpp.s

# Object files for target fastmath
fastmath_OBJECTS = \
"CMakeFiles/fastmath.dir/fastmath.cpp.o"

# External object files for target fastmath
fastmath_EXTERNAL_OBJECTS =

Eigen/test/fastmath: Eigen/test/CMakeFiles/fastmath.dir/fastmath.cpp.o
Eigen/test/fastmath: Eigen/test/CMakeFiles/fastmath.dir/build.make
Eigen/test/fastmath: Eigen/test/CMakeFiles/fastmath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fastmath"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fastmath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Eigen/test/CMakeFiles/fastmath.dir/build: Eigen/test/fastmath
.PHONY : Eigen/test/CMakeFiles/fastmath.dir/build

Eigen/test/CMakeFiles/fastmath.dir/clean:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && $(CMAKE_COMMAND) -P CMakeFiles/fastmath.dir/cmake_clean.cmake
.PHONY : Eigen/test/CMakeFiles/fastmath.dir/clean

Eigen/test/CMakeFiles/fastmath.dir/depend:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crystalized/cpp_project/myRender/myGraphicEngine /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test/CMakeFiles/fastmath.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Eigen/test/CMakeFiles/fastmath.dir/depend

