//
// Created by Sairam on 13-12-2021.
//

#ifndef TESTPROJECT_REFERENCE_H
#define TESTPROJECT_REFERENCE_H

#include "object.h"
#include "main_loop.h"
#include "iostream"

class InternalCounter {
public:
    explicit InternalCounter() {
        _counter = 0;
    }

    ~InternalCounter() = default;

    InternalCounter(const InternalCounter &c) = delete;

    void operator=(const InternalCounter &c) = delete;

    void reset() {
        _counter = 0;
    }

    unsigned int counter() const {
        return _counter;
    }

    // Shortcuts
    void operator++(int) {
        _counter++;
    }

    void operator++() {
        _counter++;
    }

    void operator--(int) {
        _counter--;
    }

    void operator--() {
        _counter--;
    }

    friend std::ostream &operator<<(std::ostream &ostream, const InternalCounter counter) {
        ostream << "Counter Value:" << counter._counter << std::endl;
        return ostream;
    }


private:
    unsigned int _counter = 0;
};

class Reference : public Object {
private:
    InternalCounter *counter;
    Reference *m_ptr;
public:
    explicit Reference() {
        counter = new InternalCounter();
        m_ptr = this;
        if (m_ptr) {
            (*counter)++;
        }
    }
    // Copy constructor
    Reference(const Reference &r) : Object(r) {
        m_ptr = r.m_ptr;
        counter = r.counter;
        (*counter)++;
    }

    unsigned int count() {
        return counter->counter();
    }

    Reference *get() {
        return m_ptr;
    }

    Reference &operator*() {
        return *m_ptr;
    };

    Reference *operator->() {
        return m_ptr;
    }

    ~Reference() {
        std::cout << "Exiting scope" << std::endl;
        (*counter)--;
        if (counter->counter() == 0 && m_ptr) {
            std::cout << "Exiting program.." << std::endl;
            m_ptr = nullptr;
            delete counter;
        }
    }

};

#endif //TESTPROJECT_REFERENCE_H
