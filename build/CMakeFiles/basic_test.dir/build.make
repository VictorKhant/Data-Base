# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/victorkhant/DataBase

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/victorkhant/DataBase/build

# Include any dependencies generated for this target.
include CMakeFiles/basic_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/basic_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/basic_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basic_test.dir/flags.make

CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o: /Users/victorkhant/DataBase/_tests/_test_files/basic_test.cpp
CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o -MF CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o.d -o CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o -c /Users/victorkhant/DataBase/_tests/_test_files/basic_test.cpp

CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/_tests/_test_files/basic_test.cpp > CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.i

CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/_tests/_test_files/basic_test.cpp -o CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.s

CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.o: /Users/victorkhant/DataBase/includes/binary_files/file_record.cpp
CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.o -MF CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.o.d -o CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.o -c /Users/victorkhant/DataBase/includes/binary_files/file_record.cpp

CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/binary_files/file_record.cpp > CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.i

CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/binary_files/file_record.cpp -o CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.s

CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.o: /Users/victorkhant/DataBase/includes/binary_files/utilities.cpp
CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.o -MF CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.o.d -o CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.o -c /Users/victorkhant/DataBase/includes/binary_files/utilities.cpp

CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/binary_files/utilities.cpp > CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.i

CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/binary_files/utilities.cpp -o CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.s

CMakeFiles/basic_test.dir/includes/parser/parser.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/parser/parser.cpp.o: /Users/victorkhant/DataBase/includes/parser/parser.cpp
CMakeFiles/basic_test.dir/includes/parser/parser.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/basic_test.dir/includes/parser/parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/parser/parser.cpp.o -MF CMakeFiles/basic_test.dir/includes/parser/parser.cpp.o.d -o CMakeFiles/basic_test.dir/includes/parser/parser.cpp.o -c /Users/victorkhant/DataBase/includes/parser/parser.cpp

CMakeFiles/basic_test.dir/includes/parser/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/parser/parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/parser/parser.cpp > CMakeFiles/basic_test.dir/includes/parser/parser.cpp.i

CMakeFiles/basic_test.dir/includes/parser/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/parser/parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/parser/parser.cpp -o CMakeFiles/basic_test.dir/includes/parser/parser.cpp.s

CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.o: /Users/victorkhant/DataBase/includes/shunting_yard/shunting_yard.cpp
CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.o -MF CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.o.d -o CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.o -c /Users/victorkhant/DataBase/includes/shunting_yard/shunting_yard.cpp

CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/shunting_yard/shunting_yard.cpp > CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.i

CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/shunting_yard/shunting_yard.cpp -o CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.s

CMakeFiles/basic_test.dir/includes/sql/sql.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/sql/sql.cpp.o: /Users/victorkhant/DataBase/includes/sql/sql.cpp
CMakeFiles/basic_test.dir/includes/sql/sql.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/basic_test.dir/includes/sql/sql.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/sql/sql.cpp.o -MF CMakeFiles/basic_test.dir/includes/sql/sql.cpp.o.d -o CMakeFiles/basic_test.dir/includes/sql/sql.cpp.o -c /Users/victorkhant/DataBase/includes/sql/sql.cpp

CMakeFiles/basic_test.dir/includes/sql/sql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/sql/sql.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/sql/sql.cpp > CMakeFiles/basic_test.dir/includes/sql/sql.cpp.i

CMakeFiles/basic_test.dir/includes/sql/sql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/sql/sql.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/sql/sql.cpp -o CMakeFiles/basic_test.dir/includes/sql/sql.cpp.s

CMakeFiles/basic_test.dir/includes/stub/stub.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/stub/stub.cpp.o: /Users/victorkhant/DataBase/includes/stub/stub.cpp
CMakeFiles/basic_test.dir/includes/stub/stub.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/basic_test.dir/includes/stub/stub.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/stub/stub.cpp.o -MF CMakeFiles/basic_test.dir/includes/stub/stub.cpp.o.d -o CMakeFiles/basic_test.dir/includes/stub/stub.cpp.o -c /Users/victorkhant/DataBase/includes/stub/stub.cpp

CMakeFiles/basic_test.dir/includes/stub/stub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/stub/stub.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/stub/stub.cpp > CMakeFiles/basic_test.dir/includes/stub/stub.cpp.i

CMakeFiles/basic_test.dir/includes/stub/stub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/stub/stub.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/stub/stub.cpp -o CMakeFiles/basic_test.dir/includes/stub/stub.cpp.s

CMakeFiles/basic_test.dir/includes/table/table.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/table/table.cpp.o: /Users/victorkhant/DataBase/includes/table/table.cpp
CMakeFiles/basic_test.dir/includes/table/table.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/basic_test.dir/includes/table/table.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/table/table.cpp.o -MF CMakeFiles/basic_test.dir/includes/table/table.cpp.o.d -o CMakeFiles/basic_test.dir/includes/table/table.cpp.o -c /Users/victorkhant/DataBase/includes/table/table.cpp

