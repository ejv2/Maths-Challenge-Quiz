# UNIX-style makefile provided for convenience when used on *NIX platforms
.POSIX:

SRC = Main.cpp src/Util.cpp src/Scoring.cpp src/round/SkipRound.cpp \
      src/round/MultiplicationRound.cpp src/round/RoundUtils.cpp \
      src/round/BaseRound.cpp src/round/DivisionRound.cpp \
      src/round/SpeedRound.cpp src/round/DilemmaRound.cpp \
      src/round/ArithmeticRound.cpp src/Startup.cpp src/CommandLine.cpp
HDR = include/Scoring.h include/Util.h include/round/DilemmaRound.h \
      include/round/MultiplicationRound.h include/round/ArithmeticRound.h \
      include/round/DivisionRound.h include/round/SkipRound.h \
      include/round/BaseRound.h include/round/Round.h include/round/SpeedRound.h \
      include/round/RoundUtils.h include/Constants.h include/CommandLine.h \
      include/Startup.h

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
