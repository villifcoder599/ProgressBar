# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Francesco Villi\CLionProjects\ProgressBar"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Francesco Villi\CLionProjects\ProgressBar\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ProgressBar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProgressBar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProgressBar.dir/flags.make

CMakeFiles/ProgressBar.dir/ProgressBar.cpp.obj: CMakeFiles/ProgressBar.dir/flags.make
CMakeFiles/ProgressBar.dir/ProgressBar.cpp.obj: CMakeFiles/ProgressBar.dir/includes_CXX.rsp
CMakeFiles/ProgressBar.dir/ProgressBar.cpp.obj: ../ProgressBar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Francesco Villi\CLionProjects\ProgressBar\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProgressBar.dir/ProgressBar.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ProgressBar.dir\ProgressBar.cpp.obj -c "C:\Users\Francesco Villi\CLionProjects\ProgressBar\ProgressBar.cpp"

CMakeFiles/ProgressBar.dir/ProgressBar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgressBar.dir/ProgressBar.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Francesco Villi\CLionProjects\ProgressBar\ProgressBar.cpp" > CMakeFiles\ProgressBar.dir\ProgressBar.cpp.i

CMakeFiles/ProgressBar.dir/ProgressBar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgressBar.dir/ProgressBar.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Francesco Villi\CLionProjects\ProgressBar\ProgressBar.cpp" -o CMakeFiles\ProgressBar.dir\ProgressBar.cpp.s

CMakeFiles/ProgressBar.dir/Observer.cpp.obj: CMakeFiles/ProgressBar.dir/flags.make
CMakeFiles/ProgressBar.dir/Observer.cpp.obj: CMakeFiles/ProgressBar.dir/includes_CXX.rsp
CMakeFiles/ProgressBar.dir/Observer.cpp.obj: ../Observer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Francesco Villi\CLionProjects\ProgressBar\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProgressBar.dir/Observer.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ProgressBar.dir\Observer.cpp.obj -c "C:\Users\Francesco Villi\CLionProjects\ProgressBar\Observer.cpp"

CMakeFiles/ProgressBar.dir/Observer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgressBar.dir/Observer.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Francesco Villi\CLionProjects\ProgressBar\Observer.cpp" > CMakeFiles\ProgressBar.dir\Observer.cpp.i

CMakeFiles/ProgressBar.dir/Observer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgressBar.dir/Observer.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Francesco Villi\CLionProjects\ProgressBar\Observer.cpp" -o CMakeFiles\ProgressBar.dir\Observer.cpp.s

CMakeFiles/ProgressBar.dir/Subject.cpp.obj: CMakeFiles/ProgressBar.dir/flags.make
CMakeFiles/ProgressBar.dir/Subject.cpp.obj: CMakeFiles/ProgressBar.dir/includes_CXX.rsp
CMakeFiles/ProgressBar.dir/Subject.cpp.obj: ../Subject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Francesco Villi\CLionProjects\ProgressBar\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProgressBar.dir/Subject.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ProgressBar.dir\Subject.cpp.obj -c "C:\Users\Francesco Villi\CLionProjects\ProgressBar\Subject.cpp"

CMakeFiles/ProgressBar.dir/Subject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgressBar.dir/Subject.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Francesco Villi\CLionProjects\ProgressBar\Subject.cpp" > CMakeFiles\ProgressBar.dir\Subject.cpp.i

CMakeFiles/ProgressBar.dir/Subject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgressBar.dir/Subject.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Francesco Villi\CLionProjects\ProgressBar\Subject.cpp" -o CMakeFiles\ProgressBar.dir\Subject.cpp.s

CMakeFiles/ProgressBar.dir/Loader.cpp.obj: CMakeFiles/ProgressBar.dir/flags.make
CMakeFiles/ProgressBar.dir/Loader.cpp.obj: CMakeFiles/ProgressBar.dir/includes_CXX.rsp
CMakeFiles/ProgressBar.dir/Loader.cpp.obj: ../Loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Francesco Villi\CLionProjects\ProgressBar\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProgressBar.dir/Loader.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ProgressBar.dir\Loader.cpp.obj -c "C:\Users\Francesco Villi\CLionProjects\ProgressBar\Loader.cpp"

CMakeFiles/ProgressBar.dir/Loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgressBar.dir/Loader.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Francesco Villi\CLionProjects\ProgressBar\Loader.cpp" > CMakeFiles\ProgressBar.dir\Loader.cpp.i

CMakeFiles/ProgressBar.dir/Loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgressBar.dir/Loader.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Francesco Villi\CLionProjects\ProgressBar\Loader.cpp" -o CMakeFiles\ProgressBar.dir\Loader.cpp.s

# Object files for target ProgressBar
ProgressBar_OBJECTS = \
"CMakeFiles/ProgressBar.dir/ProgressBar.cpp.obj" \
"CMakeFiles/ProgressBar.dir/Observer.cpp.obj" \
"CMakeFiles/ProgressBar.dir/Subject.cpp.obj" \
"CMakeFiles/ProgressBar.dir/Loader.cpp.obj"

# External object files for target ProgressBar
ProgressBar_EXTERNAL_OBJECTS =

ProgressBar.exe: CMakeFiles/ProgressBar.dir/ProgressBar.cpp.obj
ProgressBar.exe: CMakeFiles/ProgressBar.dir/Observer.cpp.obj
ProgressBar.exe: CMakeFiles/ProgressBar.dir/Subject.cpp.obj
ProgressBar.exe: CMakeFiles/ProgressBar.dir/Loader.cpp.obj
ProgressBar.exe: CMakeFiles/ProgressBar.dir/build.make
ProgressBar.exe: C:/wxWidgets-3.1.4/lib/gcc_lib/libwxmsw31ud_core.a
ProgressBar.exe: C:/wxWidgets-3.1.4/lib/gcc_lib/libwxbase31ud.a
ProgressBar.exe: C:/wxWidgets-3.1.4/lib/gcc_lib/libwxpngd.a
ProgressBar.exe: C:/wxWidgets-3.1.4/lib/gcc_lib/libwxtiffd.a
ProgressBar.exe: C:/wxWidgets-3.1.4/lib/gcc_lib/libwxjpegd.a
ProgressBar.exe: C:/wxWidgets-3.1.4/lib/gcc_lib/libwxzlibd.a
ProgressBar.exe: C:/wxWidgets-3.1.4/lib/gcc_lib/libwxregexud.a
ProgressBar.exe: C:/wxWidgets-3.1.4/lib/gcc_lib/libwxexpatd.a
ProgressBar.exe: CMakeFiles/ProgressBar.dir/linklibs.rsp
ProgressBar.exe: CMakeFiles/ProgressBar.dir/objects1.rsp
ProgressBar.exe: CMakeFiles/ProgressBar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Francesco Villi\CLionProjects\ProgressBar\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ProgressBar.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProgressBar.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProgressBar.dir/build: ProgressBar.exe

.PHONY : CMakeFiles/ProgressBar.dir/build

CMakeFiles/ProgressBar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProgressBar.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProgressBar.dir/clean

CMakeFiles/ProgressBar.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Francesco Villi\CLionProjects\ProgressBar" "C:\Users\Francesco Villi\CLionProjects\ProgressBar" "C:\Users\Francesco Villi\CLionProjects\ProgressBar\cmake-build-debug" "C:\Users\Francesco Villi\CLionProjects\ProgressBar\cmake-build-debug" "C:\Users\Francesco Villi\CLionProjects\ProgressBar\cmake-build-debug\CMakeFiles\ProgressBar.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ProgressBar.dir/depend

