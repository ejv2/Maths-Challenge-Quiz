# Maths Challenge Quiz - Makefile
# Copyright 2019 - Ethan Marshall
#
# To build the project, use make (or nmake/equivalents) to execute the makefile
# This will build an executable in the /build directory

executable_name_win = "Maths Challenge Quiz.exe"
executable_name_linux = "Maths Challenge Quiz"
build_destination = build/

dep_path = include/
dep_rpath = include/round/
main_file = Main.cpp

round_files = $(dep_rpath)BaseRound.cpp $(dep_rpath)ArithmeticRound.cpp $(dep_rpath)MultiplicationRound.cpp $(dep_rpath)DivisionRound.h $(dep_rpath)SpeedRound.cpp $(dep_rpath)SkipRound.cpp
dep_files = $(dep_path)Round.cpp $(dep_path)Startup.cpp $(dep_path)Util.cpp $(dep_path)Scoring.cpp $(dep_path)GameOver.cpp $(round_files)

header_files = $(dep_path)Round.h $(dep_path)Startup.h $(dep_path)Util.h $(dep_path)Constants.h

linux_compiler = g++
windows_compiler = x86_64-w64-mingw32-g++

none: linux

windows:
	@echo This option requires you to be on Linux, but compiles for Windows
	@echo By default, it attempts to use MinGW cross compiler
	@echo
	@echo WARNING: UNSTABLE BUILD
	@echo The windows build for this program is very buggy due to cross compile issues. Please expect crashes and issues with timing. Please report any issues you find nevertheless.

	$(windows_compiler) $(main_file) $(dep_files) -g -o $(executable_name_win) -DCOMP_WINDOWS=1 -static-libgcc -static-libstdc++
	mv $(executable_name_win) $(build_destination)$(executable_name_win)
	@echo Build succeeded

linux:
	$(linux_compiler) -g -o $(executable_name_linux) $(main_file) $(dep_files)
	mv $(executable_name_linux) $(build_destination)$(executable_name_linux)
	@echo Build succeeded

clean:
	rm $(build_destination)$(executable_name_linux)
	-rm $(build_destination).gdb_history
	-rm $(build_destination)$(executable_name_win)

	@echo Project cleared