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
include test_redis/CMakeFiles/example_cpp_local_redis.dir/depend.make

# Include the progress variables for this target.
include test_redis/CMakeFiles/example_cpp_local_redis.dir/progress.make

# Include the compile flags for this target's objects.
include test_redis/CMakeFiles/example_cpp_local_redis.dir/flags.make

test_redis/CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.o: test_redis/CMakeFiles/example_cpp_local_redis.dir/flags.make
test_redis/CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.o: ../test_redis/local_redis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test_redis/CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.o"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test_redis && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.o -c /Users/james/jameswork/james_clion/testpoco/test_redis/local_redis.cpp

test_redis/CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.i"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test_redis && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/jameswork/james_clion/testpoco/test_redis/local_redis.cpp > CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.i

test_redis/CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.s"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test_redis && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/jameswork/james_clion/testpoco/test_redis/local_redis.cpp -o CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.s

# Object files for target example_cpp_local_redis
example_cpp_local_redis_OBJECTS = \
"CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.o"

# External object files for target example_cpp_local_redis
example_cpp_local_redis_EXTERNAL_OBJECTS =

test_redis/example_cpp_local_redis: test_redis/CMakeFiles/example_cpp_local_redis.dir/local_redis.cpp.o
test_redis/example_cpp_local_redis: test_redis/CMakeFiles/example_cpp_local_redis.dir/build.make
test_redis/example_cpp_local_redis: test_redis/CMakeFiles/example_cpp_local_redis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_cpp_local_redis"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test_redis && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_cpp_local_redis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test_redis/CMakeFiles/example_cpp_local_redis.dir/build: test_redis/example_cpp_local_redis

.PHONY : test_redis/CMakeFiles/example_cpp_local_redis.dir/build

test_redis/CMakeFiles/example_cpp_local_redis.dir/clean:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test_redis && $(CMAKE_COMMAND) -P CMakeFiles/example_cpp_local_redis.dir/cmake_clean.cmake
.PHONY : test_redis/CMakeFiles/example_cpp_local_redis.dir/clean

test_redis/CMakeFiles/example_cpp_local_redis.dir/depend:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/jameswork/james_clion/testpoco /Users/james/jameswork/james_clion/testpoco/test_redis /Users/james/jameswork/james_clion/testpoco/cmake-build-debug /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test_redis /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test_redis/CMakeFiles/example_cpp_local_redis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test_redis/CMakeFiles/example_cpp_local_redis.dir/depend

