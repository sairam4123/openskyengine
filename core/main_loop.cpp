//
// Created by Sairam on 03-12-2021.
//

#include <iostream>
#include "main_loop.h"
#include "chrono"

void MainLoop::start() {
    _loop();
}

void MainLoop::_loop() {
    _looping = true;
    _ready();
    auto time_before = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    while (true) {
        if (_quit) {
            std::cout << "Exiting!" << std::endl;
            break;
        }
        auto time_now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        loop(float(time_now.count() - time_before.count()));
        time_before = time_now;
    }
}

void MainLoop::_ready() {
    for (auto &object : objects) {
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

void MainLoop::loop(float delta) {
    for (auto &object : objects) {
        if (_quit) {
            break;
        }
        std::cout << delta << std::endl;
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