//
// Created by Sairam on 03-12-2021.
//

#include <iostream>
#include "test_object.h"
#include "core/main_loop.h"

void Object::_loop() {
//    std::cout << "I'm " << name.c_str() << ". " << std::endl;
    position += 1;
    if (position >= 200) {
        mainLoop->exit();
    }
}

void Object::_ready() {
    std::cout << name.c_str() << " is ready!" << std::endl;
    std::cout << name.c_str() << "'s ID is: " << id << "." << std::endl;
    if (name == "Wow") {
        auto* object = new Object("Cool Wow");
        mainLoop->add_object(object);
    }
}

void Object::_exit() {
    std::cout << name.c_str() << " is exiting!" << std::endl;
    std::cout << name.c_str() << "'s ID is: " << id << "." << std::endl;

}
