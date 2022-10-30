//
// Created by Sairam on 29-10-2022.
//

#include "vector_2i.h"

Vector2i Vector2i::operator+(Vector2i a) const {
    return {this->x + a.x, this->y + a.y};
}

Vector2i Vector2i::operator+=(Vector2i other) const {
    return operator+(other);
}

Vector2i Vector2i::operator++() const {
    return operator+(Vector2i(1, 1));
}

Vector2i Vector2i::operator*(Vector2i a) const {
    return {};
}

Vector2i Vector2i::operator*(int64_t a) const {
    return {this->x * a, this->y * a};
}

Vector2i Vector2i::operator*=(int64_t a) const {
    return operator*(a);
}

Vector2i Vector2i::operator*=(Vector2i other) const {
    return {};
}


