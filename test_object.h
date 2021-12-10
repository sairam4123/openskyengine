//
// Created by Sairam on 03-12-2021.
//

#ifndef TESTPROJECT_TEST_OBJECT_H
#define TESTPROJECT_TEST_OBJECT_H


#include "object.h"
#include "my_string.h"

class Object : public Object_ {
public:
    int position = 0;
    MyString name;
    explicit Object(const char * _name) {
        name = MyString(_name);
    };
protected:
    void _loop() override;
    void _ready() override;
    void _exit() override;
};


#endif //TESTPROJECT_TEST_OBJECT_H
