# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ali/git/JAM-Benchmark/embb-1.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ali/git/JAM-Benchmark/embb-1.0.0/build

# Include any dependencies generated for this target.
include mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/depend.make

# Include the progress variables for this target.
include mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/progress.make

# Include the compile flags for this target's objects.
include mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/flags.make

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/flags.make
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o: ../mtapi_cpp/test/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/main.cc

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/main.cc > CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.i

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/main.cc -o CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.s

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o.requires:

.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o.requires

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o.provides: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o.requires
	$(MAKE) -f mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/build.make mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o.provides.build
.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o.provides

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o.provides.build: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o


mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/flags.make
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o: ../mtapi_cpp/test/mtapi_cpp_test_error.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_error.cc

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_error.cc > CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.i

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_error.cc -o CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.s

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o.requires:

.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o.requires

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o.provides: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o.requires
	$(MAKE) -f mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/build.make mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o.provides.build
.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o.provides

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o.provides.build: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o


mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/flags.make
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o: ../mtapi_cpp/test/mtapi_cpp_test_group.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_group.cc

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_group.cc > CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.i

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_group.cc -o CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.s

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o.requires:

.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o.requires

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o.provides: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o.requires
	$(MAKE) -f mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/build.make mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o.provides.build
.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o.provides

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o.provides.build: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o


mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/flags.make
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o: ../mtapi_cpp/test/mtapi_cpp_test_queue.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_queue.cc

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_queue.cc > CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.i

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_queue.cc -o CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.s

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o.requires:

.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o.requires

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o.provides: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o.requires
	$(MAKE) -f mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/build.make mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o.provides.build
.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o.provides

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o.provides.build: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o


mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/flags.make
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o: ../mtapi_cpp/test/mtapi_cpp_test_task.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_task.cc

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_task.cc > CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.i

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp/test/mtapi_cpp_test_task.cc -o CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.s

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o.requires:

.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o.requires

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o.provides: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o.requires
	$(MAKE) -f mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/build.make mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o.provides.build
.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o.provides

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o.provides.build: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o


# Object files for target embb_mtapi_cpp_test
embb_mtapi_cpp_test_OBJECTS = \
"CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o" \
"CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o" \
"CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o" \
"CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o" \
"CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o"

# External object files for target embb_mtapi_cpp_test
embb_mtapi_cpp_test_EXTERNAL_OBJECTS =

mtapi_cpp/embb_mtapi_cpp_test: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o
mtapi_cpp/embb_mtapi_cpp_test: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o
mtapi_cpp/embb_mtapi_cpp_test: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o
mtapi_cpp/embb_mtapi_cpp_test: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o
mtapi_cpp/embb_mtapi_cpp_test: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o
mtapi_cpp/embb_mtapi_cpp_test: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/build.make
mtapi_cpp/embb_mtapi_cpp_test: mtapi_cpp/libembb_mtapi_cpp.a
mtapi_cpp/embb_mtapi_cpp_test: mtapi_c/libembb_mtapi_c.a
mtapi_cpp/embb_mtapi_cpp_test: partest_build/libpartest.a
mtapi_cpp/embb_mtapi_cpp_test: base_cpp/libembb_base_cpp.a
mtapi_cpp/embb_mtapi_cpp_test: base_c/libembb_base_c.a
mtapi_cpp/embb_mtapi_cpp_test: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable embb_mtapi_cpp_test"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/embb_mtapi_cpp_test.dir/link.txt --verbose=$(VERBOSE)
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && /usr/bin/cmake -E copy /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp/embb_mtapi_cpp_test /home/ali/git/JAM-Benchmark/embb-1.0.0/build/binaries

# Rule to build all files generated by this target.
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/build: mtapi_cpp/embb_mtapi_cpp_test

.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/build

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/requires: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/main.cc.o.requires
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/requires: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_error.cc.o.requires
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/requires: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_group.cc.o.requires
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/requires: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_queue.cc.o.requires
mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/requires: mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/test/mtapi_cpp_test_task.cc.o.requires

.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/requires

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/clean:
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp && $(CMAKE_COMMAND) -P CMakeFiles/embb_mtapi_cpp_test.dir/cmake_clean.cmake
.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/clean

mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/depend:
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ali/git/JAM-Benchmark/embb-1.0.0 /home/ali/git/JAM-Benchmark/embb-1.0.0/mtapi_cpp /home/ali/git/JAM-Benchmark/embb-1.0.0/build /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp /home/ali/git/JAM-Benchmark/embb-1.0.0/build/mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mtapi_cpp/CMakeFiles/embb_mtapi_cpp_test.dir/depend

