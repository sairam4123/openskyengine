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
    auto get_time = [](){
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch());
    };
    auto time_before = get_time();
    while (true) {
        if (_quit) {
            std::cout << "Exiting!" << std::endl;
            break;
        }
        auto time_now = get_time();
        auto dur = time_now - time_before;
        auto delta = std::chrono::duration_cast<std::chrono::duration<float>>(dur).count();
        loop(delta);
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
        object->_loop(delta);
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

MainLoop::~MainLoop() {
    objects.shrink_to_fit();
}
