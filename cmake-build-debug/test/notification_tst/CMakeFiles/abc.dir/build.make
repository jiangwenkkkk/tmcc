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
include test/notification_tst/CMakeFiles/abc.dir/depend.make

# Include the progress variables for this target.
include test/notification_tst/CMakeFiles/abc.dir/progress.make

# Include the compile flags for this target's objects.
include test/notification_tst/CMakeFiles/abc.dir/flags.make

test/notification_tst/CMakeFiles/abc.dir/notification_test.cpp.o: test/notification_tst/CMakeFiles/abc.dir/flags.make
test/notification_tst/CMakeFiles/abc.dir/notification_test.cpp.o: ../test/notification_tst/notification_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/notification_tst/CMakeFiles/abc.dir/notification_test.cpp.o"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/notification_tst && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abc.dir/notification_test.cpp.o -c /Users/james/jameswork/james_clion/testpoco/test/notification_tst/notification_test.cpp

test/notification_tst/CMakeFiles/abc.dir/notification_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abc.dir/notification_test.cpp.i"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/notification_tst && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/jameswork/james_clion/testpoco/test/notification_tst/notification_test.cpp > CMakeFiles/abc.dir/notification_test.cpp.i

test/notification_tst/CMakeFiles/abc.dir/notification_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abc.dir/notification_test.cpp.s"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/notification_tst && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/jameswork/james_clion/testpoco/test/notification_tst/notification_test.cpp -o CMakeFiles/abc.dir/notification_test.cpp.s

# Object files for target abc
abc_OBJECTS = \
"CMakeFiles/abc.dir/notification_test.cpp.o"

# External object files for target abc
abc_EXTERNAL_OBJECTS =

test/notification_tst/abc: test/notification_tst/CMakeFiles/abc.dir/notification_test.cpp.o
test/notification_tst/abc: test/notification_tst/CMakeFiles/abc.dir/build.make
test/notification_tst/abc: test/notification_tst/CMakeFiles/abc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable abc"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/notification_tst && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/abc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/notification_tst/CMakeFiles/abc.dir/build: test/notification_tst/abc

.PHONY : test/notification_tst/CMakeFiles/abc.dir/build

test/notification_tst/CMakeFiles/abc.dir/clean:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/notification_tst && $(CMAKE_COMMAND) -P CMakeFiles/abc.dir/cmake_clean.cmake
.PHONY : test/notification_tst/CMakeFiles/abc.dir/clean

test/notification_tst/CMakeFiles/abc.dir/depend:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/jameswork/james_clion/testpoco /Users/james/jameswork/james_clion/testpoco/test/notification_tst /Users/james/jameswork/james_clion/testpoco/cmake-build-debug /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/notification_tst /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/notification_tst/CMakeFiles/abc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/notification_tst/CMakeFiles/abc.dir/depend

