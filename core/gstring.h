//
// Created by Sairam on 12-09-2021.
//

#ifndef TESTPROJECT_GSTRING_H
#define TESTPROJECT_GSTRING_H

#include <string>
#include <iostream>
#include <codecvt>

class String {
private:
    std::string *str;
    std::wstring *wstr;

    void convert(std::string * str1) {
        try {
            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
            wstr = new std::wstring(converter.from_bytes(str1->c_str()));
        } catch(std::range_error& e) {
            size_t length = str1->length();
            std::wstring wstring;
            wstring.reserve(length);
            for(size_t i = 0; i < length; i++)
            {
                wstring.push_back(str->at(i) & 0xFF);
            }
            const wchar_t* temp = L"";
            wstring.copy(const_cast<wchar_t*>(temp), wstring.length());
            wstr = new std::wstring(temp);
        }
    }
public:

    String operator+(std::string *add_string);

    String operator+(const char *add_string);

    String operator+(String string);

    String operator*(size_t num);

    String &operator+=(std::string *add_string);

    String &operator+=(const char *add_string);

    String &operator+=(String string);

    String &operator*=(size_t num);

    bool operator==(const String* myString);

    bool operator==(const char* myString);

    bool operator==(const wchar_t* myString);
    bool operator!=(const wchar_t* myString);


    bool operator!=(const String* myString);

    bool operator!=(const char* myString);

    String* operator[](int index);
    String* operator()(int start, int end);

    const char *c_str();
    const wchar_t * wc_str();

    explicit String(std::string *p_str) {
        str = p_str;
        convert(str);
    };

    explicit String() {
        str = new std::string("");
        convert(str);
    };

    explicit String(const char *p_str) {
        str = new std::string(p_str);
        convert(str);
    };

    ~String();
};


#endif //TESTPROJECT_GSTRING_H
