//
// Created by kanna on 31-08-2022.
//

#ifndef TESTPROJECT_DISPLAY_SERVER_WINDOWS_H
#define TESTPROJECT_DISPLAY_SERVER_WINDOWS_H


#include "../../core/display/display_server.h"
#include "windows.h"
#include <map>
#include <set>


class DisplayServerWindows : public DisplayServer{
private:
    HINSTANCE hInstance;

    bool alt = false;
    bool ctrl = false;
    bool shift = false;
    bool meta = false;

    std::set<wchar_t> pressed_keys;
    std::map<int, HWND> hwnd_id_map;
    
    Window * create_window(String *name, Vector2i *position, Vector2i *size) override;
    void destroy_window(Window *window) override;
    
    void set_window_visiblity(int id, bool visible) override;
    int64_t get_native_handle(int id) override;

    HWND get_main_hwnd();

public:
    explicit DisplayServerWindows(HINSTANCE p_hInstance);
    LRESULT wnd_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    HWND get_hwnd(int window_id);
    
    static const wchar_t* CLASS_NAME;

};


#endif //TESTPROJECT_DISPLAY_SERVER_WINDOWS_H
