cmake_minimum_required(VERSION 3.16)
project(TSP)

set(CMAKE_CXX_STANDARD 14)

add_executable(DFS dfs.cpp)
add_executable(ants ants.cpp)
add_executable(make produce.cpp)