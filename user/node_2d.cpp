//
// Created by Sairam on 10-12-2021.
//

#include "node_2d.h"
#include "iostream"
#include "../core/display/display_server.h"

void Node2D::_ready() {
    std::cout << name->c_str() << " is ready." << std::endl;
    auto window1 = DisplayServer::get_singleton()->create_window(
            new String("TestWindow2"),
            new Vector2i(10, 10),
            new Vector2i(500, 500)
            );
}

void Node2D::_exit() {
    std::cout << "exiting!" << std::endl;
}

void Node2D::_loop(const float delta) {
    x += 1 * delta;
//    if (fmod(x, 1.0) == 0.0) {
//        std::cout << x << std::endl;
//    }
//    std::cout << x << std::endl;
    if (x >= 20) {
        for (auto &win : DisplayServer::get_singleton()->windows) {
            win->close();
        }
    }
}

void Node2D::_input(InputEvent *event) {
    auto motion = dynamic_cast<InputEventMouseMotion *>(event);
    if (motion) {
        std::cout << "Mouse Motion (" << motion->position->x << ", " << motion->position->y << ")" << std::endl;
    }

    auto btn = dynamic_cast<InputEventMouseButton *>(event);
    if (btn) {
        std::cout << "Mouse Button " << btn->button_index << " is " << btn->pressed << std::endl;
    }

    auto key_ev = dynamic_cast<InputEventKey *>(event);
    if (key_ev) {
        if (key_ev->unicode == L'X') {
            std::wcout << key_ev->unicode << std::endl;
            auto win = DisplayServer::get_singleton()->create_window(
                new String("Window #1"),
                new Vector2i(100, 200),
                new Vector2i(1020, 200)
            );
        }
        std::wcout << "Key: " << key_ev->unicode << " is " << key_ev->pressed << " echo: " << key_ev->echo << std::endl;
    }
}
