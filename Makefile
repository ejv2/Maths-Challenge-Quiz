# UNIX-style makefile provided for convenience when used on *NIX platforms
.POSIX:

SRC = Main.cpp src/Util.cpp src/Scoring.cpp src/round/SkipRound.cpp \
      src/round/MultiplicationRound.cpp src/round/RoundUtils.cpp \
      src/round/BaseRound.cpp src/round/DivisionRound.cpp \
      src/round/SpeedRound.cpp src/round/DilemmaRound.cpp \
      src/round/ArithmeticRound.cpp src/Startup.cpp src/CommandLine.cpp
HDR = include/Scoring.hpp include/Util.hpp include/round/DilemmaRound.hpp \
      include/round/MultiplicationRound.hpp include/round/ArithmeticRound.hpp \
      include/round/DivisionRound.hpp include/round/SkipRound.hpp \
      include/round/BaseRound.hpp include/round/Round.hpp include/round/SpeedRound.hpp \
      include/round/RoundUtils.hpp include/Constants.hpp include/CommandLine.hpp \
      include/Startup.hpp

OBJ = ${SRC:.cpp=.o}
EXE = mcq

MCFLAGS = -Iinclude/ -Iinclude/round/
MLDFLAGS= 

${EXE}: ${OBJ}
	${CXX} -o ${EXE} ${OBJ}

${OBJ}: ${HDR}

.cpp.o:
	${CXX} -c ${CFLAGS} ${MCFLAGS} -o $(basename $<).o $<

clean:
	rm -f ${OBJ} ${EXE}

.PHONY: clean
