# CMAKE generated file: DO NOT EDIT!
<<<<<<< HEAD
# Generated by "Unix Makefiles" Generator, CMake Version 3.20
=======
# Generated by "Unix Makefiles" Generator, CMake Version 3.22
>>>>>>> 78b1f60 (First commit.)

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
<<<<<<< HEAD
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f
=======
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f
>>>>>>> 78b1f60 (First commit.)

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
<<<<<<< HEAD
CMAKE_SOURCE_DIR = /home/karthik/IITB/MTP/tchecker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/karthik/IITB/MTP/tchecker
=======
CMAKE_SOURCE_DIR = /home/karthik/Computers/tchecker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/karthik/Computers/tchecker
>>>>>>> 78b1f60 (First commit.)

# Utility rule file for save-explore.

# Include any custom commands dependencies for this target.
include test/explore/CMakeFiles/save-explore.dir/compiler_depend.make

# Include the progress variables for this target.
include test/explore/CMakeFiles/save-explore.dir/progress.make

test/explore/CMakeFiles/save-explore:
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/karthik/IITB/MTP/tchecker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Saving results as expected ones from test/explore"
	cd /home/karthik/IITB/MTP/tchecker/test/explore && ../save-results.sh /home/karthik/IITB/MTP/tchecker/test/explore/save_tests.txt
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/karthik/Computers/tchecker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Saving results as expected ones from test/explore"
	cd /home/karthik/Computers/tchecker/test/explore && ../save-results.sh /home/karthik/Computers/tchecker/test/explore/save_tests.txt
>>>>>>> 78b1f60 (First commit.)

save-explore: test/explore/CMakeFiles/save-explore
save-explore: test/explore/CMakeFiles/save-explore.dir/build.make
.PHONY : save-explore

# Rule to build all files generated by this target.
test/explore/CMakeFiles/save-explore.dir/build: save-explore
.PHONY : test/explore/CMakeFiles/save-explore.dir/build

test/explore/CMakeFiles/save-explore.dir/clean:
<<<<<<< HEAD
	cd /home/karthik/IITB/MTP/tchecker/test/explore && $(CMAKE_COMMAND) -P CMakeFiles/save-explore.dir/cmake_clean.cmake
.PHONY : test/explore/CMakeFiles/save-explore.dir/clean

test/explore/CMakeFiles/save-explore.dir/depend:
	cd /home/karthik/IITB/MTP/tchecker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/karthik/IITB/MTP/tchecker /home/karthik/IITB/MTP/tchecker/test/explore /home/karthik/IITB/MTP/tchecker /home/karthik/IITB/MTP/tchecker/test/explore /home/karthik/IITB/MTP/tchecker/test/explore/CMakeFiles/save-explore.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /home/karthik/Computers/tchecker/test/explore && $(CMAKE_COMMAND) -P CMakeFiles/save-explore.dir/cmake_clean.cmake
.PHONY : test/explore/CMakeFiles/save-explore.dir/clean

test/explore/CMakeFiles/save-explore.dir/depend:
	cd /home/karthik/Computers/tchecker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/karthik/Computers/tchecker /home/karthik/Computers/tchecker/test/explore /home/karthik/Computers/tchecker /home/karthik/Computers/tchecker/test/explore /home/karthik/Computers/tchecker/test/explore/CMakeFiles/save-explore.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> 78b1f60 (First commit.)
.PHONY : test/explore/CMakeFiles/save-explore.dir/depend
