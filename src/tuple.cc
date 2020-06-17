#include <cmath>
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

Tuple Tuple::operator-() {
    return { -x, -y, -z, w };
}


Tuple Tuple::operator+(const Tuple &b) {
    if (almost_equal(w + b.w, 2))
        throw std::invalid_argument("Adding two points is not supported.");
    return { x + b.x, y + b.y, z + b.z, w + b.w };
}

Tuple Tuple::operator-(const Tuple &b) {
    if (w - b.w < 0)
        throw std::invalid_argument("Subtracting point from vector is not supported.");
    return { x - b.x, y - b.y, z - b.z, w - b.w };
}

Tuple Tuple::operator*(float scalar) {
    return { x * scalar, y * scalar, z * scalar, w };
}

Tuple Tuple::operator/(float scalar) {
    if (almost_equal(scalar, 0))
        throw std::overflow_error("Division by zero.");
    return { x / scalar, y / scalar, z / scalar, w };
}

Tuple operator*(float scalar, const Tuple &a) {
    return { a.x * scalar, a.y * scalar, a.z * scalar, a.w };
}

bool Tuple::operator==(const Tuple &other) const {
    return almost_equal(x, other.x)
        && almost_equal(y, other.y)
        && almost_equal(z, other.z)
        && almost_equal(w, other.w);
}

float Tuple::magnitude() {
    // TODO: possible optimization later on: use squared length for comparisons
    return sqrt(x*x + y*y + z*z);
}

Tuple Tuple::normalize() {
    float mag = magnitude();

    if (almost_equal(mag, 0))
        throw std::overflow_error("Normalizing vector with magnitude zero causes division by zero.");

    return { x / mag, y / mag, z / mag, w };
}