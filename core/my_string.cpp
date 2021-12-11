//
// Created by Sairam on 12-09-2021.
//

#include "my_string.h"



MyString MyString::operator+(MyString string) {
    return MyString(&str->append(string.c_str()));
}

MyString MyString::operator+(std::string *add_string) {
    return MyString(&str->append(*add_string));
}

const char *MyString::c_str() {
    return str->c_str();
}

MyString MyString::operator*(size_t num) {
    std::string *tmp = str;
    for (size_t i = 1; i < num; ++i) {
        tmp = &tmp->append(*str);
    }
    return MyString(tmp->c_str());
}

MyString &MyString::operator+=(std::string *add_string) {
    str = &str->append(*add_string);
    return *this;
}

MyString &MyString::operator+=(MyString string) {
    str = &str->append(string.c_str());
    return *this;
}

MyString &MyString::operator*=(size_t num) {
    std::string *tmp = str;
    for (size_t i = 1; i < num; ++i) {
        tmp = &tmp->append(*str);
    }
    str = tmp;
    return *this;
}

MyString MyString::operator+(const char *add_string) {
    return MyString(&str->append(add_string));
}

MyString &MyString::operator+=(const char *add_string) {
    str = &str->append(add_string);
    return *this;
}

MyString *MyString::operator[](int index) {
    return new MyString(&str[index]);
}

MyString *MyString::operator()(int start, int end) {
    return new MyString(str->substr(start, end).c_str());
}

MyString::~MyString() {
    delete str;
}
