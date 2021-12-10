//
// Created by Sairam on 03-12-2021.
//

#ifndef TESTPROJECT_OBJECT_H
#define TESTPROJECT_OBJECT_H

class MainLoop;

class Object_ {
public:
    MainLoop *mainLoop{};

    virtual void _loop();

    virtual void _ready();

    virtual void _exit();

    int id = 0;

    bool operator==(const Object_ *object1) const {
        return object1->id == id;
    }
};


#endif //TESTPROJECT_OBJECT_H
