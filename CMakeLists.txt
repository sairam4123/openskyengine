cmake_minimum_required(VERSION 3.17)
project(TestProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WIN32_EXECUTABLE 1)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:wWinMain")
add_executable(TestProject platforms/win/main.cpp core/gstring.cpp core/main_loop.cpp core/node.cpp user/node_2d.cpp core/reference.h user/resource.cpp)
