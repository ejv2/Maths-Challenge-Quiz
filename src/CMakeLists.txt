add_library(includes STATIC
            scoring.cpp
            startup.cpp
            cmdline.cpp
            util.cpp)

add_library(round-includes STATIC
            round/base.cpp
            round/arithmetic.cpp
            round/multiplication.cpp
            round/division.cpp
            round/speed.cpp
            round/skip.cpp
            round/dilemma.cpp
            round/utils.cpp)

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
