#pragma once

#include "tuple.h"

struct Color {
    Tuple tuple_;

    Color() {}
    Color(const Tuple &tuple);
    Color(float r, float g, float b);

    float red() const;
    float green() const;
    float blue() const;

    Color operator*(float a);
    Color operator*(const Color &other);
    Color operator+(const Color &other);
    Color operator-(const Color &other);
    bool operator==(const Color &other) const;
};

Color operator*(float a, const Color &other);