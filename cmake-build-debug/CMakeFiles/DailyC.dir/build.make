# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\OneFl\Documents\GitHub\DailyC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\OneFl\Documents\GitHub\DailyC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DailyC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DailyC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DailyC.dir/flags.make

CMakeFiles/DailyC.dir/system/VariableArgs.c.obj: CMakeFiles/DailyC.dir/flags.make
CMakeFiles/DailyC.dir/system/VariableArgs.c.obj: ../system/VariableArgs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\OneFl\Documents\GitHub\DailyC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DailyC.dir/system/VariableArgs.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DailyC.dir\system\VariableArgs.c.obj   -c C:\Users\OneFl\Documents\GitHub\DailyC\system\VariableArgs.c

CMakeFiles/DailyC.dir/system/VariableArgs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DailyC.dir/system/VariableArgs.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\OneFl\Documents\GitHub\DailyC\system\VariableArgs.c > CMakeFiles\DailyC.dir\system\VariableArgs.c.i

CMakeFiles/DailyC.dir/system/VariableArgs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DailyC.dir/system/VariableArgs.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\OneFl\Documents\GitHub\DailyC\system\VariableArgs.c -o CMakeFiles\DailyC.dir\system\VariableArgs.c.s

# Object files for target DailyC
DailyC_OBJECTS = \
"CMakeFiles/DailyC.dir/system/VariableArgs.c.obj"

# External object files for target DailyC
DailyC_EXTERNAL_OBJECTS =

DailyC.exe: CMakeFiles/DailyC.dir/system/VariableArgs.c.obj
DailyC.exe: CMakeFiles/DailyC.dir/build.make
DailyC.exe: CMakeFiles/DailyC.dir/linklibs.rsp
DailyC.exe: CMakeFiles/DailyC.dir/objects1.rsp
DailyC.exe: CMakeFiles/DailyC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\OneFl\Documents\GitHub\DailyC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DailyC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DailyC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DailyC.dir/build: DailyC.exe

.PHONY : CMakeFiles/DailyC.dir/build

CMakeFiles/DailyC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DailyC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DailyC.dir/clean

CMakeFiles/DailyC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\OneFl\Documents\GitHub\DailyC C:\Users\OneFl\Documents\GitHub\DailyC C:\Users\OneFl\Documents\GitHub\DailyC\cmake-build-debug C:\Users\OneFl\Documents\GitHub\DailyC\cmake-build-debug C:\Users\OneFl\Documents\GitHub\DailyC\cmake-build-debug\CMakeFiles\DailyC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DailyC.dir/depend

