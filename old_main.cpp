#include <iostream>
#include "core/main_loop.h"
#include "user/node_2d.h"
#include "user/resource.h"

using namespace std;

int run() {
    auto mainLoop = new MainLoop();
    auto node = Node("Test");
    auto node_2 = Node2D("Node2D");
    auto node_3 = Node2D("Node2D1");

    auto res = Resource();
    mainLoop->add_object(&node);
    mainLoop->add_object(&res);
    node.add_child(&node_2);
    node.add_child(&node_3);

    mainLoop->start();

    delete mainLoop;
    return 0;
}

int main() {
    auto error = run();
    cout << "Exiting Application" << endl;
    return error;
}


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