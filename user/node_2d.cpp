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

void Node2D::_loop(float delta) {
    x += 1*delta;
    std::cout << x << "\n";
    if (x >= 10) {
        mainLoop->exit();
    }
}
