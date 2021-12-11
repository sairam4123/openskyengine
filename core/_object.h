//
// Created by Sairam on 03-12-2021.
//

#ifndef TESTPROJECT__OBJECT_H
#define TESTPROJECT__OBJECT_H

#include "my_string.h"

class MainLoop;

class Object_ {
public:
    MainLoop *mainLoop{};

    virtual void _loop() = 0;

    virtual void _ready() = 0;

    virtual void _exit() = 0;

    int id = 0;

    bool operator==(const Object_ *object1) const {
        return object1->id == id;
    }
};


#endif //TESTPROJECT__OBJECT_H
