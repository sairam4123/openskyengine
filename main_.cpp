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
