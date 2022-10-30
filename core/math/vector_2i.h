//
// Created by Sairam on 29-10-2022.
//

#ifndef TESTPROJECT_VECTOR_2I_H
#define TESTPROJECT_VECTOR_2I_H

#include <stdint.h>

class Vector2i {
public:
    int64_t x;
    int64_t y;

    Vector2i(int64_t p_x, int64_t p_y) {
        x = p_x;
        y = p_y;
    }

    Vector2i() {
        x = 0;
        y = 0;
    }

    Vector2i operator+(Vector2i a) const;

    Vector2i operator+=(Vector2i other) const;

    Vector2i operator++() const;

    Vector2i operator*(int64_t a) const;

    Vector2i operator*(Vector2i a) const;

    Vector2i operator*=(int64_t other) const;

    Vector2i operator*=(Vector2i other) const;

    static Vector2i *ZERO() {
        return new Vector2i(0, 0);
    };

    static Vector2i *ONE() {
        return new Vector2i(1, 1);
    };

    static Vector2i *UP() {
        return new Vector2i(0, 1);
    };

    static Vector2i *DOWN() {
        return new Vector2i(0, -1);
    };

    static Vector2i *LEFT() {
        return new Vector2i(-1, 0);
    };

    static Vector2i *RIGHT() {
        return new Vector2i(+1, 0);
    };
};


#endif //TESTPROJECT_VECTOR_2I_H
