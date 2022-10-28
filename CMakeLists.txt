cmake_minimum_required(VERSION 3.0.0)
project(MATHS-CHALLENGE-QUIZ)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (WIN32)
    add_compile_definitions(COMP_WINDOWS)
endif (WIN32)

add_subdirectory(src)

add_executable(mcq main.cpp)

target_link_libraries(mcq
    PRIVATE 
        includes
)

target_link_libraries(mcq
    PRIVATE 
        round-includes
)
