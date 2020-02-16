cmake_minimum_required(VERSION 3.0.0)

project(tests LANGUAGES CXX VERSION 0.0.1)

include(catch2/Catch.cmake)

add_executable(RunTests RunTests.cpp)
target_link_libraries(RunTests includes)
target_link_libraries(RunTests round-includes)

target_include_directories(RunTests PUBLIC ..)

catch_discover_tests(RunTests)