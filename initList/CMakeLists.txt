cmake_minimum_required(VERSION 3.20)
project(cppstd2)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppstd2 main.cpp Test.cpp Test.h Test2.cpp Test2.h)
