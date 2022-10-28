# UNIX-style makefile provided for convenience when used on *NIX platforms
.POSIX:

SRC = main.cpp src/util.cpp src/scoring.cpp src/round/skip.cpp \
      src/round/multiplication.cpp src/round/utils.cpp \
      src/round/base.cpp src/round/division.cpp \
      src/round/speed.cpp src/round/dilemma.cpp \
      src/round/arithmetic.cpp src/startup.cpp src/cmdline.cpp
HDR = include/scoring.hpp include/util.hpp include/round/dilemma.hpp \
      include/round/multiplication.hpp include/round/arithmetic.hpp \
      include/round/division.hpp include/round/skip.hpp \
      include/round/base.hpp include/round/round.hpp include/round/speed.hpp \
      include/round/roundutils.hpp include/const.hpp include/cmdline.hpp \
      include/startup.hpp

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
