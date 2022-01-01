//
// Created by Sairam on 17-12-2021.
//

#include "windows.h"
#include "csignal"
#include <iostream>
#include "../../core/main_loop.h"
#include "../../user/node_2d.h"
#include "chrono"

typedef std::chrono::microseconds TIME;
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

MainLoop* mainLoop;

void exit_terminator(int signum) {
    PostQuitMessage(0);
}
// Taken from https://stackoverflow.com/a/57241985/11697614
void CreateConsole()
{
    if (!AllocConsole()) {
        // Add some error handling here.
        // You can call GetLastError() to get more info about the error.
        return;
    }

    // std::cout, std::clog, std::cerr, std::cin
    FILE* fDummy;
    freopen_s(&fDummy, "CONOUT$", "w", stdout);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONIN$", "r", stdin);
    std::cout.clear();
    std::clog.clear();
    std::cerr.clear();
    std::cin.clear();

    // std::wcout, std::wclog, std::wcerr, std::wcin
    HANDLE hConOut = CreateFile("CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE hConIn = CreateFile("CONIN$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    SetStdHandle(STD_OUTPUT_HANDLE, hConOut);
    SetStdHandle(STD_ERROR_HANDLE, hConOut);
    SetStdHandle(STD_INPUT_HANDLE, hConIn);
    std::wcout.clear();
    std::wclog.clear();
    std::wcerr.clear();
    std::wcin.clear();
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"OpenSkyEngine (inspired from Godot Game Engine)";
    auto get_time = []() {
        return std::chrono::duration_cast<TIME>(
                std::chrono::system_clock::now().time_since_epoch());
    };
    auto time_before = get_time();

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
            0,
            CLASS_NAME,
            L"OpenSkyEngine",
            WS_OVERLAPPEDWINDOW,

            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,
            NULL,
            hInstance,
            NULL
    );
    mainLoop = new MainLoop();

    if (hwnd == 0) {
        return 0;
    }
    signal(SIGINT, exit_terminator);
    auto node1 = Node2D("Test");
    ShowWindow(hwnd, nCmdShow);
    CreateConsole();
    MainLoop::get_singleton()->add_object(&node1);
    MainLoop::get_singleton()->start();

    while (true) {
        MSG msg = {};
        auto time_now = get_time();
        auto dur = time_now - time_before;
        auto delta = std::chrono::duration_cast<std::chrono::duration<float>>(dur).count();
        auto retValue = PeekMessageW(&msg, hwnd, 0, 0, PM_REMOVE);
        if (retValue){
            TranslateMessage(&msg);
        }
        MainLoop::get_singleton()->loop(delta);
        if (MainLoop::get_singleton()->is_quitting) {
            std::cout << "Trying to exit!" << std::endl;
            PostQuitMessage(0);
            break;
        }
        if (retValue) {
            DispatchMessageW(&msg);
        }
        time_before = time_now;
    }

    FreeConsole();
    delete mainLoop;
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            MainLoop::get_singleton()->exit();
            PostQuitMessage(0);
            break;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);


            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps);
        }
            break;
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

