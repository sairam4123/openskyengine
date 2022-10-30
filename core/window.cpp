//
// Created by kanna on 22-01-2022.
//

#include "window.h"
#include "display/display_server.h"

void Window::redraw() {

}


void Window::close() {
    DisplayServer::get_singleton()->destroy_window(this);
}

void Window::toggle_visiblity() {
    visible = !visible;
    DisplayServer::get_singleton()->set_window_visiblity(id, visible);
}

void Window::hide() {
    visible = false;
    DisplayServer::get_singleton()->set_window_visiblity(id, visible);
}

void Window::show() {
    visible = true;
    DisplayServer::get_singleton()->set_window_visiblity(id, visible);
}


void Window::get_native_handle() {
    DisplayServer::get_singleton()->get_native_handle(id);

}