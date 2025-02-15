cmake_minimum_required(VERSION 3.10)

project(mygrep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(WIN32)
    find_package(boost_nowide CONFIG REQUIRED)
endif()

add_executable(mygrep main.cpp search.cpp)

if(WIN32)
    target_link_libraries(mygrep PRIVATE Boost::nowide)
endif()
