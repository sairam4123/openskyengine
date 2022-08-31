//
// Created by kanna on 11-04-2022.
//

#include "vector_2.h"

Vector2 Vector2::operator+(Vector2 a) const {
    return {this->x + a.x, this->y + a.y};
}

Vector2 Vector2::operator+=(Vector2 other) const {
    return operator+(other);
}

Vector2 Vector2::operator++() const {
    return operator+(Vector2(1, 1));
}

Vector2 Vector2::operator*(Vector2 a) const {
    return {};
}

Vector2 Vector2::operator*(float a) const {
    return {this->x * a, this->y * a};
}

Vector2 Vector2::operator*=(float a) const {
    return operator*(a);
}

Vector2 Vector2::operator*=(Vector2 other) const {
    return {};
}


