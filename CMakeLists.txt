cmake_minimum_required(VERSION 3.23)
project(COP3530PageRank)

set(CMAKE_CXX_STANDARD 14)

add_executable(COP3530PageRank main.cpp AdjacencyList.h catch.hpp test.cpp)
