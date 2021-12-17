//
// Created by kanna on 17-12-2021.
//

#ifndef TESTPROJECT_PLAT_WIN_H
#define TESTPROJECT_PLAT_WIN_H

#include "windows.h"

class Windows {
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);

    LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};


#endif //TESTPROJECT_PLAT_WIN_H
