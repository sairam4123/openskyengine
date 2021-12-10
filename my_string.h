//
// Created by Sairam on 12-09-2021.
//

#ifndef TESTPROJECT_MY_STRING_H
#define TESTPROJECT_MY_STRING_H

#include <string>

class MyString {
private:
    std::string *str;
public:

    MyString operator+(std::string *add_string);

    MyString operator+(const char *add_string);

    MyString operator+(MyString string);

    MyString operator*(size_t num);

    MyString &operator+=(std::string *add_string);

    MyString &operator+=(const char *add_string);

    MyString &operator+=(MyString string);

    MyString &operator*=(size_t num);

    bool operator==(const MyString* myString) {
        return std::strcmp(str->c_str(), myString->str->c_str()) == 0;
    }

    bool operator==(const char* myString) {
        return std::strcmp(str->c_str(), myString) == 0;
    }

    bool operator!=(const MyString* myString) {
        return std::strcmp(str->c_str(), myString->str->c_str()) != 0;
    }

    bool operator!=(const char* myString) {
        return std::strcmp(str->c_str(), myString) != 0;
    }


    MyString* operator[](int index);
    MyString* operator()(int start, int end);

    const char *c_str();

    explicit MyString(std::string *p_str) {
        str = p_str;
    };

    explicit MyString() {
        str = new std::string("");
    };

    explicit MyString(const char *p_str) {
        str = new std::string(p_str);
    };
};


#endif //TESTPROJECT_MY_STRING_H
