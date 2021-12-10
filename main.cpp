#include <iostream>
#include "core/main_loop.h"
#include "test_object.h"

using namespace std;

int main() {
    auto *mainLoop = new MainLoop();
    auto *object = new Object("Test");
    auto *object1 = new Object("Wow");
    mainLoop->add_object(object);
    mainLoop->add_object(object1);
    mainLoop->start();
    char i = 0;
    cin >> i;
    return 0;
}
