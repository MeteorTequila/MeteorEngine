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
include dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compiler_depend.make

# Include the progress variables for this target.
include dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/progress.make

# Include the compile flags for this target's objects.
include dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/flags.make

dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o: dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/flags.make
dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o: dependencies/eigen-3.4.0/doc/snippets/compile_PartialRedux_prod.cpp
dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o: /Users/crystalized/cpp_project/myRender/myGraphicEngine/dependencies/eigen-3.4.0/doc/snippets/PartialRedux_prod.cpp
dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o: dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o -MF CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o.d -o CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o -c /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets/compile_PartialRedux_prod.cpp

dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.i"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets/compile_PartialRedux_prod.cpp > CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.i

dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.s"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets/compile_PartialRedux_prod.cpp -o CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.s

# Object files for target compile_PartialRedux_prod
compile_PartialRedux_prod_OBJECTS = \
"CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o"

# External object files for target compile_PartialRedux_prod
compile_PartialRedux_prod_EXTERNAL_OBJECTS =

dependencies/eigen-3.4.0/doc/snippets/compile_PartialRedux_prod: dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/compile_PartialRedux_prod.cpp.o
dependencies/eigen-3.4.0/doc/snippets/compile_PartialRedux_prod: dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/build.make
dependencies/eigen-3.4.0/doc/snippets/compile_PartialRedux_prod: dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable compile_PartialRedux_prod"
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile_PartialRedux_prod.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets && ./compile_PartialRedux_prod >/Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets/PartialRedux_prod.out

# Rule to build all files generated by this target.
dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/build: dependencies/eigen-3.4.0/doc/snippets/compile_PartialRedux_prod
.PHONY : dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/build

dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/clean:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets && $(CMAKE_COMMAND) -P CMakeFiles/compile_PartialRedux_prod.dir/cmake_clean.cmake
.PHONY : dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/clean

dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/depend:
	cd /Users/crystalized/cpp_project/myRender/myGraphicEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crystalized/cpp_project/myRender/myGraphicEngine /Users/crystalized/cpp_project/myRender/myGraphicEngine/dependencies/eigen-3.4.0/doc/snippets /Users/crystalized/cpp_project/myRender/myGraphicEngine/build /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets /Users/crystalized/cpp_project/myRender/myGraphicEngine/build/dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dependencies/eigen-3.4.0/doc/snippets/CMakeFiles/compile_PartialRedux_prod.dir/depend

