#pragma once

#include <cmath>

constexpr float EPSILON = 1e-4;

inline bool almost_equal(float a, float b) {
    return std::fabs(a - b) < EPSILON;
}