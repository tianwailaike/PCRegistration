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

# Utility rule file for super4pcs_automoc.

# Include the progress variables for this target.
include CMakeFiles/super4pcs_automoc.dir/progress.make

CMakeFiles/super4pcs_automoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic moc for target super4pcs"
	/usr/bin/cmake -E cmake_autogen /home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles/super4pcs_automoc.dir/ Release

super4pcs_automoc: CMakeFiles/super4pcs_automoc
super4pcs_automoc: CMakeFiles/super4pcs_automoc.dir/build.make

.PHONY : super4pcs_automoc

# Rule to build all files generated by this target.
CMakeFiles/super4pcs_automoc.dir/build: super4pcs_automoc

.PHONY : CMakeFiles/super4pcs_automoc.dir/build

CMakeFiles/super4pcs_automoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/super4pcs_automoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/super4pcs_automoc.dir/clean

CMakeFiles/super4pcs_automoc.dir/depend:
	cd /home/ubuntu/lyc2017/pcp/PCRegistration/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/lyc2017/pcp/PCRegistration /home/ubuntu/lyc2017/pcp/PCRegistration /home/ubuntu/lyc2017/pcp/PCRegistration/build /home/ubuntu/lyc2017/pcp/PCRegistration/build /home/ubuntu/lyc2017/pcp/PCRegistration/build/CMakeFiles/super4pcs_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/super4pcs_automoc.dir/depend

