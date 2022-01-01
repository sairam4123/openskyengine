//
// Created by Sairam on 10-12-2021.
//

#include "node_2d.h"
#include "iostream"

void Node2D::_ready() {
    std::cout << name->c_str() << " is ready." << std::endl;
}

void Node2D::_exit() {
    std::cout << "exiting!" << std::endl;
}

void Node2D::_loop(const float delta) {
    x += 1*delta;
//    if (fmod(x, 1.0) == 0.0) {
//        std::cout << x << std::endl;
//    }
    std::cout << x << std::endl;
    if (x >= 100) {
        MainLoop::get_singleton()->exit();
    }
}
