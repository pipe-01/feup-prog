# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/149/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/149/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1st_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1st_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1st_project.dir/flags.make

CMakeFiles/1st_project.dir/main.cpp.o: CMakeFiles/1st_project.dir/flags.make
CMakeFiles/1st_project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1st_project.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1st_project.dir/main.cpp.o -c /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/main.cpp

CMakeFiles/1st_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1st_project.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/main.cpp > CMakeFiles/1st_project.dir/main.cpp.i

CMakeFiles/1st_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1st_project.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/main.cpp -o CMakeFiles/1st_project.dir/main.cpp.s

# Object files for target 1st_project
1st_project_OBJECTS = \
"CMakeFiles/1st_project.dir/main.cpp.o"

# External object files for target 1st_project
1st_project_EXTERNAL_OBJECTS =

1st_project: CMakeFiles/1st_project.dir/main.cpp.o
1st_project: CMakeFiles/1st_project.dir/build.make
1st_project: CMakeFiles/1st_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1st_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1st_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1st_project.dir/build: 1st_project

.PHONY : CMakeFiles/1st_project.dir/build

CMakeFiles/1st_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1st_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1st_project.dir/clean

CMakeFiles/1st_project.dir/depend:
	cd /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/cmake-build-debug /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/cmake-build-debug /home/juan/Documents/FEUP/2-Ano/2-Sem/PROG/project/feup-prog/1st_proj/cmake-build-debug/CMakeFiles/1st_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1st_project.dir/depend

