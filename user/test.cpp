//
// Created by kanna on 07-02-2022.
//

#include "test.h"
#include "iostream"

void Test::test() {
//    int x = 10;
//    std::cout << "Before X value ++x: " << x << std::endl;
//    int c = ++x;
//    std::cout << "After X value ++x: " << x << std::endl;
//    x = 10;
//    std::cout << "Before X value x++: " << x << std::endl;
//    int d = x++;
//    std::cout << "After X value x++: " << x << std::endl;
//
//    std::cout << "C value: " << c << std::endl;
//    std::cout << "D value: " << d << std::endl;
//    std::cout << "X value: " << x << std::endl;

    auto derived = Derived();
    do_stuff(&derived);

}

void Test::_ready() {
    test();
}


void Base::do_stuff() {
    std::cout << "This is called from Base class!";
}

void Derived::do_stuff() {
    std::cout << "This is called from Derived class!";
}

void Test::do_stuff(Base base) {
    base.do_stuff();
}

void Test::do_stuff(Base *base) {
    base->do_stuff();
}

void Test::do_stuff(Base &base) {
    base.do_stuff();
}

void Test::_input(InputEvent *event) {
//    auto motion = static_cast<InputEventMouseMotion *>(event);

    auto motion = dynamic_cast<InputEventMouseMotion *>(event);
    if (motion) {
        std::cout << "Mouse Motion (" << motion->position->x << ", " << motion->position->y << ")" << std::endl;
    }
    auto btn = dynamic_cast<InputEventMouseButton *>(event);
    if (btn) {
        std::cout << "Mouse Button " << btn->button_index << " is " << btn->pressed << std::endl;
    }
}