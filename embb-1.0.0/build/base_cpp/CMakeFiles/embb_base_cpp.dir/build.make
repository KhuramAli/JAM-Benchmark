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
include base_cpp/CMakeFiles/embb_base_cpp.dir/depend.make

# Include the progress variables for this target.
include base_cpp/CMakeFiles/embb_base_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make

base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o: base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make
base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o: ../base_cpp/src/condition_variable.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/condition_variable.cc

base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/condition_variable.cc > CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.i

base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/condition_variable.cc -o CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.s

base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o.requires:

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o.requires

base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o.provides: base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o.requires
	$(MAKE) -f base_cpp/CMakeFiles/embb_base_cpp.dir/build.make base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o.provides.build
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o.provides

base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o.provides.build: base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o


base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o: base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make
base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o: ../base_cpp/src/core_set.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/core_set.cc

base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_base_cpp.dir/src/core_set.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/core_set.cc > CMakeFiles/embb_base_cpp.dir/src/core_set.cc.i

base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_base_cpp.dir/src/core_set.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/core_set.cc -o CMakeFiles/embb_base_cpp.dir/src/core_set.cc.s

base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o.requires:

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o.requires

base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o.provides: base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o.requires
	$(MAKE) -f base_cpp/CMakeFiles/embb_base_cpp.dir/build.make base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o.provides.build
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o.provides

base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o.provides.build: base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o


base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o: base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make
base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o: ../base_cpp/src/duration.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_base_cpp.dir/src/duration.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/duration.cc

base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_base_cpp.dir/src/duration.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/duration.cc > CMakeFiles/embb_base_cpp.dir/src/duration.cc.i

base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_base_cpp.dir/src/duration.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/duration.cc -o CMakeFiles/embb_base_cpp.dir/src/duration.cc.s

base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o.requires:

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o.requires

base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o.provides: base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o.requires
	$(MAKE) -f base_cpp/CMakeFiles/embb_base_cpp.dir/build.make base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o.provides.build
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o.provides

base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o.provides.build: base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o


base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o: base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make
base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o: ../base_cpp/src/function.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_base_cpp.dir/src/function.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/function.cc

base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_base_cpp.dir/src/function.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/function.cc > CMakeFiles/embb_base_cpp.dir/src/function.cc.i

base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_base_cpp.dir/src/function.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/function.cc -o CMakeFiles/embb_base_cpp.dir/src/function.cc.s

base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o.requires:

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o.requires

base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o.provides: base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o.requires
	$(MAKE) -f base_cpp/CMakeFiles/embb_base_cpp.dir/build.make base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o.provides.build
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o.provides

base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o.provides.build: base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o


base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o: base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make
base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o: ../base_cpp/src/log.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_base_cpp.dir/src/log.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/log.cc

base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_base_cpp.dir/src/log.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/log.cc > CMakeFiles/embb_base_cpp.dir/src/log.cc.i

base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_base_cpp.dir/src/log.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/log.cc -o CMakeFiles/embb_base_cpp.dir/src/log.cc.s

base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o.requires:

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o.requires

base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o.provides: base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o.requires
	$(MAKE) -f base_cpp/CMakeFiles/embb_base_cpp.dir/build.make base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o.provides.build
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o.provides

base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o.provides.build: base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o


base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o: base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make
base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o: ../base_cpp/src/memory_allocation.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/memory_allocation.cc

base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/memory_allocation.cc > CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.i

base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/memory_allocation.cc -o CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.s

base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o.requires:

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o.requires

base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o.provides: base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o.requires
	$(MAKE) -f base_cpp/CMakeFiles/embb_base_cpp.dir/build.make base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o.provides.build
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o.provides

base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o.provides.build: base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o


base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o: base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make
base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o: ../base_cpp/src/mutex.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/mutex.cc

base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_base_cpp.dir/src/mutex.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/mutex.cc > CMakeFiles/embb_base_cpp.dir/src/mutex.cc.i

base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_base_cpp.dir/src/mutex.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/mutex.cc -o CMakeFiles/embb_base_cpp.dir/src/mutex.cc.s

base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o.requires:

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o.requires

base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o.provides: base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o.requires
	$(MAKE) -f base_cpp/CMakeFiles/embb_base_cpp.dir/build.make base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o.provides.build
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o.provides

base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o.provides.build: base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o


base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o: base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make
base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o: ../base_cpp/src/thread.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_base_cpp.dir/src/thread.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/thread.cc

base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_base_cpp.dir/src/thread.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/thread.cc > CMakeFiles/embb_base_cpp.dir/src/thread.cc.i

