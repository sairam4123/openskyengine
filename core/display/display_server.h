//
// Created by kanna on 31-08-2022.
//

#ifndef TESTPROJECT_DISPLAY_SERVER_H
#define TESTPROJECT_DISPLAY_SERVER_H


#include <vector>
#include "../window.h"
#include "../gstring.h"
#include "../math/vector_2.h"
#include "functional"

class DisplayServer {
public:
    static DisplayServer *displayServer;

public:
    static DisplayServer *get_singleton() {
        return displayServer;
    }

    std::vector<Window *> windows;

    virtual Window *create_window(String *name, Vector2 *position, Vector2 *size);

    virtual void destroy_window(int id);

    virtual void destroy_window(Window *window);

//public:
//    std::vector<std::function<DisplayServer*(void )>> create_functions;
};


#endif //TESTPROJECT_DISPLAY_SERVER_H
