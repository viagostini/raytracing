#pragma once

#include "utils.h"

struct Tuple {
    float x, y, z, w;

    Tuple();
    Tuple(float x, float y, float z, float w);

    Tuple operator-();
    Tuple operator*(float scalar);
    Tuple operator+(const Tuple &other);
    Tuple operator-(const Tuple &other);
    bool operator==(const Tuple &other) const;

    bool isPoint();
    bool isVector();
};

Tuple operator*(float scalar, const Tuple &a);

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);