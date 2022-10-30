//
// Created by Sairam on 22-01-2022.
//

#ifndef TESTPROJECT_WINDOW_H
#define TESTPROJECT_WINDOW_H

#include "gstring.h"
#include "math/vector_2i.h"

class Window {
public:
    int id = 0;

    String* name = new String("");
    Vector2i* position = Vector2i::ZERO();
    Vector2i* size = new Vector2i(100, 100);
    bool visible = false;

    void redraw();
    void close();

    void toggle_visiblity();
    void show();
    void hide();
    void get_native_handle();
};


#endif //TESTPROJECT_WINDOW_H
