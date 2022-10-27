//
// Created by kanna on 31-08-2022.
//

#include "display_server.h"
#include "../main_loop.h"

Window *DisplayServer::create_window(String *name, Vector2 *position, Vector2 *size) {
    auto win = new Window();
    win->name = name;
    win->position = position;
    win->size = size;
    win->id = MainLoop::get_singleton()->object_counter;
    MainLoop::get_singleton()->object_counter++;
    windows.push_back(win);
    return win;
}

void DisplayServer::destroy_window(int id) {
    for (auto &window : windows) {
        if (window->id == id) {
            destroy_window(window);
        }
    }
}

void DisplayServer::destroy_window(Window *window) {
    auto idx = std::find(windows.begin(), windows.end(), window);
    if (idx != windows.end()) {
        windows.erase(idx);
    }
}

DisplayServer *DisplayServer::displayServer = nullptr;