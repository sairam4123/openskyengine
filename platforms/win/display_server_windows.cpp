//
// Created by kanna on 31-08-2022.
//

#include "display_server_windows.h"
#include "windowsx.h"
#include "../../core/main_loop.h"
#include "../../core/math/vector_2.h"


const wchar_t *DisplayServerWindows::CLASS_NAME = L"OpenSkyEngine";

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
    UpdateWindow(hwnd);
    hwnd_id_map[win->id] = hwnd;
    return win;
}

DisplayServerWindows::DisplayServerWindows(HINSTANCE p_hInstance) {
    hInstance = p_hInstance;
    // _setup_class(hInstance, (WNDPROC)WND_PROC);
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

void DisplayServerWindows::alert(String* msg) {
    MessageBoxW(NULL, msg->wc_str(), L"ALERT!!!", MB_OK | MB_ICONEXCLAMATION);
}
LRESULT DisplayServerWindows::wnd_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        
        switch (uMsg) {
        case WM_CREATE: {
            for (auto &win : windows) {
                if (get_hwnd(win->id) == hwnd) {
                    std::wcout << "Window " << win->name << " created successfully!" << std::endl;
                }
            }
            break;
        }
        case WM_DESTROY: {
            auto main_hwnd = get_hwnd(main_window->id);
            if (hwnd != main_hwnd) {
                break;
            }
            MainLoop::get_singleton()->exit();
            PostQuitMessage(0);
            break;
        }
        case WM_KEYUP: {
            switch (wParam) {
                case VK_SHIFT: {
                    shift = false;
                    break;
                }
                case VK_MENU: {
                    alt = false;
                    // alt gr
                    ctrl = false;
                    break;
                }
                case VK_CONTROL: {
                    ctrl = false;
                    break;
                }
                case VK_LWIN: {
                    meta = false;
                    break;
                }
                case VK_RWIN: {
                    meta = false;
                    break;
                }

            }
            auto event = InputEventKey((wchar_t)wParam, false, false);
            event.alt = alt;
            event.ctrl = ctrl;
            event.shift = shift;
            event.meta = meta;
            // auto idx = std::find(pressed_keys.begin(), pressed_keys.end(), (wchar_t)&wParam);
            // if (idx != pressed_keys.end()) {
            //     pressed_keys.erase(idx);
            // }
            pressed_keys.erase((wchar_t)wParam);
            MainLoop::get_singleton()->propagate_input(&event);
            // std::cout << "The entered character is: " << (char)wParam << std::endl;
            break;
        }
        case WM_SYSKEYDOWN: {
            switch (wParam) {
                case VK_MENU: {
                    alt = true;
                }
            }
        }
        case WM_SYSKEYUP: {
            switch (wParam) {
                case VK_MENU: {
                    alt = false;
                }
            }
        }
        case WM_KEYDOWN: {
            switch ((wchar_t)wParam) {
                case ' ':
                    auto con_hwnd = GetConsoleWindow();
                    auto visible = IsWindowVisible(con_hwnd);
                    ShowWindow(con_hwnd, visible ? SW_HIDE : SW_SHOW);
                    break;
            }
            switch (wParam) {
                case VK_SHIFT: {
                    shift = true;
                    break;
                }
                case VK_MENU: {
                    alt = true;
                    break;
                }
                case VK_CONTROL: {
                    ctrl = true;
                    break;
                }
                case VK_LWIN: {
                    meta = true;
                    break;
                }
                case VK_RWIN: {
                    meta = true;
                    break;
                }

            }
            bool echo = (bool)pressed_keys.count((wchar_t)wParam);
            auto event = InputEventKey((wchar_t)wParam, true, echo);
            event.alt = alt;
            event.ctrl = ctrl;
            event.shift = shift;
            event.meta = meta;
            pressed_keys.insert((wchar_t)wParam);
            MainLoop::get_singleton()->propagate_input(&event);
            // std::cout << "The entered character is: " << (char)wParam << std::endl;
            break;
        }
        case WM_MOUSEMOVE: {
            auto x_pos = (int)GET_X_LPARAM(lParam);
            auto y_pos = (int)GET_Y_LPARAM(lParam);
            auto pos = Vector2(x_pos, y_pos);
            auto event = InputEventMouseMotion(&pos, Vector2::ZERO());
            MainLoop::get_singleton()->propagate_input(&event);
            break;
        }
        
        case WM_MBUTTONUP: {
            auto x_pos = (int) GET_X_LPARAM(lParam);
            auto y_pos = (int) GET_Y_LPARAM(lParam);
            auto pos = Vector2(x_pos, y_pos);
            auto event = InputEventMouseButton(&pos, ButtonCode::M_BUTTON, false);
            MainLoop::get_singleton()->propagate_input(&event);
            break;
        }
        case WM_MBUTTONDOWN: {
            auto x_pos = (int) GET_X_LPARAM(lParam);
            auto y_pos = (int) GET_Y_LPARAM(lParam);
            auto pos = Vector2(x_pos, y_pos);
            auto event = InputEventMouseButton(&pos, ButtonCode::M_BUTTON, true);
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
            RECT rc;
            GetWindowRect(hwnd, &rc);
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 2)); // 2 is godot color!

            // DrawTextW(hdc, L"Test", 5, &rc, DT_CALCRECT);
            DrawTextW(hdc, L"Test", 5, &rc, DT_CENTER | DT_VCENTER);
            // FillRect(hdc, &rc, (HBRUSH) (COLOR_WINDOW + 2)); // 2 is godot color!

            EndPaint(hwnd, &ps);
        }
            break;
        case WM_SETCURSOR: {
            auto cursor = LoadCursorW(nullptr, (LPCWSTR)IDC_ARROW);
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

void DisplayServerWindows::set_window_visiblity(int id, bool visible) {
    auto hwnd = get_hwnd(id);
    ShowWindow(hwnd, visible ? SW_SHOW : SW_HIDE);
}

int64_t DisplayServerWindows::get_native_handle(int id) {
    return (int64_t)get_hwnd(id);
}