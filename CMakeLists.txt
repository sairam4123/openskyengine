cmake_minimum_required(VERSION 3.17)
project(TestProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestProject main.cpp test_object.cpp core/object.cpp core/my_string.cpp core/main_loop.cpp)
