# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jettajac/Documents/CPP/calculator/Mycalc/src/QT_calc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jettajac/Documents/CPP/calculator/Mycalc/build/s21_calculator

# Utility rule file for s21_Calc_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/s21_Calc_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/s21_Calc_autogen.dir/progress.make

CMakeFiles/s21_Calc_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/jettajac/Documents/CPP/calculator/Mycalc/build/s21_calculator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target s21_Calc"
	/usr/local/bin/cmake -E cmake_autogen /Users/jettajac/Documents/CPP/calculator/Mycalc/build/s21_calculator/CMakeFiles/s21_Calc_autogen.dir/AutogenInfo.json ""

s21_Calc_autogen: CMakeFiles/s21_Calc_autogen
s21_Calc_autogen: CMakeFiles/s21_Calc_autogen.dir/build.make
.PHONY : s21_Calc_autogen

# Rule to build all files generated by this target.
CMakeFiles/s21_Calc_autogen.dir/build: s21_Calc_autogen
.PHONY : CMakeFiles/s21_Calc_autogen.dir/build

CMakeFiles/s21_Calc_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/s21_Calc_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/s21_Calc_autogen.dir/clean

CMakeFiles/s21_Calc_autogen.dir/depend:
	cd /Users/jettajac/Documents/CPP/calculator/Mycalc/build/s21_calculator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jettajac/Documents/CPP/calculator/Mycalc/src/QT_calc /Users/jettajac/Documents/CPP/calculator/Mycalc/src/QT_calc /Users/jettajac/Documents/CPP/calculator/Mycalc/build/s21_calculator /Users/jettajac/Documents/CPP/calculator/Mycalc/build/s21_calculator /Users/jettajac/Documents/CPP/calculator/Mycalc/build/s21_calculator/CMakeFiles/s21_Calc_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/s21_Calc_autogen.dir/depend

