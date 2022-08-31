//
// Created by kanna on 03-02-2022.
//

#ifndef TESTPROJECT_MAIN_H
#define TESTPROJECT_MAIN_H


#include "core/main_loop.h"

class Main {
private:
    MainLoop* mainLoop;
public:
    void init();
    Main();
    ~Main();
};


#endif //TESTPROJECT_MAIN_H
