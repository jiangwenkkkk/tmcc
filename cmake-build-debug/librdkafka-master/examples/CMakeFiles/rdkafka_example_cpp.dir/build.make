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
include librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/depend.make

# Include the progress variables for this target.
include librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/flags.make

librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.o: librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/flags.make
librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.o: ../librdkafka-master/examples/rdkafka_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.o"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/examples && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.o -c /Users/james/jameswork/james_clion/testpoco/librdkafka-master/examples/rdkafka_example.cpp

librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.i"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/jameswork/james_clion/testpoco/librdkafka-master/examples/rdkafka_example.cpp > CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.i

librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.s"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/jameswork/james_clion/testpoco/librdkafka-master/examples/rdkafka_example.cpp -o CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.s

# Object files for target rdkafka_example_cpp
rdkafka_example_cpp_OBJECTS = \
"CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.o"

# External object files for target rdkafka_example_cpp
rdkafka_example_cpp_EXTERNAL_OBJECTS =

librdkafka-master/examples/rdkafka_example_cpp: librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/rdkafka_example.cpp.o
librdkafka-master/examples/rdkafka_example_cpp: librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/build.make
librdkafka-master/examples/rdkafka_example_cpp: librdkafka-master/src-cpp/librdkafka++.a
librdkafka-master/examples/rdkafka_example_cpp: librdkafka-master/src/librdkafka.dylib
librdkafka-master/examples/rdkafka_example_cpp: /usr/lib/libz.dylib
librdkafka-master/examples/rdkafka_example_cpp: librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rdkafka_example_cpp"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rdkafka_example_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/build: librdkafka-master/examples/rdkafka_example_cpp

.PHONY : librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/build

librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/clean:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/examples && $(CMAKE_COMMAND) -P CMakeFiles/rdkafka_example_cpp.dir/cmake_clean.cmake
.PHONY : librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/clean

librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/depend:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/jameswork/james_clion/testpoco /Users/james/jameswork/james_clion/testpoco/librdkafka-master/examples /Users/james/jameswork/james_clion/testpoco/cmake-build-debug /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/examples /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : librdkafka-master/examples/CMakeFiles/rdkafka_example_cpp.dir/depend
