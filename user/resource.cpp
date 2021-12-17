//
// Created by Sairam on 17-12-2021.
//

#include "resource.h"
#include "iostream"

void Resource::_loop(const float delta) {
    std::cout << "Test" << std::endl;
}

void Resource::_ready() {
    std::cout << "ready!!!!" << std::endl;
}

void Resource::_exit() {

}
