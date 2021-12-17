//
// Created by Sairam on 12-09-2021.
//

#ifndef TESTPROJECT_GSTRING_H
#define TESTPROJECT_GSTRING_H

#include <string>

class String {
private:
    std::string *str;
public:

    String operator+(std::string *add_string);

    String operator+(const char *add_string);

    String operator+(String string);

    String operator*(size_t num);

    String &operator+=(std::string *add_string);

    String &operator+=(const char *add_string);

    String &operator+=(String string);

    String &operator*=(size_t num);

    bool operator==(const String* myString) {
        return std::strcmp(str->c_str(), myString->str->c_str()) == 0;
    }

    bool operator==(const char* myString) {
        return std::strcmp(str->c_str(), myString) == 0;
    }

    bool operator!=(const String* myString) {
        return std::strcmp(str->c_str(), myString->str->c_str()) != 0;
    }

    bool operator!=(const char* myString) {
        return std::strcmp(str->c_str(), myString) != 0;
    }


    String* operator[](int index);
    String* operator()(int start, int end);

    const char *c_str();

    explicit String(std::string *p_str) {
        str = p_str;
    };

    explicit String() {
        str = new std::string("");
    };

    explicit String(const char *p_str) {
        str = new std::string(p_str);
    };

    ~String();
};


#endif //TESTPROJECT_GSTRING_H
