//
// Created by Sairam on 03-12-2021.
//

#ifndef TESTPROJECT_MAIN_LOOP_H
#define TESTPROJECT_MAIN_LOOP_H

#include "_object.h"
#include "vector"

class MainLoop {
public:
    bool is_quitting = false;
    void start();

    void exit();

    void loop(float delta);
    void add_object(Object_* object);
    void remove_object(Object_* object);
    void clear_objects();
private:
    std::vector<Object_*> objects;
    bool _quit = false;
    bool _looping = false;

    void _loop();
    void _ready();
    int _counter = 0;
};


#endif //TESTPROJECT_MAIN_LOOP_H
