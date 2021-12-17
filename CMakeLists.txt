cmake_minimum_required(VERSION 3.17)
project(TestProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestProject main.cpp core/gstring.cpp core/main_loop.cpp core/node.cpp user/node_2d.cpp core/reference.h user/resource.cpp)
