//
// Created by kanna on 17-12-2021.
//

#include "plat_win.h"

int Windows::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"OpenSkyEngine (inspired from Godot Game Engine)";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;


    return 0;
}

LRESULT Windows::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    return 0;
}
