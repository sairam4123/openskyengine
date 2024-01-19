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
#ifdef NDEBUG
    x += 1 * delta;
    if (x >= 10 && !alerted) {
        DisplayServer::get_singleton()->alert(new String("Free Trial ENDED, purchase the game engine!"));
        alerted = true;
    }
    if (x >= 15 && alerted) {    
        for (auto &win : DisplayServer::get_singleton()->windows) {
            win->close();
        }
        MainLoop::get_singleton()->exit();
    }
#endif
}

void Node2D::_input(InputEvent *event) {
    auto motion = dynamic_cast<InputEventMouseMotion *>(event);
    if (motion) {
        std::cout << "Mouse Motion (" << motion->position->x << ", " << motion->position->y << ")" << std::endl;
    }

    auto key_ev = dynamic_cast<InputEventKey *>(event);
    if (key_ev) {
        bool insanity_check = key_ev->unicode == L'Z' && key_ev->ctrl && !key_ev->echo && key_ev->pressed && DisplayServer::get_singleton()->is_main_window(key_ev->window->id);

        if (insanity_check && insanity_checks < 6 && !insanity_check_successful) {
            DisplayServer::get_singleton()->alert(new String("Ctrl+Z is pressed, do not disturb me again!"));
            insanity_checks++;
        } else if (insanity_check && insanity_checks >= 6 && !insanity_check_successful) {
            DisplayServer::get_singleton()->alert(new String("Duck it, im not responding anymore!"));
            insanity_check_successful = true;
        }

        if (key_ev->unicode == L'X' && key_ev->ctrl && !key_ev->echo && key_ev->pressed && DisplayServer::get_singleton()->is_main_window(key_ev->window->id)) {
#ifdef NDEBUG
            if (current_window_count <= max_windows) {
                DisplayServer::get_singleton()->create_window(new String("TestWindowSmall"), new Vector2i(100, 200), new Vector2i(500, 200));
                current_window_count++;
            } else {
                DisplayServer::get_singleton()->alert(new String("Max windows reached, purchase our game engine!"));
            }
#else
                DisplayServer::get_singleton()->create_window(new String("TestWindowSmall"), new Vector2i(100, 200), new Vector2i(500, 200));
#endif
        }

    }
    auto btn = dynamic_cast<InputEventMouseButton *>(event);
    if (btn) {
        std::cout << "Mouse Button " << btn->button_index << " is " << btn->pressed << std::endl;
    }    
}
