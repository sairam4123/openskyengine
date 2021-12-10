//
// Created by Sairam on 03-12-2021.
//

#include <iostream>
#include "main_loop.h"

void MainLoop::start() {
    _loop();
}

void MainLoop::_loop() {
    _looping = true;
    _ready();
    while (true) {
        if (_quit) {
            std::cout << "Exiting!" << std::endl;
            break;
        }
        loop();
    }
}

void MainLoop::_ready() {
    for (auto & object : objects) {
        object->_ready();
    }
}

void MainLoop::exit() {
    if (_quit) {
        return;
    }
    _quit = true;
    is_quitting = true;
    clear_objects();
}

void MainLoop::loop() {
    for (auto &object : objects) {
        if (_quit) {
            break;
        }
        object->_loop();
    }
}

void MainLoop::add_object(Object_ *object) {
    objects.push_back(object);
    object->id = _counter;
    _counter++;
    object->mainLoop = this;
    if (_looping) {
        object->_ready();
    }
}

void MainLoop::remove_object(Object_ *object) {
    auto index = std::find(objects.begin(), objects.end(), object);
    if (index != objects.cend()) {
        objects.erase(index);
    }
    object->_exit();
    object->mainLoop = nullptr;
}

void MainLoop::clear_objects() {
    auto unedited_objects = objects;
    for (auto &object : unedited_objects) {
        remove_object(object);
    }
}