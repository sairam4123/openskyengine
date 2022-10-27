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