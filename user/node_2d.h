//
// Created by Sairam on 10-12-2021.
//

#ifndef TESTPROJECT_NODE_2D_H
#define TESTPROJECT_NODE_2D_H


#include "../core/node.h"

class Node2D : public Node {
public:
    float x = 0;
    float y = 0;

    float rotation = 0;

    void _loop(float delta) override;

    void _exit() override;

    void _ready() override;

    void _input(InputEvent* event) override;

    explicit Node2D(const char *_name) : Node(_name) {
        name = new String(_name);
    }

    explicit Node2D(String *p_name) : Node(p_name) {
        name = p_name;
    }
private:
    bool insanity_check_successful = false;
    bool alerted = false;
    int insanity_checks = 0;
    int max_windows = 5;
    int current_window_count = 1;
};


#endif //TESTPROJECT_NODE_2D_H
