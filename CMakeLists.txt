cmake_minimum_required(VERSION 3.17)
project(TestProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WIN32_EXECUTABLE 1)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:wWinMain")
add_executable(TestProject platforms/win/main.cpp core/gstring.cpp core/main_loop.cpp core/node.cpp user/node_2d.cpp core/reference.h user/resource.cpp platforms/win/plat_win.cpp core/window.cpp core/window.h main.cpp main.h user/test.cpp user/test.h core/input_event.cpp core/input_event.h core/math/vector_2.cpp core/math/vector_2.h core/display/display_server.cpp core/display/display_server.h platforms/win/display_server_windows.cpp platforms/win/display_server_windows.h)
