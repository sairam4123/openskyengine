//
// Created by kanna on 31-08-2022.
//

#include "display_server_windows.h"

const wchar_t *DisplayServerWindows::CLASS_NAME = L"OpenSkyEngine (inspired from Godot Game Engine)";

Window *DisplayServerWindows::create_window(String *name, Vector2 *position, Vector2 *size) {
    auto win = DisplayServer::create_window(name, position, size);
    auto hwnd = CreateWindowExW(0,
                    CLASS_NAME,
                    static_cast<LPCWSTR>(name->wc_str()),
                    WS_OVERLAPPEDWINDOW,

                    (int)position->x, (int)position->y, (int)size->x, (int)size->y,

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
    auto hwnd = hwnd_id_map[window->id];
    DestroyWindow(hwnd);
    hwnd_id_map[window->id] = nullptr;
    DisplayServer::destroy_window(window);
}

HWND DisplayServerWindows::get_hwnd(int window_id) {
   return hwnd_id_map[window_id];
}