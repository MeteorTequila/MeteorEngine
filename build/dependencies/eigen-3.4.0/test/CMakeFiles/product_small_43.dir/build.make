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
include dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/compiler_depend.make

# Include the progress variables for this target.
include dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/progress.make

# Include the compile flags for this target's objects.
include dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/flags.make

dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/product_small.cpp.o: dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/flags.make
dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/product_small.cpp.o: /Users/crystalized/cpp_project/myRender/myGraphicEngine/dependencies/eigen-3.4.0/test/product_small.cpp
dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/product_small.cpp.o: dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/product_small.cpp.o"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/product_small.cpp.o -MF CMakeFiles/product_small_43.dir/product_small.cpp.o.d -o CMakeFiles/product_small_43.dir/product_small.cpp.o -c /Users/crystalized/cpp_project/myRender/myGraphicEngine/dependencies/eigen-3.4.0/test/product_small.cpp

dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/product_small.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/product_small_43.dir/product_small.cpp.i"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/crystalized/cpp_project/myRender/myGraphicEngine/dependencies/eigen-3.4.0/test/product_small.cpp > CMakeFiles/product_small_43.dir/product_small.cpp.i

dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/product_small.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/product_small_43.dir/product_small.cpp.s"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/crystalized/cpp_project/myRender/myGraphicEngine/dependencies/eigen-3.4.0/test/product_small.cpp -o CMakeFiles/product_small_43.dir/product_small.cpp.s

# Object files for target product_small_43
product_small_43_OBJECTS = \
"CMakeFiles/product_small_43.dir/product_small.cpp.o"

# External object files for target product_small_43
product_small_43_EXTERNAL_OBJECTS =

dependencies/eigen-3.4.0/test/product_small_43: dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/product_small.cpp.o
dependencies/eigen-3.4.0/test/product_small_43: dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/build.make
dependencies/eigen-3.4.0/test/product_small_43: dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable product_small_43"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/product_small_43.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/build: dependencies/eigen-3.4.0/test/product_small_43
.PHONY : dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/build

dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/clean:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test && $(CMAKE_COMMAND) -P CMakeFiles/product_small_43.dir/cmake_clean.cmake
.PHONY : dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/clean

dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/depend:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crystalized/cpp_project/myRender/myGraphicEngine /Users/crystalized/cpp_project/myRender/myGraphicEngine/dependencies/eigen-3.4.0/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dependencies/eigen-3.4.0/test/CMakeFiles/product_small_43.dir/depend

