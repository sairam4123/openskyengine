//
// Created by kanna on 17-12-2021.
//

#include "plat_win.h"
#include "windowsx.h"
#include "../../core/main_loop.h"
#include "../../user/node_2d.h"
#include "chrono"
#include "csignal"
#include "iostream"
#include "../../main.h"
#include "../../core/math/vector_2.h"
#include "display_server_windows.h"

typedef std::chrono::microseconds TIME;

void Windows::exit_terminator(int signum) {
    PostQuitMessage(0);
    signal(signum, Windows::exit_terminator);
}
// Taken from https://stackoverflow.com/a/57241985/11697614
void Windows::CreateConsole()
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
    HANDLE hConOut = CreateFile("CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
                                nullptr);
    HANDLE hConIn = CreateFile("CONIN$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
                               nullptr);
    SetStdHandle(STD_OUTPUT_HANDLE, hConOut);
    SetStdHandle(STD_ERROR_HANDLE, hConOut);
    SetStdHandle(STD_INPUT_HANDLE, hConIn);
    std::wcout.clear();
    std::wclog.clear();
    std::wcerr.clear();
    std::wcin.clear();
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    return Windows::get_singleton()->wnd_proc(hwnd, uMsg, wParam, lParam);
}


int Windows::win_main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"OpenSkyEngine (inspired from Godot Game Engine)";
    
    auto ds = DisplayServerWindows(hInstance);
    DisplayServer::displayServer = &ds;

    WNDCLASSW wc = {};
    wc.lpfnWndProc = (WNDPROC)::WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
    wc.lpszClassName = DisplayServerWindows::CLASS_NAME;

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
            0,
            DisplayServerWindows::CLASS_NAME,
            L"OpenSkyEngine - TestWindow",
            WS_OVERLAPPEDWINDOW,

            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            nullptr,
            nullptr,
            hInstance,
            nullptr
    );

    if (hwnd == nullptr) {
        return 0;
    }
    main_hwnd = hwnd;
    signal(SIGINT, exit_terminator);
    ShowWindow(hwnd, nCmdShow);
    CreateConsole();
    HWND console_hwnd = GetConsoleWindow();
    ShowWindow(console_hwnd, SW_HIDE);
    auto main = Main();
    main.init();
    MainLoop::get_singleton()->start();

    _loop(hInstance, hwnd);
    FreeConsole();
    return 0;
}

void Windows::_loop(HINSTANCE hInstance, HWND hwnd) {
    auto get_time = []() {
        return std::chrono::duration_cast<TIME>(
                std::chrono::system_clock::now().time_since_epoch());
    };
    auto time_before = get_time();

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
}

LRESULT Windows::wnd_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            if (hwnd != main_hwnd) {
                break;
            }
            MainLoop::get_singleton()->exit();
            PostQuitMessage(0);
            break;
        case WM_KEYDOWN:
//            std::cout << ((char)wParam == 'H') << std::endl;
            switch ((wchar_t)wParam) {
                case ' ':
                    ToggleConsoleWindow();
            }
            std::cout << "The entered character is: " << (char)wParam << std::endl;
            break;
        case WM_MOUSEMOVE: {
            auto x_pos = (int)GET_X_LPARAM(lParam);
            auto y_pos = (int)GET_Y_LPARAM(lParam);
            auto pos = Vector2(x_pos, y_pos);
            auto event = InputEventMouseMotion(&pos, Vector2::ZERO());
            MainLoop::get_singleton()->propagate_input(&event);
            break;
        }
        case WM_LBUTTONUP: {
            auto x_pos = (int) GET_X_LPARAM(lParam);
            auto y_pos = (int) GET_Y_LPARAM(lParam);
            auto pos = Vector2(x_pos, y_pos);
            auto event = InputEventMouseButton(&pos, ButtonCode::L_BUTTON, false);
            MainLoop::get_singleton()->propagate_input(&event);
            break;
        }
        case WM_LBUTTONDOWN: {
            auto x_pos = (int) GET_X_LPARAM(lParam);
            auto y_pos = (int) GET_Y_LPARAM(lParam);
            auto pos = Vector2(x_pos, y_pos);
            auto event = InputEventMouseButton(&pos, ButtonCode::L_BUTTON, true);
            MainLoop::get_singleton()->propagate_input(&event);
            break;
        }
        case WM_RBUTTONUP: {
            auto x_pos = (int) GET_X_LPARAM(lParam);
            auto y_pos = (int) GET_Y_LPARAM(lParam);
            auto pos = Vector2(x_pos, y_pos);
            auto event = InputEventMouseButton(&pos, ButtonCode::R_BUTTON, false);
            MainLoop::get_singleton()->propagate_input(&event);
            break;
        }
        case WM_RBUTTONDOWN: {
            auto x_pos = (int) GET_X_LPARAM(lParam);
            auto y_pos = (int) GET_Y_LPARAM(lParam);
            auto pos = Vector2(x_pos, y_pos);
            auto event = InputEventMouseButton(&pos, ButtonCode::R_BUTTON, true);
            MainLoop::get_singleton()->propagate_input(&event);
            break;
        }

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 2)); // 2 is godot color!

            EndPaint(hwnd, &ps);
        }
            break;
        case WM_SETCURSOR: {
            auto cursor = LoadCursorW(nullptr,(LPCWSTR)IDC_ARROW);
            SetCursor(cursor);
        }
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

inline bool Windows::IsConsoleWindowActive() {
    return IsWindowVisible(GetConsoleWindow());
}

void Windows::ToggleConsoleWindow() {
    HWND con_hwnd = GetConsoleWindow();
    int nCmdShow = IsConsoleWindowActive() ? SW_HIDE : SW_SHOW;
    ShowWindow(con_hwnd, nCmdShow);
}

Windows *Windows::_singleton = nullptr;

Windows *Windows::get_singleton() {
    return _singleton;
}

Windows::Windows() {
    _singleton = this;
}

Windows::~Windows() {
    _singleton = nullptr;
}

