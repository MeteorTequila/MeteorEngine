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
include Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/compiler_depend.make

# Include the progress variables for this target.
include Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/progress.make

# Include the compile flags for this target's objects.
include Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/flags.make

Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.o: Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/flags.make
Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.o: /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/unsupported/doc/examples/MatrixPower.cpp
Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.o: Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.o"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/unsupported/doc/examples && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.o -MF CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.o.d -o CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.o -c /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/unsupported/doc/examples/MatrixPower.cpp

Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.i"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/unsupported/doc/examples && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/unsupported/doc/examples/MatrixPower.cpp > CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.i

Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.s"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/unsupported/doc/examples && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/unsupported/doc/examples/MatrixPower.cpp -o CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.s

# Object files for target example_MatrixPower
example_MatrixPower_OBJECTS = \
"CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.o"

# External object files for target example_MatrixPower
example_MatrixPower_EXTERNAL_OBJECTS =

Eigen/unsupported/doc/examples/example_MatrixPower: Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/MatrixPower.cpp.o
Eigen/unsupported/doc/examples/example_MatrixPower: Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/build.make
Eigen/unsupported/doc/examples/example_MatrixPower: Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_MatrixPower"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/unsupported/doc/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_MatrixPower.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/unsupported/doc/examples && ./example_MatrixPower >/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/unsupported/doc/examples/MatrixPower.out

# Rule to build all files generated by this target.
Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/build: Eigen/unsupported/doc/examples/example_MatrixPower
.PHONY : Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/build

Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/clean:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/unsupported/doc/examples && $(CMAKE_COMMAND) -P CMakeFiles/example_MatrixPower.dir/cmake_clean.cmake
.PHONY : Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/clean

Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/depend:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crystalized/cpp_project/myRender/myGraphicEngine /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/unsupported/doc/examples /Users/crystalized/cpp_project/myRender/myGraphicEngine/build /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/unsupported/doc/examples /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Eigen/unsupported/doc/examples/CMakeFiles/example_MatrixPower.dir/depend

