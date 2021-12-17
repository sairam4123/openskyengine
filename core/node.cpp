//
// Created by Sairam on 10-12-2021.
//

#include "node.h"

void Node::add_child(Node *child) {
    child->parent = this;
    children.push_back(child);
    MainLoop::get_singleton()->add_object(child);
}

void Node::remove_child(Node *child) {
    child->parent = nullptr;
    auto index = std::find(children.begin(), children.end(), child);
    if (index != children.cend()) {
        children.erase(index);
    }
}

void Node::remove_child(int index) {
    Node *child = children[index];
    remove_child(child);
}

void Node::add_child(Node *child, int index) {
    child->parent = this;
    children.insert(children.begin() + index, child);
    MainLoop::get_singleton()->add_object(child);
}

void Node::move_child(Node *child, int index) {
    remove_child(child);
    add_child(child, index);
}

void Node::set_name(String *p_name) {
    name = p_name;
}

void Node::set_name(const char *p_name) {
    name = new String(p_name);
}

Node::~Node() {
    delete name;
}
