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

# Utility rule file for sparse_permutations.

# Include any custom commands dependencies for this target.
include dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/compiler_depend.make

# Include the progress variables for this target.
include dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/progress.make

sparse_permutations: dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/build.make
.PHONY : sparse_permutations

# Rule to build all files generated by this target.
dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/build: sparse_permutations
.PHONY : dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/build

dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/clean:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test && $(CMAKE_COMMAND) -P CMakeFiles/sparse_permutations.dir/cmake_clean.cmake
.PHONY : dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/clean

dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/depend:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crystalized/cpp_project/myRender/myGraphicEngine /Users/crystalized/cpp_project/myRender/myGraphicEngine/dependencies/eigen-3.4.0/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dependencies/eigen-3.4.0/test/CMakeFiles/sparse_permutations.dir/depend

