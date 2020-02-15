cmake_minimum_required(VERSION 3.0.0)
project(MATHS-CHALLENGE-QUIZ)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_TESTS "Run tests on compilation" off)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTS)
    add_subdirectory(test)
    enable_testing()
endif()

if (WIN32)
    add_compile_definitions(COMP_WINDOWS)
endif (WIN32)

add_subdirectory(include)

add_executable(Maths-Challenge-Quiz Main.cpp)

target_link_libraries(Maths-Challenge-Quiz
    PRIVATE 
        includes
)

target_link_libraries(Maths-Challenge-Quiz
    PRIVATE 
        round-includes
)