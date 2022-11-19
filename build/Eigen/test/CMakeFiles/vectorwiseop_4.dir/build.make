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
include Eigen/test/CMakeFiles/vectorwiseop_4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Eigen/test/CMakeFiles/vectorwiseop_4.dir/compiler_depend.make

# Include the progress variables for this target.
include Eigen/test/CMakeFiles/vectorwiseop_4.dir/progress.make

# Include the compile flags for this target's objects.
include Eigen/test/CMakeFiles/vectorwiseop_4.dir/flags.make

Eigen/test/CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.o: Eigen/test/CMakeFiles/vectorwiseop_4.dir/flags.make
Eigen/test/CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.o: /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/vectorwiseop.cpp
Eigen/test/CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.o: Eigen/test/CMakeFiles/vectorwiseop_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Eigen/test/CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.o"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Eigen/test/CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.o -MF CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.o.d -o CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.o -c /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/vectorwiseop.cpp

Eigen/test/CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.i"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/vectorwiseop.cpp > CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.i

Eigen/test/CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.s"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/vectorwiseop.cpp -o CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.s

# Object files for target vectorwiseop_4
vectorwiseop_4_OBJECTS = \
"CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.o"

# External object files for target vectorwiseop_4
vectorwiseop_4_EXTERNAL_OBJECTS =

Eigen/test/vectorwiseop_4: Eigen/test/CMakeFiles/vectorwiseop_4.dir/vectorwiseop.cpp.o
Eigen/test/vectorwiseop_4: Eigen/test/CMakeFiles/vectorwiseop_4.dir/build.make
Eigen/test/vectorwiseop_4: Eigen/test/CMakeFiles/vectorwiseop_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vectorwiseop_4"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vectorwiseop_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Eigen/test/CMakeFiles/vectorwiseop_4.dir/build: Eigen/test/vectorwiseop_4
.PHONY : Eigen/test/CMakeFiles/vectorwiseop_4.dir/build

Eigen/test/CMakeFiles/vectorwiseop_4.dir/clean:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && $(CMAKE_COMMAND) -P CMakeFiles/vectorwiseop_4.dir/cmake_clean.cmake
.PHONY : Eigen/test/CMakeFiles/vectorwiseop_4.dir/clean

Eigen/test/CMakeFiles/vectorwiseop_4.dir/depend:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crystalized/cpp_project/myRender/myGraphicEngine /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test/CMakeFiles/vectorwiseop_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Eigen/test/CMakeFiles/vectorwiseop_4.dir/depend

