# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/Project/tinyrenderer/cloud_render

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Project/tinyrenderer/cloud_render/build

# Include any dependencies generated for this target.
include CMakeFiles/cloudrender.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cloudrender.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cloudrender.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cloudrender.dir/flags.make

CMakeFiles/cloudrender.dir/main.cpp.o: CMakeFiles/cloudrender.dir/flags.make
CMakeFiles/cloudrender.dir/main.cpp.o: /root/Project/tinyrenderer/cloud_render/main.cpp
CMakeFiles/cloudrender.dir/main.cpp.o: CMakeFiles/cloudrender.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/Project/tinyrenderer/cloud_render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cloudrender.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cloudrender.dir/main.cpp.o -MF CMakeFiles/cloudrender.dir/main.cpp.o.d -o CMakeFiles/cloudrender.dir/main.cpp.o -c /root/Project/tinyrenderer/cloud_render/main.cpp

CMakeFiles/cloudrender.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cloudrender.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Project/tinyrenderer/cloud_render/main.cpp > CMakeFiles/cloudrender.dir/main.cpp.i

CMakeFiles/cloudrender.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cloudrender.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Project/tinyrenderer/cloud_render/main.cpp -o CMakeFiles/cloudrender.dir/main.cpp.s

CMakeFiles/cloudrender.dir/tgaimage.cpp.o: CMakeFiles/cloudrender.dir/flags.make
CMakeFiles/cloudrender.dir/tgaimage.cpp.o: /root/Project/tinyrenderer/cloud_render/tgaimage.cpp
CMakeFiles/cloudrender.dir/tgaimage.cpp.o: CMakeFiles/cloudrender.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/Project/tinyrenderer/cloud_render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cloudrender.dir/tgaimage.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cloudrender.dir/tgaimage.cpp.o -MF CMakeFiles/cloudrender.dir/tgaimage.cpp.o.d -o CMakeFiles/cloudrender.dir/tgaimage.cpp.o -c /root/Project/tinyrenderer/cloud_render/tgaimage.cpp

CMakeFiles/cloudrender.dir/tgaimage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cloudrender.dir/tgaimage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Project/tinyrenderer/cloud_render/tgaimage.cpp > CMakeFiles/cloudrender.dir/tgaimage.cpp.i

CMakeFiles/cloudrender.dir/tgaimage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cloudrender.dir/tgaimage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Project/tinyrenderer/cloud_render/tgaimage.cpp -o CMakeFiles/cloudrender.dir/tgaimage.cpp.s

CMakeFiles/cloudrender.dir/model.cpp.o: CMakeFiles/cloudrender.dir/flags.make
CMakeFiles/cloudrender.dir/model.cpp.o: /root/Project/tinyrenderer/cloud_render/model.cpp
CMakeFiles/cloudrender.dir/model.cpp.o: CMakeFiles/cloudrender.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/Project/tinyrenderer/cloud_render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cloudrender.dir/model.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cloudrender.dir/model.cpp.o -MF CMakeFiles/cloudrender.dir/model.cpp.o.d -o CMakeFiles/cloudrender.dir/model.cpp.o -c /root/Project/tinyrenderer/cloud_render/model.cpp

CMakeFiles/cloudrender.dir/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cloudrender.dir/model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Project/tinyrenderer/cloud_render/model.cpp > CMakeFiles/cloudrender.dir/model.cpp.i

CMakeFiles/cloudrender.dir/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cloudrender.dir/model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Project/tinyrenderer/cloud_render/model.cpp -o CMakeFiles/cloudrender.dir/model.cpp.s

# Object files for target cloudrender
cloudrender_OBJECTS = \
"CMakeFiles/cloudrender.dir/main.cpp.o" \
"CMakeFiles/cloudrender.dir/tgaimage.cpp.o" \
"CMakeFiles/cloudrender.dir/model.cpp.o"

# External object files for target cloudrender
cloudrender_EXTERNAL_OBJECTS =

cloudrender: CMakeFiles/cloudrender.dir/main.cpp.o
cloudrender: CMakeFiles/cloudrender.dir/tgaimage.cpp.o
cloudrender: CMakeFiles/cloudrender.dir/model.cpp.o
cloudrender: CMakeFiles/cloudrender.dir/build.make
cloudrender: CMakeFiles/cloudrender.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/root/Project/tinyrenderer/cloud_render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cloudrender"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cloudrender.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cloudrender.dir/build: cloudrender
.PHONY : CMakeFiles/cloudrender.dir/build

CMakeFiles/cloudrender.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cloudrender.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cloudrender.dir/clean

CMakeFiles/cloudrender.dir/depend:
	cd /root/Project/tinyrenderer/cloud_render/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Project/tinyrenderer/cloud_render /root/Project/tinyrenderer/cloud_render /root/Project/tinyrenderer/cloud_render/build /root/Project/tinyrenderer/cloud_render/build /root/Project/tinyrenderer/cloud_render/build/CMakeFiles/cloudrender.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cloudrender.dir/depend

