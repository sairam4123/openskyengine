//
// Created by kanna on 31-08-2022.
//

#ifndef TESTPROJECT_DISPLAY_SERVER_WINDOWS_H
#define TESTPROJECT_DISPLAY_SERVER_WINDOWS_H


#include "../../core/display/display_server.h"
#include "windows.h"
#include <map>

class DisplayServerWindows : public DisplayServer{
private:
    HINSTANCE hInstance;

    Window * create_window(String *name, Vector2 *position, Vector2 *size) override;
    void destroy_window(Window *window) override;

public:
    std::map<int, HWND> hwnd_id_map;
    explicit DisplayServerWindows(HINSTANCE p_hInstance);

    HWND get_hwnd(int window_id);
    static const wchar_t* CLASS_NAME;
};


#endif //TESTPROJECT_DISPLAY_SERVER_WINDOWS_H
