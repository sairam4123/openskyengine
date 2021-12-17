//
// Created by Sairam on 10-12-2021.
//

#ifndef TESTPROJECT_NODE_H
#define TESTPROJECT_NODE_H

#include "object.h"
#include "gstring.h"
#include "vector"
#include "main_loop.h"

class Node : public Object {
public:
    String *name;

    Node *parent = nullptr;
    std::vector<Node *> children;

    void add_child(Node *child);

    void remove_child(Node *child);

    void remove_child(int index);

    void move_child(Node *child, int index);

    void add_child(Node *child, int index);

    void set_name(String *p_name);

    void set_name(const char *p_name);

    explicit Node(const char *_name) {
        name = new String(_name);
    }

    explicit Node(String *p_name) {
        name = p_name;
    }

    ~Node();
};


#endif //TESTPROJECT_NODE_H
