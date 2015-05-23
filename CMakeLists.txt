cmake_minimum_required(VERSION 3.2)
project(Enum_Iterator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES example.cpp)
add_executable(Enum_Iterator ${SOURCE_FILES} enumit.hpp)