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
include test/audit_test/CMakeFiles/abcdef.dir/depend.make

# Include the progress variables for this target.
include test/audit_test/CMakeFiles/abcdef.dir/progress.make

# Include the compile flags for this target's objects.
include test/audit_test/CMakeFiles/abcdef.dir/flags.make

test/audit_test/CMakeFiles/abcdef.dir/auditMain.cpp.o: test/audit_test/CMakeFiles/abcdef.dir/flags.make
test/audit_test/CMakeFiles/abcdef.dir/auditMain.cpp.o: ../test/audit_test/auditMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/audit_test/CMakeFiles/abcdef.dir/auditMain.cpp.o"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abcdef.dir/auditMain.cpp.o -c /Users/james/jameswork/james_clion/testpoco/test/audit_test/auditMain.cpp

test/audit_test/CMakeFiles/abcdef.dir/auditMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abcdef.dir/auditMain.cpp.i"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/jameswork/james_clion/testpoco/test/audit_test/auditMain.cpp > CMakeFiles/abcdef.dir/auditMain.cpp.i

test/audit_test/CMakeFiles/abcdef.dir/auditMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abcdef.dir/auditMain.cpp.s"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/jameswork/james_clion/testpoco/test/audit_test/auditMain.cpp -o CMakeFiles/abcdef.dir/auditMain.cpp.s

test/audit_test/CMakeFiles/abcdef.dir/test.cpp.o: test/audit_test/CMakeFiles/abcdef.dir/flags.make
test/audit_test/CMakeFiles/abcdef.dir/test.cpp.o: ../test/audit_test/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/audit_test/CMakeFiles/abcdef.dir/test.cpp.o"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abcdef.dir/test.cpp.o -c /Users/james/jameswork/james_clion/testpoco/test/audit_test/test.cpp

test/audit_test/CMakeFiles/abcdef.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abcdef.dir/test.cpp.i"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/jameswork/james_clion/testpoco/test/audit_test/test.cpp > CMakeFiles/abcdef.dir/test.cpp.i

test/audit_test/CMakeFiles/abcdef.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abcdef.dir/test.cpp.s"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/jameswork/james_clion/testpoco/test/audit_test/test.cpp -o CMakeFiles/abcdef.dir/test.cpp.s

# Object files for target abcdef
abcdef_OBJECTS = \
"CMakeFiles/abcdef.dir/auditMain.cpp.o" \
"CMakeFiles/abcdef.dir/test.cpp.o"

# External object files for target abcdef
abcdef_EXTERNAL_OBJECTS =

test/audit_test/abcdef: test/audit_test/CMakeFiles/abcdef.dir/auditMain.cpp.o
test/audit_test/abcdef: test/audit_test/CMakeFiles/abcdef.dir/test.cpp.o
test/audit_test/abcdef: test/audit_test/CMakeFiles/abcdef.dir/build.make
test/audit_test/abcdef: test/audit_test/CMakeFiles/abcdef.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable abcdef"
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/abcdef.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/audit_test/CMakeFiles/abcdef.dir/build: test/audit_test/abcdef

.PHONY : test/audit_test/CMakeFiles/abcdef.dir/build

test/audit_test/CMakeFiles/abcdef.dir/clean:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test && $(CMAKE_COMMAND) -P CMakeFiles/abcdef.dir/cmake_clean.cmake
.PHONY : test/audit_test/CMakeFiles/abcdef.dir/clean

test/audit_test/CMakeFiles/abcdef.dir/depend:
	cd /Users/james/jameswork/james_clion/testpoco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/jameswork/james_clion/testpoco /Users/james/jameswork/james_clion/testpoco/test/audit_test /Users/james/jameswork/james_clion/testpoco/cmake-build-debug /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test/CMakeFiles/abcdef.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/audit_test/CMakeFiles/abcdef.dir/depend
