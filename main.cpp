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
    // std::cout << DisplayServer::get_singleton() << std::endl;
    // auto window2 = DisplayServer::get_singleton()->create_window(]
    //         new String("TestWindow3"),
    //         new Vector2(50, 10),
    //         new Vector2(500, 500)
    //         );
    // auto hwnd_id = dynamic_cast<DisplayServerWindows *>(DisplayServer::get_singleton())->hwnd_id_map;
    // for (auto itr = hwnd_id.begin(); itr != hwnd_id.end(); ++itr) {
        // std::cout << '\t' << itr->first << '\t' << itr->second
            //  << '\n';
    // }
    // std::cout <<  << std::endl;
    // std::cout << window1->id << std::endl;
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
