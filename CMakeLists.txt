cmake_minimum_required(VERSION 3.17)
project(TestProject)

set(CMAKE_CXX_STANDARD 14)


add_executable(TestProject main.cpp my_string.cpp main_loop.cpp object.cpp object.h test_object.cpp test_object.h)