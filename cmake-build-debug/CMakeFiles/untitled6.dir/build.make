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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/untitled6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled6.dir/flags.make

CMakeFiles/untitled6.dir/main.c.obj: CMakeFiles/untitled6.dir/flags.make
CMakeFiles/untitled6.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled6.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled6.dir\main.c.obj   -c "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\main.c"

CMakeFiles/untitled6.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled6.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\main.c" > CMakeFiles\untitled6.dir\main.c.i

CMakeFiles/untitled6.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled6.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\main.c" -o CMakeFiles\untitled6.dir\main.c.s

CMakeFiles/untitled6.dir/libs/string/string_.c.obj: CMakeFiles/untitled6.dir/flags.make
CMakeFiles/untitled6.dir/libs/string/string_.c.obj: ../libs/string/string_.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled6.dir/libs/string/string_.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled6.dir\libs\string\string_.c.obj   -c "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\libs\string\string_.c"

CMakeFiles/untitled6.dir/libs/string/string_.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled6.dir/libs/string/string_.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\libs\string\string_.c" > CMakeFiles\untitled6.dir\libs\string\string_.c.i

CMakeFiles/untitled6.dir/libs/string/string_.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled6.dir/libs/string/string_.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\libs\string\string_.c" -o CMakeFiles\untitled6.dir\libs\string\string_.c.s

# Object files for target untitled6
untitled6_OBJECTS = \
"CMakeFiles/untitled6.dir/main.c.obj" \
"CMakeFiles/untitled6.dir/libs/string/string_.c.obj"

# External object files for target untitled6
untitled6_EXTERNAL_OBJECTS =

untitled6.exe: CMakeFiles/untitled6.dir/main.c.obj
untitled6.exe: CMakeFiles/untitled6.dir/libs/string/string_.c.obj
untitled6.exe: CMakeFiles/untitled6.dir/build.make
untitled6.exe: libstr.a
untitled6.exe: libs/data_structures/libdata_structures.a
untitled6.exe: libs/algorithms/libalgorithms.a
untitled6.exe: CMakeFiles/untitled6.dir/linklibs.rsp
untitled6.exe: CMakeFiles/untitled6.dir/objects1.rsp
untitled6.exe: CMakeFiles/untitled6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable untitled6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled6.dir/build: untitled6.exe

.PHONY : CMakeFiles/untitled6.dir/build

CMakeFiles/untitled6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled6.dir/clean

CMakeFiles/untitled6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6" "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6" "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\cmake-build-debug" "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\cmake-build-debug" "C:\Users\DeriliyDarkNight\test\Git project timeplay\untitled6\cmake-build-debug\CMakeFiles\untitled6.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/untitled6.dir/depend