CMakeFiles/basic_test.dir/includes/table/table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/table/table.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/table/table.cpp > CMakeFiles/basic_test.dir/includes/table/table.cpp.i

CMakeFiles/basic_test.dir/includes/table/table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/table/table.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/table/table.cpp -o CMakeFiles/basic_test.dir/includes/table/table.cpp.s

CMakeFiles/basic_test.dir/includes/token/token.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/token/token.cpp.o: /Users/victorkhant/DataBase/includes/token/token.cpp
CMakeFiles/basic_test.dir/includes/token/token.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/basic_test.dir/includes/token/token.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/token/token.cpp.o -MF CMakeFiles/basic_test.dir/includes/token/token.cpp.o.d -o CMakeFiles/basic_test.dir/includes/token/token.cpp.o -c /Users/victorkhant/DataBase/includes/token/token.cpp

CMakeFiles/basic_test.dir/includes/token/token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/token/token.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/token/token.cpp > CMakeFiles/basic_test.dir/includes/token/token.cpp.i

CMakeFiles/basic_test.dir/includes/token/token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/token/token.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/token/token.cpp -o CMakeFiles/basic_test.dir/includes/token/token.cpp.s

CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.o: /Users/victorkhant/DataBase/includes/tokenizer/ftokenize.cpp
CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.o -MF CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.o.d -o CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.o -c /Users/victorkhant/DataBase/includes/tokenizer/ftokenize.cpp

CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/tokenizer/ftokenize.cpp > CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.i

CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/tokenizer/ftokenize.cpp -o CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.s

CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.o: /Users/victorkhant/DataBase/includes/tokenizer/state_machine_functions.cpp
CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.o -MF CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.o.d -o CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.o -c /Users/victorkhant/DataBase/includes/tokenizer/state_machine_functions.cpp

CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/tokenizer/state_machine_functions.cpp > CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.i

CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/tokenizer/state_machine_functions.cpp -o CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.s

CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.o: /Users/victorkhant/DataBase/includes/tokenizer/stokenize.cpp
CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.o -MF CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.o.d -o CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.o -c /Users/victorkhant/DataBase/includes/tokenizer/stokenize.cpp

CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/tokenizer/stokenize.cpp > CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.i

CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/tokenizer/stokenize.cpp -o CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.s

CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.o: CMakeFiles/basic_test.dir/flags.make
CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.o: /Users/victorkhant/DataBase/includes/tokenizer/token.cpp
CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.o: CMakeFiles/basic_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.o -MF CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.o.d -o CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.o -c /Users/victorkhant/DataBase/includes/tokenizer/token.cpp

CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/victorkhant/DataBase/includes/tokenizer/token.cpp > CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.i

CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/victorkhant/DataBase/includes/tokenizer/token.cpp -o CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.s

# Object files for target basic_test
basic_test_OBJECTS = \
"CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o" \
"CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.o" \
"CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.o" \
"CMakeFiles/basic_test.dir/includes/parser/parser.cpp.o" \
"CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.o" \
"CMakeFiles/basic_test.dir/includes/sql/sql.cpp.o" \
"CMakeFiles/basic_test.dir/includes/stub/stub.cpp.o" \
"CMakeFiles/basic_test.dir/includes/table/table.cpp.o" \
"CMakeFiles/basic_test.dir/includes/token/token.cpp.o" \
"CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.o" \
"CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.o" \
"CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.o" \
"CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.o"

# External object files for target basic_test
basic_test_EXTERNAL_OBJECTS =

bin/basic_test: CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/binary_files/file_record.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/binary_files/utilities.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/parser/parser.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/shunting_yard/shunting_yard.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/sql/sql.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/stub/stub.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/table/table.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/token/token.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/tokenizer/ftokenize.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/tokenizer/state_machine_functions.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/tokenizer/stokenize.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/includes/tokenizer/token.cpp.o
bin/basic_test: CMakeFiles/basic_test.dir/build.make
bin/basic_test: lib/libgtest.a
bin/basic_test: CMakeFiles/basic_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/victorkhant/DataBase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable bin/basic_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basic_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basic_test.dir/build: bin/basic_test
.PHONY : CMakeFiles/basic_test.dir/build

CMakeFiles/basic_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/basic_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/basic_test.dir/clean

CMakeFiles/basic_test.dir/depend:
	cd /Users/victorkhant/DataBase/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/victorkhant/DataBase /Users/victorkhant/DataBase /Users/victorkhant/DataBase/build /Users/victorkhant/DataBase/build /Users/victorkhant/DataBase/build/CMakeFiles/basic_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/basic_test.dir/depend

