//
// Created by Sairam on 22-01-2022.
//

#ifndef TESTPROJECT_WINDOW_H
#define TESTPROJECT_WINDOW_H

#include "gstring.h"
#include "math/vector_2.h"

class Window {
public:
    int id = 0;
    String* name = new String("");
    Vector2* position = Vector2::ZERO();
    Vector2* size = new Vector2(100, 100);

    void redraw();
    void close();
};


#endif //TESTPROJECT_WINDOW_H
