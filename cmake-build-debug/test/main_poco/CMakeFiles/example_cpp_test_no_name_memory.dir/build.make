# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/james/jameswork/james_clion/testpoco

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/james/jameswork/james_clion/testpoco/cmake-build-debug

# Include any dependencies generated for this target.
include test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/depend.make

# Include the progress variables for this target.
include test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/progress.make

# Include the compile flags for this target's objects.
include test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/flags.make

test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.o: test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/flags.make
test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.o: ../test/main_poco/test_no_name_memory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.o"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/main_poco && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.o -c /Users/james/jameswork/james_clion/testpoco/test/main_poco/test_no_name_memory.cpp

test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.i"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/main_poco && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/jameswork/james_clion/testpoco/test/main_poco/test_no_name_memory.cpp > CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.i

test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.s"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/main_poco && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/jameswork/james_clion/testpoco/test/main_poco/test_no_name_memory.cpp -o CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.s

# Object files for target example_cpp_test_no_name_memory
example_cpp_test_no_name_memory_OBJECTS = \
"CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.o"

# External object files for target example_cpp_test_no_name_memory
example_cpp_test_no_name_memory_EXTERNAL_OBJECTS =

test/main_poco/example_cpp_test_no_name_memory: test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/test_no_name_memory.cpp.o
test/main_poco/example_cpp_test_no_name_memory: test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/build.make
test/main_poco/example_cpp_test_no_name_memory: test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_cpp_test_no_name_memory"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/main_poco && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_cpp_test_no_name_memory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/build: test/main_poco/example_cpp_test_no_name_memory

.PHONY : test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/build

test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/clean:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/main_poco && $(CMAKE_COMMAND) -P CMakeFiles/example_cpp_test_no_name_memory.dir/cmake_clean.cmake
.PHONY : test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/clean

test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/depend:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/jameswork/james_clion/testpoco /Users/james/jameswork/james_clion/testpoco/test/main_poco /Users/james/jameswork/james_clion/testpoco/cmake-build-debug /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/main_poco /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/main_poco/CMakeFiles/example_cpp_test_no_name_memory.dir/depend

