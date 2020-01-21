cmake_minimum_required(VERSION 3.0.0)
project(MATHS-CHALLENGE-QUIZ)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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