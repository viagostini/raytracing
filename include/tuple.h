#pragma once

#include "utils.h"

struct Tuple {
    float x, y, z, w;

    Tuple();
    Tuple(float x, float y, float z, float w);

    Tuple operator-();
    Tuple operator*(float scalar);
    Tuple operator/(float scalar);
    Tuple operator+(const Tuple &other);
    Tuple operator-(const Tuple &other);
    bool operator==(const Tuple &other) const;

    bool isPoint() const;
    bool isVector() const;
    float magnitude() const;
    void normalize();
    Tuple normalized() const;
    float dot(const Tuple &other) const;
    Tuple cross(const Tuple &other) const;

};

Tuple operator*(float scalar, const Tuple &a);

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);