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

void Node2D::_loop() {
    x += 0.1;
    if (x >= 1000) {
        mainLoop->exit();
    }
}
