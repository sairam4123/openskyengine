#include <iostream>
#include "core/main_loop.h"
#include "user/node_2d.h"
//#include "core/reference.h"
#include "user/resource.h"

using namespace std;


int main() {
    {
        auto *mainLoop = new MainLoop();
        auto *node = new Node2D("Node2D");
        auto *node_2 = new Node2D("Node3D1");

        auto res = Resource();
        mainLoop->add_object(node);
        mainLoop->add_object(&res);
        node->add_child(node_2);

        mainLoop->start();

        delete node;
        delete node_2;
        delete mainLoop;
    }
    return 0;
}
