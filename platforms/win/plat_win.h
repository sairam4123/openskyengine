//
// Created by kanna on 17-12-2021.
//

#ifndef TESTPROJECT_PLAT_WIN_H
#define TESTPROJECT_PLAT_WIN_H

#include "windows.h"
#include "windowsx.h"
#include "../../core/main_loop.h"

class Windows {

    static Windows* _singleton;
    static MainLoop mainLoop;

public:
    static Windows* get_singleton();

    HWND main_hwnd;
    Windows();
    ~Windows();

    LRESULT wnd_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    static void exit_terminator(int signum);

    static void CreateConsole();

    void _loop(HINSTANCE hInstance, HWND hwnd);

    int WINAPI win_main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);

    inline static bool IsConsoleWindowActive();
    static void ToggleConsoleWindow();

};


#endif //TESTPROJECT_PLAT_WIN_H
