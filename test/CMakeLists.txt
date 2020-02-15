cmake_minimum_required(VERSION 3.0.0)

project(tests LANGUAGES CXX VERSION 0.0.1)

include(catch2/Catch.cmake)

add_executable(RunTests RunTests.cpp)

catch_discover_tests(RunTests)