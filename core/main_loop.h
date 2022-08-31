//
// Created by Sairam on 03-12-2021.
//

#ifndef TESTPROJECT_MAIN_LOOP_H
#define TESTPROJECT_MAIN_LOOP_H

#include "object.h"
#include "vector"
#include "input_event.h"

class MainLoop {
public:
    bool is_quitting = false;

    void start();

    void exit();

    void loop(float delta);

    void add_object(Object *object);

    void remove_object(Object *object);

    void clear_objects();

    static MainLoop *get_singleton();

    std::vector<Object *> *get_objects();

    MainLoop();

    ~MainLoop();

    void propagate_input(InputEvent *event);

private:
    std::vector<Object *> *objects;
    bool _quit = false;
    bool _looping = false;

    static MainLoop *mainLoop;

    static void _exit_handler(int signum);

    void _loop();

    void _ready();

    int _counter = 0;
};

#endif //TESTPROJECT_MAIN_LOOP_H
