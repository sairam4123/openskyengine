//
// Created by kanna on 03-02-2022.
//

#include "main.h"
#include "user/node_2d.h"
#include "user/test.h"

void Main::init() {
    auto node1 = new Node2D("Test");
    mainLoop->add_object(node1);
}

Main::Main() {
    mainLoop = new MainLoop();
}

Main::~Main() {
    for (auto& object : *mainLoop->get_objects()){
        mainLoop->remove_object(object);
        delete object;
    }
    delete mainLoop;
}
