//
// Created by kanna on 31-08-2022.
//

#ifndef TESTPROJECT_DISPLAY_SERVER_H
#define TESTPROJECT_DISPLAY_SERVER_H


#include <vector>
#include "../window.h"
#include "../gstring.h"
#include "functional"

class DisplayServer {
public:
    static DisplayServer *displayServer;
    int _counter = 0;

public:
    static DisplayServer *get_singleton() {
        return displayServer;
    }

    std::vector<Window *> windows;

    virtual Window *create_window(String *name, Vector2i *position, Vector2i *size);

    virtual void destroy_window(int id);

    virtual void destroy_window(Window *window);

    virtual void set_window_visiblity(int id, bool visible) = 0;

    virtual int64_t get_native_handle(int id) = 0;
    
    virtual void alert(String* msg) = 0;

    Window * main_window;

//public:
//    std::vector<std::function<DisplayServer*(void )>> create_functions;
};


#endif //TESTPROJECT_DISPLAY_SERVER_H
