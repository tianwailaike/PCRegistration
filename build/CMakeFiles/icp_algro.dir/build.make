# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ubuntu/lyc2017/pcp/PCRegistration

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/lyc2017/pcp/PCRegistration/build

# Include any dependencies generated for this target.
include CMakeFiles/icp_algro.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/icp_algro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/icp_algro.dir/flags.make

CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o: CMakeFiles/icp_algro.dir/flags.make
CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o: ../src/icprefine/mestimator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o -c /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/mestimator.cpp

CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/mestimator.cpp > CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.i

CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/mestimator.cpp -o CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.s

CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o.requires:

.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o.requires

CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o.provides: CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o.requires
	$(MAKE) -f CMakeFiles/icp_algro.dir/build.make CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o.provides.build
.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o.provides

CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o.provides.build: CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o


CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o: CMakeFiles/icp_algro.dir/flags.make
CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o: ../src/icprefine/error_point_to_plane_sim3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o -c /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_plane_sim3.cpp

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_plane_sim3.cpp > CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.i

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_plane_sim3.cpp -o CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.s

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o.requires:

.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o.requires

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o.provides: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o.requires
	$(MAKE) -f CMakeFiles/icp_algro.dir/build.make CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o.provides.build
.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o.provides

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o.provides.build: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o


CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o: CMakeFiles/icp_algro.dir/flags.make
CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o: ../src/icprefine/error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o -c /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error.cpp

CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error.cpp > CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.i

CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error.cpp -o CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.s

CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o.requires:

.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o.requires

CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o.provides: CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o.requires
	$(MAKE) -f CMakeFiles/icp_algro.dir/build.make CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o.provides.build
.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o.provides

CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o.provides.build: CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o


CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o: CMakeFiles/icp_algro.dir/flags.make
CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o: ../src/icprefine/error_point_to_point_sim3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o -c /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_point_sim3.cpp

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_point_sim3.cpp > CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.i

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_point_sim3.cpp -o CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.s

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o.requires:

.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o.requires

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o.provides: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o.requires
	$(MAKE) -f CMakeFiles/icp_algro.dir/build.make CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o.provides.build
.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o.provides

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o.provides.build: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o


CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o: CMakeFiles/icp_algro.dir/flags.make
CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o: ../src/icprefine/error_point_to_point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o -c /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_point.cpp

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_point.cpp > CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.i

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_point.cpp -o CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.s

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o.requires:

.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o.requires

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o.provides: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o.requires
	$(MAKE) -f CMakeFiles/icp_algro.dir/build.make CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o.provides.build
.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o.provides

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o.provides.build: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o


CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o: CMakeFiles/icp_algro.dir/flags.make
CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o: ../src/icprefine/error_point_to_plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o -c /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_plane.cpp

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_plane.cpp > CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.i

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/error_point_to_plane.cpp -o CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.s

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o.requires:

.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o.requires

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o.provides: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o.requires
	$(MAKE) -f CMakeFiles/icp_algro.dir/build.make CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o.provides.build
.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o.provides

CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o.provides.build: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o


CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o: CMakeFiles/icp_algro.dir/flags.make
CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o: ../src/icprefine/icp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o -c /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/icp.cpp

CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/icp.cpp > CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.i

CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/icp.cpp -o CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.s

CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o.requires:

.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o.requires

CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o.provides: CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o.requires
	$(MAKE) -f CMakeFiles/icp_algro.dir/build.make CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o.provides.build
.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o.provides

CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o.provides.build: CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o


CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o: CMakeFiles/icp_algro.dir/flags.make
CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o: ../src/icprefine/mestimator_hubert.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o -c /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/mestimator_hubert.cpp

CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/mestimator_hubert.cpp > CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.i

CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/lyc2017/pcp/PCRegistration/src/icprefine/mestimator_hubert.cpp -o CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.s

CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o.requires:

.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o.requires

CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o.provides: CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o.requires
	$(MAKE) -f CMakeFiles/icp_algro.dir/build.make CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o.provides.build
.PHONY : CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o.provides

CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o.provides.build: CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o


# Object files for target icp_algro
icp_algro_OBJECTS = \
"CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o" \
"CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o" \
"CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o" \
"CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o" \
"CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o" \
"CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o" \
"CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o" \
"CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o"

# External object files for target icp_algro
icp_algro_EXTERNAL_OBJECTS =

../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o
../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o
../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o
../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o
../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o
../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o
../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o
../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o
../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/build.make
../lib/libicp_algro.a: CMakeFiles/icp_algro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library ../lib/libicp_algro.a"
	$(CMAKE_COMMAND) -P CMakeFiles/icp_algro.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/icp_algro.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/icp_algro.dir/build: ../lib/libicp_algro.a

.PHONY : CMakeFiles/icp_algro.dir/build

CMakeFiles/icp_algro.dir/requires: CMakeFiles/icp_algro.dir/src/icprefine/mestimator.cpp.o.requires
CMakeFiles/icp_algro.dir/requires: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane_sim3.cpp.o.requires
CMakeFiles/icp_algro.dir/requires: CMakeFiles/icp_algro.dir/src/icprefine/error.cpp.o.requires
CMakeFiles/icp_algro.dir/requires: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point_sim3.cpp.o.requires
CMakeFiles/icp_algro.dir/requires: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_point.cpp.o.requires
CMakeFiles/icp_algro.dir/requires: CMakeFiles/icp_algro.dir/src/icprefine/error_point_to_plane.cpp.o.requires
CMakeFiles/icp_algro.dir/requires: CMakeFiles/icp_algro.dir/src/icprefine/icp.cpp.o.requires
CMakeFiles/icp_algro.dir/requires: CMakeFiles/icp_algro.dir/src/icprefine/mestimator_hubert.cpp.o.requires

.PHONY : CMakeFiles/icp_algro.dir/requires

CMakeFiles/icp_algro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/icp_algro.dir/cmake_clean.cmake
.PHONY : CMakeFiles/icp_algro.dir/clean

CMakeFiles/icp_algro.dir/depend:
	cd /home/ubuntu/lyc2017/pcp/PCRegistration/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/lyc2017/pcp/PCRegistration /home/ubuntu/lyc2017/pcp/PCRegistration /home/ubuntu/lyc2017/pcp/PCRegistration/build /home/ubuntu/lyc2017/pcp/PCRegistration/build /home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles/icp_algro.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/icp_algro.dir/depend

