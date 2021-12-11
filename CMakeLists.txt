cmake_minimum_required(VERSION 3.17)
project(TestProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestProject main.cpp core/my_string.cpp core/main_loop.cpp core/node.cpp core/node.h user/node_2d.cpp user/node_2d.h)
