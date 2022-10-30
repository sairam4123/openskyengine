//
// Created by kanna on 31-08-2022.
//

#include "display_server_windows.h"
#include "windowsx.h"
#include "../../core/main_loop.h"
#include "../../core/math/vector_2.h"


const wchar_t *DisplayServerWindows::CLASS_NAME = L"OpenSkyEngine (inspired from Godot Game Engine)";

Window *DisplayServerWindows::create_window(String *name, Vector2i *position, Vector2i *size) {
    auto win = DisplayServer::create_window(name, position, size);
    auto hwnd = CreateWindowExW(0,
                    CLASS_NAME,
                    static_cast<LPCWSTR>(name->wc_str()),
                    WS_OVERLAPPEDWINDOW,

                    (int64_t)position->x, (int64_t)position->y, (int64_t)size->x, (int64_t)size->y,

                    nullptr,
                    nullptr,
                    hInstance,
                    nullptr);
    ShowWindow(hwnd, SW_SHOW);
    hwnd_id_map[win->id] = hwnd;
    return win;
}

DisplayServerWindows::DisplayServerWindows(HINSTANCE p_hInstance) {
    hInstance = p_hInstance;
}

void DisplayServerWindows::destroy_window(Window *window) {
    if (window->id == main_window->id) {
        return;
    }
    auto hwnd = hwnd_id_map[window->id];
    DestroyWindow(hwnd);
    hwnd_id_map[window->id] = nullptr;
    DisplayServer::destroy_window(window);
}

HWND DisplayServerWindows::get_hwnd(int window_id) {
   return hwnd_id_map[window_id];
}

LRESULT DisplayServerWindows::wnd_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        auto main_hwnd = get_hwnd(main_window->id);
        switch (uMsg) {
        case WM_DESTROY:
            if (hwnd != main_hwnd) {
                break;
            }
            MainLoop::get_singleton()->exit();
            PostQuitMessage(0);
            break;
        case WM_KEYDOWN:
            switch ((wchar_t)wParam) {
                case ' ':
                    auto con_hwnd = GetConsoleWindow();
                    auto visible = IsWindowVisible(con_hwnd);
                    ShowWindow(con_hwnd, visible ? SW_HIDE : SW_SHOW);
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

HWND DisplayServerWindows::get_main_hwnd() {
    return get_hwnd(main_window->id);
}

LRESULT WND_PROC(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    auto ds = static_cast<DisplayServerWindows *>(DisplayServer::get_singleton());
    return ds->wnd_proc(hwnd, uMsg, wParam, lParam);
}

DisplayServerWindows::DisplayServerWindows() {
    _setup_class(hInstance, (WNDPROC)WND_PROC);
}

void DisplayServerWindows::set_window_visiblity(int id, bool visible) {
    auto hwnd = get_hwnd(id);
    ShowWindow(hwnd, visible ? SW_SHOW : SW_HIDE);
}

void DisplayServerWindows::_setup_class(HINSTANCE hInstance, WNDPROC wndproc) {
    WNDCLASSW wc = {};
    wc.lpfnWndProc = wndproc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
    wc.lpszClassName = DisplayServerWindows::CLASS_NAME;

    RegisterClassW(&wc);
}

int64_t DisplayServerWindows::get_native_handle(int id) {
    return (int64_t)get_hwnd(id);
}