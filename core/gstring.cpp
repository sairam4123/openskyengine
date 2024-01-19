//
// Created by Sairam on 12-09-2021.
//

#include "gstring.h"


String String::operator+(String string) {
    return String(&str->append(string.c_str()));
}

String String::operator+(std::string *add_string) {
    return String(&str->append(*add_string));
}

const char *String::c_str() {
    return str->c_str();
}

const wchar_t *String::wc_str() {
    return wstr->c_str();
}

String String::operator*(size_t num) {
    std::string *tmp = str;
    for (size_t i = 1; i < num; ++i) {
        tmp = &tmp->append(*str);
    }
    return String(tmp->c_str());
}

String &String::operator+=(std::string *add_string) {
    str = &str->append(*add_string);
    convert(str);
    return *this;
}

String &String::operator+=(String string) {
    str = &str->append(string.c_str());
    convert(str);
    return *this;
}

String &String::operator*=(size_t num) {
    std::string *tmp = str;
    for (size_t i = 1; i < num; ++i) {
        tmp = &tmp->append(*str);
    }
    str = tmp;
    convert(str);
    return *this;
}

String String::operator+(const char *add_string) {
    return String(&str->append(add_string));
}

String &String::operator+=(const char *add_string) {
    str = &str->append(add_string);
    convert(str);
    return *this;
}

String *String::operator[](int index) {
    return new String(&str[index]);
}

String *String::operator()(int start, int end) {
    return new String(str->substr(start, end).c_str());
}

String::~String() {
    delete str;
}

bool String::operator==(const String *myString) {
    return (std::strcmp(str->c_str(), myString->str->c_str()) == 0
    && std::wcscmp(wstr->c_str(), myString->wstr->c_str()));
}

bool String::operator==(const char *myString) {
    return std::strcmp(str->c_str(), myString) == 0;
}

bool String::operator!=(const String *myString) {
    return (std::strcmp(str->c_str(), myString->str->c_str()) != 0
    && std::wcscmp(wstr->c_str(), myString->wstr->c_str()));
}

bool String::operator!=(const char *myString) {
    return std::strcmp(str->c_str(), myString) != 0;
}

bool String::operator!=(const wchar_t *myString) {
    return std::wcscmp(wstr->c_str(), myString) != 0;
}

bool String::operator==(const wchar_t *myString) {
    return std::wcscmp(wstr->c_str(), myString) == 0;
}
