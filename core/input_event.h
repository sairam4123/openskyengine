//
// Created by kanna on 10-03-2022.
//

#ifndef TESTPROJECT_INPUT_EVENT_H
#define TESTPROJECT_INPUT_EVENT_H


#include "math/vector_2.h"
#include "gstring.h"

class InputEvent {
public:
    virtual String get_name() = 0;
};

enum ButtonCode {
    L_BUTTON = 0,
    M_BUTTON = 1,
    R_BUTTON = 2
};

class  InputEventMouse: public InputEvent {
public:
    String get_name() override {
        return String("InputEventMouse");
    }
};
class InputEventMouseMotion : public InputEventMouse {
public:
    Vector2 *position;
    Vector2 *relative;
    String get_name() override {
        return String("InputEventMouseMotion");
    }
    InputEventMouseMotion(Vector2 *p_position, Vector2 *p_relative) : InputEventMouse() {
        position = p_position;
        relative = p_relative;
    }
};


class InputEventMouseButton : public InputEventMouse {
public:
    Vector2 *position;
    ButtonCode button_index;
    bool pressed = true;

    String get_name() override {
        return String("InputEventMouseButton");
    }

    InputEventMouseButton(Vector2 *p_position, ButtonCode p_button_index, bool p_pressed) : InputEventMouse() {
        position = p_position;
        button_index = p_button_index;
        pressed = p_pressed;
    }
};

#endif //TESTPROJECT_INPUT_EVENT_H
