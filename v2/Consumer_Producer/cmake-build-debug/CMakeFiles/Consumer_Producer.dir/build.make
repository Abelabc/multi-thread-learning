# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\github_project\multi-thread-learning\v1\Consumer_Producer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\github_project\multi-thread-learning\v1\Consumer_Producer\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Consumer_Producer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Consumer_Producer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Consumer_Producer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Consumer_Producer.dir/flags.make

CMakeFiles/Consumer_Producer.dir/main.cpp.obj: CMakeFiles/Consumer_Producer.dir/flags.make
CMakeFiles/Consumer_Producer.dir/main.cpp.obj: F:/github_project/multi-thread-learning/v1/Consumer_Producer/main.cpp
CMakeFiles/Consumer_Producer.dir/main.cpp.obj: CMakeFiles/Consumer_Producer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\github_project\multi-thread-learning\v1\Consumer_Producer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Consumer_Producer.dir/main.cpp.obj"
	D:\mingw64\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Consumer_Producer.dir/main.cpp.obj -MF CMakeFiles\Consumer_Producer.dir\main.cpp.obj.d -o CMakeFiles\Consumer_Producer.dir\main.cpp.obj -c F:\github_project\multi-thread-learning\v1\Consumer_Producer\main.cpp

CMakeFiles/Consumer_Producer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Consumer_Producer.dir/main.cpp.i"
	D:\mingw64\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\github_project\multi-thread-learning\v1\Consumer_Producer\main.cpp > CMakeFiles\Consumer_Producer.dir\main.cpp.i

CMakeFiles/Consumer_Producer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Consumer_Producer.dir/main.cpp.s"
	D:\mingw64\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\github_project\multi-thread-learning\v1\Consumer_Producer\main.cpp -o CMakeFiles\Consumer_Producer.dir\main.cpp.s

# Object files for target Consumer_Producer
Consumer_Producer_OBJECTS = \
"CMakeFiles/Consumer_Producer.dir/main.cpp.obj"

# External object files for target Consumer_Producer
Consumer_Producer_EXTERNAL_OBJECTS =

Consumer_Producer.exe: CMakeFiles/Consumer_Producer.dir/main.cpp.obj
Consumer_Producer.exe: CMakeFiles/Consumer_Producer.dir/build.make
Consumer_Producer.exe: CMakeFiles/Consumer_Producer.dir/linkLibs.rsp
Consumer_Producer.exe: CMakeFiles/Consumer_Producer.dir/objects1.rsp
Consumer_Producer.exe: CMakeFiles/Consumer_Producer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\github_project\multi-thread-learning\v1\Consumer_Producer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Consumer_Producer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Consumer_Producer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Consumer_Producer.dir/build: Consumer_Producer.exe
.PHONY : CMakeFiles/Consumer_Producer.dir/build

CMakeFiles/Consumer_Producer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Consumer_Producer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Consumer_Producer.dir/clean

CMakeFiles/Consumer_Producer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\github_project\multi-thread-learning\v1\Consumer_Producer F:\github_project\multi-thread-learning\v1\Consumer_Producer F:\github_project\multi-thread-learning\v1\Consumer_Producer\cmake-build-debug F:\github_project\multi-thread-learning\v1\Consumer_Producer\cmake-build-debug F:\github_project\multi-thread-learning\v1\Consumer_Producer\cmake-build-debug\CMakeFiles\Consumer_Producer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Consumer_Producer.dir/depend
