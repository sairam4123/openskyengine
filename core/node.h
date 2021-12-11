//
// Created by Sairam on 10-12-2021.
//

#ifndef TESTPROJECT_NODE_H
#define TESTPROJECT_NODE_H

#include "object.h"
#include "my_string.h"
#include "vector"

class Node : public Object_ {
public:
    MyString *name;

    Node *parent = nullptr;
    std::vector<Node *> children;

    void add_child(Node *child);

    void remove_child(Node *child);

    void remove_child(int index);

    void move_child(Node *child, int index);

    void add_child(Node *child, int index);

    void set_name(MyString *p_name);

    void set_name(const char *p_name);

    void _ready() override = 0;

    void _loop() override = 0;

    void _exit() override = 0;

    explicit Node(const char *_name) {
        name = new MyString(_name);
    }

    explicit Node(MyString *p_name) {
        name = p_name;
    }
};


#endif //TESTPROJECT_NODE_H
