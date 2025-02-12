cmake_minimum_required(VERSION 3.10)

project(mygrep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(mygrep main.cpp search.cpp)