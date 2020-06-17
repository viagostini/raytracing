#pragma once

#include "utils.h"

struct Tuple {
    float x, y, z, w;

    Tuple();
    Tuple(float x, float y, float z, float w);

    bool operator==(const Tuple &other) const;

    bool isPoint();
    bool isVector();
};

Tuple operator+(const Tuple& a, const Tuple &b);
Tuple operator-(const Tuple& a, const Tuple &b);
Tuple operator-(const Tuple& a);

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);