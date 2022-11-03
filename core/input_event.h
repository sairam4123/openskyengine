//
// Created by kanna on 10-03-2022.
//

#ifndef TESTPROJECT_INPUT_EVENT_H
#define TESTPROJECT_INPUT_EVENT_H


#include "math/vector_2.h"
#include "gstring.h"

enum Key {
    KEY_A = 0,
    KEY_B = 1,
    KEY_C = 2,
    KEY_D = 3,
    KEY_E = 4,
    KEY_F = 5,
    KEY_G = 6,
    KEY_H = 7,
    KEY_I = 8,
    KEY_J = 9,
    KEY_K = 10,
    KEY_L = 11,
    KEY_M = 12,
    KEY_N = 13,
    KEY_O = 14,
    KEY_P = 15,
    KEY_Q = 16,
    KEY_R = 17,
    KEY_S = 18,
    KEY_T = 19,
    KEY_U = 20,
    KEY_V = 21,
    KEY_W = 22,
    KEY_X = 23,
    KEY_Y = 24,
    KEY_Z = 25,

    // nums
    KEY_1 = 26,
    KEY_2 = 27,
    KEY_3 = 28,
    KEY_4 = 29,
    KEY_5 = 30,
    KEY_6 = 31,
    KEY_7 = 32,
    KEY_8 = 33,
    KEY_9 = 34,
    KEY_0 = 35,

    // keypad
    KEY_KP_1 = 36,
    KEY_KP_2 = 37,
    KEY_KP_3 = 38,
    KEY_KP_4 = 39,
    KEY_KP_5 = 40,
    KEY_KP_6 = 41,
    KEY_KP_7 = 42,
    KEY_KP_8 = 43,
    KEY_KP_9 = 44,
    KEY_KP_0 = 45,
    KEY_KP_PERIOD = 46,
    KEY_KP_ENTER = 47,
    KEY_KP_SLASH = 48,
    KEY_KP_ASTRISK = 49,
    KEY_KP_MINUS = 50,
    KEY_KP_PLUS = 51

    // KEY_ACCENT = 52,
    // KEY_ = 53
};

class InputEvent {
public:
    virtual String get_name() = 0;
};

class InputEventWithModifiers: public InputEvent {
public:
    bool ctrl = false;
    bool shift = false;
    bool alt = false;
    bool meta = false;
    
    String get_name() override {
        return String("InputEventKey");
    }

};

class InputEventKey: public InputEventWithModifiers {
public:
    
    wchar_t unicode;
    bool pressed = false;
    bool echo = false;

    String get_name() override {
        return String("InputEventKey");
    }

    InputEventKey(wchar_t p_unicode, bool p_pressed, bool p_echo) {
        unicode = p_unicode;
        pressed = p_pressed;
        echo = p_echo;
    };
};

enum ButtonCode {
    L_BUTTON = 0,
    M_BUTTON = 1,
    R_BUTTON = 2
};

class  InputEventMouse: public InputEventWithModifiers {
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
