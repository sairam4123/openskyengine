//
// Created by Sairam on 17-12-2021.
//

#include "windows.h"
#include "plat_win.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    auto windows = Windows();
    return windows.win_main(hInstance, hPrevInstance, pCmdLine, nCmdShow);
}

