# Maths Challenge Quiz - Makefile
# Copyright 2019 - Ethan Marshall
#
# To build the project, use make (or nmake/equivalents) to execute the makefile
# This will build an executable in the /build directory

executable_name_win = "Maths Challenge Quiz.exe"
executable_name_linux = "Maths Challenge Quiz"
build_destination = build/

dep_path = include/
main_file = Main.cpp
dep_files = $(dep_path)Round.cpp $(dep_path)Startup.cpp $(dep_path)Util.cpp

header_files = $(dep_path)Round.h $(dep_path)Startup.h $(dep_path)Util.h $(dep_path)Constants.h

linux_compiler = g++
windows_compiler = x86_64-w64-mingw32-g++

none: linux

windows: $(main_file) $(dep_files)
	@echo This option requires you to be on Linux, but compiles for Windows
	@echo By default, it attempts to use MinGW cross compiler
	@echo
	@echo WARNING: Certain functionality, including timings and delays, is currently broken on Windows, meaning that this build may be unstable

	$(windows_compiler) $(main_file) $(dep_files) -o $(executable_name_win) -DCOMP_WINDOWS=1 -static-libgcc -static-libstdc++
	mv $(executable_name_win) $(build_destination)$(executable_name_win)
	@echo Build succeeded

linux: $(main_file) $(dep_files)
	$(linux_compiler) -o $(executable_name_linux) $(main_file) $(dep_files)
	mv $(executable_name_linux) $(build_destination)$(executable_name_linux)
	@echo Build succeeded

clean:
	rm $(build_destination)$(executable_name_linux)
	rm .gdb_history

	@echo Project cleared

clean_windows:
	rm $(build_destination)$(executable_name_win)

	@echo Windows executable deleted
	@echo You may need to run "make clean" to clean up some other files