base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_base_cpp.dir/src/thread.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/thread.cc -o CMakeFiles/embb_base_cpp.dir/src/thread.cc.s

base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o.requires:

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o.requires

base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o.provides: base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o.requires
	$(MAKE) -f base_cpp/CMakeFiles/embb_base_cpp.dir/build.make base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o.provides.build
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o.provides

base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o.provides.build: base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o


base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o: base_cpp/CMakeFiles/embb_base_cpp.dir/flags.make
base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o: ../base_cpp/src/time.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embb_base_cpp.dir/src/time.cc.o -c /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/time.cc

base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embb_base_cpp.dir/src/time.cc.i"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/time.cc > CMakeFiles/embb_base_cpp.dir/src/time.cc.i

base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embb_base_cpp.dir/src/time.cc.s"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp/src/time.cc -o CMakeFiles/embb_base_cpp.dir/src/time.cc.s

base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o.requires:

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o.requires

base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o.provides: base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o.requires
	$(MAKE) -f base_cpp/CMakeFiles/embb_base_cpp.dir/build.make base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o.provides.build
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o.provides

base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o.provides.build: base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o


# Object files for target embb_base_cpp
embb_base_cpp_OBJECTS = \
"CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o" \
"CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o" \
"CMakeFiles/embb_base_cpp.dir/src/duration.cc.o" \
"CMakeFiles/embb_base_cpp.dir/src/function.cc.o" \
"CMakeFiles/embb_base_cpp.dir/src/log.cc.o" \
"CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o" \
"CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o" \
"CMakeFiles/embb_base_cpp.dir/src/thread.cc.o" \
"CMakeFiles/embb_base_cpp.dir/src/time.cc.o"

# External object files for target embb_base_cpp
embb_base_cpp_EXTERNAL_OBJECTS =

base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/build.make
base_cpp/libembb_base_cpp.a: base_cpp/CMakeFiles/embb_base_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ali/git/JAM-Benchmark/embb-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libembb_base_cpp.a"
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && $(CMAKE_COMMAND) -P CMakeFiles/embb_base_cpp.dir/cmake_clean_target.cmake
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/embb_base_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base_cpp/CMakeFiles/embb_base_cpp.dir/build: base_cpp/libembb_base_cpp.a

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/build

base_cpp/CMakeFiles/embb_base_cpp.dir/requires: base_cpp/CMakeFiles/embb_base_cpp.dir/src/condition_variable.cc.o.requires
base_cpp/CMakeFiles/embb_base_cpp.dir/requires: base_cpp/CMakeFiles/embb_base_cpp.dir/src/core_set.cc.o.requires
base_cpp/CMakeFiles/embb_base_cpp.dir/requires: base_cpp/CMakeFiles/embb_base_cpp.dir/src/duration.cc.o.requires
base_cpp/CMakeFiles/embb_base_cpp.dir/requires: base_cpp/CMakeFiles/embb_base_cpp.dir/src/function.cc.o.requires
base_cpp/CMakeFiles/embb_base_cpp.dir/requires: base_cpp/CMakeFiles/embb_base_cpp.dir/src/log.cc.o.requires
base_cpp/CMakeFiles/embb_base_cpp.dir/requires: base_cpp/CMakeFiles/embb_base_cpp.dir/src/memory_allocation.cc.o.requires
base_cpp/CMakeFiles/embb_base_cpp.dir/requires: base_cpp/CMakeFiles/embb_base_cpp.dir/src/mutex.cc.o.requires
base_cpp/CMakeFiles/embb_base_cpp.dir/requires: base_cpp/CMakeFiles/embb_base_cpp.dir/src/thread.cc.o.requires
base_cpp/CMakeFiles/embb_base_cpp.dir/requires: base_cpp/CMakeFiles/embb_base_cpp.dir/src/time.cc.o.requires

.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/requires

base_cpp/CMakeFiles/embb_base_cpp.dir/clean:
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp && $(CMAKE_COMMAND) -P CMakeFiles/embb_base_cpp.dir/cmake_clean.cmake
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/clean

base_cpp/CMakeFiles/embb_base_cpp.dir/depend:
	cd /home/ali/git/JAM-Benchmark/embb-1.0.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ali/git/JAM-Benchmark/embb-1.0.0 /home/ali/git/JAM-Benchmark/embb-1.0.0/base_cpp /home/ali/git/JAM-Benchmark/embb-1.0.0/build /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp /home/ali/git/JAM-Benchmark/embb-1.0.0/build/base_cpp/CMakeFiles/embb_base_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base_cpp/CMakeFiles/embb_base_cpp.dir/depend

