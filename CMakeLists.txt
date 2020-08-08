cmake_minimum_required(VERSION 3.5)

project(rt)

set(CMAKE_CXX_FLAGS "-O2 -std=c++17 -Wall -Wextra -pedantic")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
