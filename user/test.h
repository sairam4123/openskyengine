//
// Created by kanna on 07-02-2022.
//

#ifndef TESTPROJECT_TEST_H
#define TESTPROJECT_TEST_H


#include "../core/node.h"
#include "resource.h"

class Base {
public:
    virtual void do_stuff();

};

class Derived : public Base {
    void do_stuff() override;
};

class Test : public Node {
    void _ready() override;

    void test();

    Resource *resource;

    void _input(InputEvent *event) override;

public:
    explicit Test(const char *_name) : Node(_name) {
        name = new String(_name);
    }

    explicit Test(String *p_name) : Node(p_name) {
        name = p_name;
    }

    void do_stuff(Base base);

    void do_stuff(Base *base);

    void do_stuff(Base &base);
};


#endif //TESTPROJECT_TEST_H
