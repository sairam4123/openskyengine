//
// Created by Sairam on 17-12-2021.
//

#ifndef TESTPROJECT_RESOURCE_H
#define TESTPROJECT_RESOURCE_H


#include "../core/reference.h"

class Resource : public Reference {
public:
    void _loop(float delta) override;
    void _ready() override;
    void _exit() override;
};


#endif //TESTPROJECT_RESOURCE_H
