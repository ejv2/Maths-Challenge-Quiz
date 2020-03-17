add_library(includes STATIC
            Constants.h
            Scoring.h
            Scoring.cpp
            Startup.h
            Startup.cpp
            CommandLine.h
            CommandLine.cpp
            Util.h
            Util.cpp)

add_library(round-includes STATIC
            round/BaseRound.h
            round/BaseRound.cpp
            round/ArithmeticRound.h
            round/ArithmeticRound.cpp
            round/MultiplicationRound.h
            round/MultiplicationRound.cpp
            round/DivisionRound.h
            round/DivisionRound.cpp
            round/SpeedRound.h
            round/SpeedRound.cpp
            round/SkipRound.h
            round/SkipRound.cpp
            round/Round.h
            round/RoundUtils.h
            round/RoundUtils.cpp)

target_include_directories(includes
    PUBLIC
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(round-includes
    PUBLIC
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/round
)