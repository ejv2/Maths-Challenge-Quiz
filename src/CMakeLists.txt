add_library(includes STATIC
            Scoring.cpp
            Startup.cpp
            CommandLine.cpp
            Util.cpp)

add_library(round-includes STATIC
            round/BaseRound.cpp
            round/ArithmeticRound.cpp
            round/MultiplicationRound.cpp
            round/DivisionRound.cpp
            round/SpeedRound.cpp
            round/SkipRound.cpp
            round/DilemmaRound.cpp
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
