#include <stdexcept>
#include "tuple.h"
#include "utils.h"

Tuple::Tuple() : x(0.0), y(0.0), z(0.0), w(0.0) {}

Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Tuple Point(float x, float y, float z) {
    return Tuple(x, y, z, 1.0);
}

Tuple Vector(float x, float y, float z) {
    return Tuple(x, y, z, 0.0);
}

bool Tuple::isPoint() {
    return almost_equal(w, 1.0);
}

bool Tuple::isVector() {
    return almost_equal(w, 0.0);
}

bool Tuple::operator==(const Tuple &other) const {
    return almost_equal(x, other.x)
        && almost_equal(y, other.y)
        && almost_equal(z, other.z)
        && almost_equal(w, other.w);
}

#define BROADCAST_OPERATOR(a, b, op) { a.x op b.x, a.y op b.y, a.z op b.z, a.w op b.w }
Tuple operator+(const Tuple& a, const Tuple &b) {
    if (almost_equal(a.w + b.w, 2))
        throw std::invalid_argument("Adding two points is not supported.");
    return BROADCAST_OPERATOR(a, b, +);
}

Tuple operator-(const Tuple& a, const Tuple &b) {
    if (a.w - b.w < 0)
        throw std::invalid_argument("Subtracting point from vector is not supported.");
    return BROADCAST_OPERATOR(a, b, -);
}
#undef BROADCAST_OPERATOR

Tuple operator-(const Tuple &a) {
    return { -a.x, -a.y, -a.z, -a.w };
}

