//
// Created by kanna on 11-04-2022.
//

#ifndef TESTPROJECT_VECTOR_2_H
#define TESTPROJECT_VECTOR_2_H


class Vector2 {
public:
    float x;
    float y;

    Vector2(float p_x, float p_y) {
        x = p_x;
        y = p_y;
    }

    Vector2() {
        x = 0;
        y = 0;
    }

    Vector2 operator+(Vector2 a) const;

    Vector2 operator+=(Vector2 other) const;

    Vector2 operator++() const;

    Vector2 operator*(float a) const;

    Vector2 operator*(Vector2 a) const;

    Vector2 operator*=(float other) const;

    Vector2 operator*=(Vector2 other) const;

    static Vector2 *ZERO() {
        return new Vector2(0, 0);
    };

    static Vector2 *ONE() {
        return new Vector2(1, 1);
    };

    static Vector2 *UP() {
        return new Vector2(0, 1);
    };

    static Vector2 *DOWN() {
        return new Vector2(0, -1);
    };

    static Vector2 *LEFT() {
        return new Vector2(-1, 0);
    };

    static Vector2 *RIGHT() {
        return new Vector2(+1, 0);
    };
};


#endif //TESTPROJECT_VECTOR_2_H
