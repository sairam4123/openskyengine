//
// Created by kanna on 03-02-2022.
//

#include "main.h"
#include "user/node_2d.h"
#include "user/test.h"
#include "core/display/display_server.h"
#include "platforms/win/display_server_windows.h"

void Main::init() {
    auto node1 = new Node2D("Test");
    MainLoop::get_singleton()->add_object(node1);
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
