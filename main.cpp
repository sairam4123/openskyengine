#include <iostream>
#include "core/main_loop.h"
#include "user/node_2d.h"

using namespace std;

int main() {
    auto *mainLoop = new MainLoop();
    auto *node = new Node2D("Node2D");
    auto *node_2 = new Node2D("Node3D");
    mainLoop->add_object(node);
    node->add_child(node_2);

    mainLoop->start();
    return 0;
}
