//
// Created by Sairam on 03-12-2021.
//

#include <iostream>
#include "main_loop.h"
#include "chrono"
#include "csignal"

typedef std::chrono::nanoseconds TIME;

void MainLoop::start() {
//    signal(SIGINT, _exit_handler);
//    signal(SIGTERM, _exit_handler);
    _looping = true;
    _ready();
//    _loop();
}

void MainLoop::_loop() {
    _looping = true;
    _ready();
    auto get_time = []() {
        return std::chrono::duration_cast<TIME>(
                std::chrono::system_clock::now().time_since_epoch());
    };
    auto time_before = TIME::zero();
    while (!_quit) {
        if (time_before == TIME::zero()){
            auto time_now = get_time();
            time_before = time_now;
            continue;
        }
        auto time_now = get_time();
        auto dur = time_now - time_before;
        auto delta = std::chrono::duration_cast<std::chrono::duration<float>>(dur).count();
        loop(delta);
        time_before = time_now;
    }
    std::cout << "Exiting!" << std::endl;
}

void MainLoop::_ready() {
    for (auto &object: *objects) {
        object->_ready();
    }
}

void MainLoop::exit() {
    if (_quit) {
        return;
    }
    _looping = false;
    _quit = true;
    is_quitting = true;
    clear_objects();
}

void MainLoop::loop(float delta) {
    for (auto &object: *objects) {
        if (_quit) {
            break;
        }
        object->_loop(delta);
    }
}

void MainLoop::add_object(Object *object) {
    objects->push_back(object);
    object->id = _counter;
    _counter++;
    if (_looping) {
        object->_ready();
    }
}

void MainLoop::remove_object(Object *object) {
    auto index = std::find(objects->begin(), objects->end(), object);
    if (index != objects->end()) {
        objects->erase(index);
    }
    object->_exit();
}

void MainLoop::clear_objects() {
    auto unedited_objects = *objects;
    for (auto &object: unedited_objects) {
        remove_object(object);
    }
}

MainLoop::~MainLoop() {
    objects->shrink_to_fit();
    mainLoop = nullptr;
    delete objects;
}

void MainLoop::_exit_handler(int signum) {
    fflush(stdout);
    std::cout << "\n\nStarting application exit process due to " << "keyboard interrupt" << "." << std::endl;
    MainLoop::get_singleton()->exit();
    signal(signum, _exit_handler);
}

MainLoop::MainLoop() {
    mainLoop = this;
    objects = new std::vector<Object *>();
}

MainLoop *MainLoop::mainLoop = nullptr;

MainLoop *MainLoop::get_singleton() {
    return mainLoop;
}

