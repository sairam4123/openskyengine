//
// Created by Sairam on 17-12-2021.
//

#include "windows.h"
#include "plat_win.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    auto windows = Windows();
    return windows.win_main(hInstance, hPrevInstance, pCmdLine, nCmdShow);
}

// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
// {
//     switch (uMsg)
//     {
//     case WM_DESTROY:
//         PostQuitMessage(0);
//         return 0;
//     case WM_PAINT:
//         {
//             PAINTSTRUCT ps;
//             HDC hdc = BeginPaint(hwnd, &ps);
//             // All painting occurs here, between BeginPaint and EndPaint.
//             FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
//             EndPaint(hwnd, &ps);
//         }
//         return 0;
//     }
//     return DefWindowProc(hwnd, uMsg, wParam, lParam);
// }
    // const wchar_t CLASS_NAME[] = L"OpenSkyEngine (inspired from Godot Game Engine)";
    // WNDCLASSW wc = {};
    // wc.lpfnWndProc = (WNDPROC)::WindowProc;
    // wc.hInstance = hInstance;
    // wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
    // wc.lpszClassName = CLASS_NAME;
    // RegisterClassW(&wc);
    // HWND hwnd = CreateWindowExW(
    //     0,                              // Optional window styles.
    //     CLASS_NAME,                     // Window class
    //     L"Learn to Program Windows",    // Window text
    //     WS_OVERLAPPEDWINDOW,            // Window style
    //     // Size and position
    //     CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    //     NULL,       // Parent window    
    //     NULL,       // Menu
    //     hInstance,  // Instance handle
    //     NULL        // Additional application data
    //     );
    // HWND hwnd2 = CreateWindowExW(
    //     0,                              // Optional window styles.
    //     CLASS_NAME,                     // Window class
    //     L"Learn to Program Windows 2",    // Window text
    //     WS_OVERLAPPEDWINDOW,            // Window style
    //     // Size and position
    //     CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
    //     NULL,       // Parent window    
    //     NULL,       // Menu
    //     hInstance,  // Instance handle
    //     NULL        // Additional application data
    //     );
    // if (hwnd == NULL)
    // {
    //     return 0;
    // }
    // ShowWindow(hwnd, nCmdShow);
    // ShowWindow(hwnd2, nCmdShow);
    // 
    // 
    // // Run the message loop.
    //
    // MSG msg = { };
    // while (GetMessage(&msg, NULL, 0, 0) > 0)
    // {
    //     TranslateMessage(&msg);
    //     DispatchMessage(&msg);
    // }
    // return 0;
// }
