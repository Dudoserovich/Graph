cmake_minimum_required(VERSION 3.19)
project(Graphs)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(Graphs main.cpp src/graph.cpp src/graph.h)

