# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/inki/Documents/intro-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/inki/Documents/intro-c/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/intro_c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/intro_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/intro_c.dir/flags.make

CMakeFiles/intro_c.dir/main.c.o: CMakeFiles/intro_c.dir/flags.make
CMakeFiles/intro_c.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/inki/Documents/intro-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/intro_c.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/intro_c.dir/main.c.o   -c /Users/inki/Documents/intro-c/main.c

CMakeFiles/intro_c.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/intro_c.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/inki/Documents/intro-c/main.c > CMakeFiles/intro_c.dir/main.c.i

CMakeFiles/intro_c.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/intro_c.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/inki/Documents/intro-c/main.c -o CMakeFiles/intro_c.dir/main.c.s

CMakeFiles/intro_c.dir/main.c.o.requires:

.PHONY : CMakeFiles/intro_c.dir/main.c.o.requires

CMakeFiles/intro_c.dir/main.c.o.provides: CMakeFiles/intro_c.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/intro_c.dir/build.make CMakeFiles/intro_c.dir/main.c.o.provides.build
.PHONY : CMakeFiles/intro_c.dir/main.c.o.provides

CMakeFiles/intro_c.dir/main.c.o.provides.build: CMakeFiles/intro_c.dir/main.c.o


# Object files for target intro_c
intro_c_OBJECTS = \
"CMakeFiles/intro_c.dir/main.c.o"

# External object files for target intro_c
intro_c_EXTERNAL_OBJECTS =

intro_c: CMakeFiles/intro_c.dir/main.c.o
intro_c: CMakeFiles/intro_c.dir/build.make
intro_c: CMakeFiles/intro_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/inki/Documents/intro-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable intro_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/intro_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/intro_c.dir/build: intro_c

.PHONY : CMakeFiles/intro_c.dir/build

CMakeFiles/intro_c.dir/requires: CMakeFiles/intro_c.dir/main.c.o.requires

.PHONY : CMakeFiles/intro_c.dir/requires

CMakeFiles/intro_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/intro_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/intro_c.dir/clean

CMakeFiles/intro_c.dir/depend:
	cd /Users/inki/Documents/intro-c/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/inki/Documents/intro-c /Users/inki/Documents/intro-c /Users/inki/Documents/intro-c/cmake-build-debug /Users/inki/Documents/intro-c/cmake-build-debug /Users/inki/Documents/intro-c/cmake-build-debug/CMakeFiles/intro_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/intro_c.dir/depend

