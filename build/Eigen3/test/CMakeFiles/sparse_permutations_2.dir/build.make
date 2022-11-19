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
include Eigen3/test/CMakeFiles/sparse_permutations_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Eigen3/test/CMakeFiles/sparse_permutations_2.dir/compiler_depend.make

# Include the progress variables for this target.
include Eigen3/test/CMakeFiles/sparse_permutations_2.dir/progress.make

# Include the compile flags for this target's objects.
include Eigen3/test/CMakeFiles/sparse_permutations_2.dir/flags.make

Eigen3/test/CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.o: Eigen3/test/CMakeFiles/sparse_permutations_2.dir/flags.make
Eigen3/test/CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.o: /Users/crystalized/cpp_project/myRender/myGraphicEngine/ThirdPartyLibraries/eigen-3.4.0/test/sparse_permutations.cpp
Eigen3/test/CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.o: Eigen3/test/CMakeFiles/sparse_permutations_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Eigen3/test/CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.o"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen3/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Eigen3/test/CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.o -MF CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.o.d -o CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.o -c /Users/crystalized/cpp_project/myRender/myGraphicEngine/ThirdPartyLibraries/eigen-3.4.0/test/sparse_permutations.cpp

Eigen3/test/CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.i"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen3/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/crystalized/cpp_project/myRender/myGraphicEngine/ThirdPartyLibraries/eigen-3.4.0/test/sparse_permutations.cpp > CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.i

Eigen3/test/CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.s"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen3/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/crystalized/cpp_project/myRender/myGraphicEngine/ThirdPartyLibraries/eigen-3.4.0/test/sparse_permutations.cpp -o CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.s

# Object files for target sparse_permutations_2
sparse_permutations_2_OBJECTS = \
"CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.o"

# External object files for target sparse_permutations_2
sparse_permutations_2_EXTERNAL_OBJECTS =

Eigen3/test/sparse_permutations_2: Eigen3/test/CMakeFiles/sparse_permutations_2.dir/sparse_permutations.cpp.o
Eigen3/test/sparse_permutations_2: Eigen3/test/CMakeFiles/sparse_permutations_2.dir/build.make
Eigen3/test/sparse_permutations_2: Eigen3/test/CMakeFiles/sparse_permutations_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sparse_permutations_2"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen3/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sparse_permutations_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Eigen3/test/CMakeFiles/sparse_permutations_2.dir/build: Eigen3/test/sparse_permutations_2
.PHONY : Eigen3/test/CMakeFiles/sparse_permutations_2.dir/build

Eigen3/test/CMakeFiles/sparse_permutations_2.dir/clean:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen3/test && $(CMAKE_COMMAND) -P CMakeFiles/sparse_permutations_2.dir/cmake_clean.cmake
.PHONY : Eigen3/test/CMakeFiles/sparse_permutations_2.dir/clean

Eigen3/test/CMakeFiles/sparse_permutations_2.dir/depend:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crystalized/cpp_project/myRender/myGraphicEngine /Users/crystalized/cpp_project/myRender/myGraphicEngine/ThirdPartyLibraries/eigen-3.4.0/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen3/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/Eigen3/test/CMakeFiles/sparse_permutations_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Eigen3/test/CMakeFiles/sparse_permutations_2.dir/depend

