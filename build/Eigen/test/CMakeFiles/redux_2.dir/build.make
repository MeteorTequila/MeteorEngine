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
include Eigen/test/CMakeFiles/redux_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Eigen/test/CMakeFiles/redux_2.dir/compiler_depend.make

# Include the progress variables for this target.
include Eigen/test/CMakeFiles/redux_2.dir/progress.make

# Include the compile flags for this target's objects.
include Eigen/test/CMakeFiles/redux_2.dir/flags.make

Eigen/test/CMakeFiles/redux_2.dir/redux.cpp.o: Eigen/test/CMakeFiles/redux_2.dir/flags.make
Eigen/test/CMakeFiles/redux_2.dir/redux.cpp.o: /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/redux.cpp
Eigen/test/CMakeFiles/redux_2.dir/redux.cpp.o: Eigen/test/CMakeFiles/redux_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Eigen/test/CMakeFiles/redux_2.dir/redux.cpp.o"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Eigen/test/CMakeFiles/redux_2.dir/redux.cpp.o -MF CMakeFiles/redux_2.dir/redux.cpp.o.d -o CMakeFiles/redux_2.dir/redux.cpp.o -c /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/redux.cpp

Eigen/test/CMakeFiles/redux_2.dir/redux.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redux_2.dir/redux.cpp.i"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/redux.cpp > CMakeFiles/redux_2.dir/redux.cpp.i

Eigen/test/CMakeFiles/redux_2.dir/redux.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redux_2.dir/redux.cpp.s"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test/redux.cpp -o CMakeFiles/redux_2.dir/redux.cpp.s

# Object files for target redux_2
redux_2_OBJECTS = \
"CMakeFiles/redux_2.dir/redux.cpp.o"

# External object files for target redux_2
redux_2_EXTERNAL_OBJECTS =

Eigen/test/redux_2: Eigen/test/CMakeFiles/redux_2.dir/redux.cpp.o
Eigen/test/redux_2: Eigen/test/CMakeFiles/redux_2.dir/build.make
Eigen/test/redux_2: Eigen/test/CMakeFiles/redux_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable redux_2"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/redux_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Eigen/test/CMakeFiles/redux_2.dir/build: Eigen/test/redux_2
.PHONY : Eigen/test/CMakeFiles/redux_2.dir/build

Eigen/test/CMakeFiles/redux_2.dir/clean:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test && $(CMAKE_COMMAND) -P CMakeFiles/redux_2.dir/cmake_clean.cmake
.PHONY : Eigen/test/CMakeFiles/redux_2.dir/clean

Eigen/test/CMakeFiles/redux_2.dir/depend:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crystalized/cpp_project/myRender/myGraphicEngine /Users/crystalized/cpp_project/myRender/myGraphicEngine/third_part/eigen-3.4.0/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen/test/CMakeFiles/redux_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Eigen/test/CMakeFiles/redux_2.dir/depend

