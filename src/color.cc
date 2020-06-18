#include "color.h"

Color::Color(const Tuple &tuple) : tuple_(tuple) {}

Color::Color::Color(float r, float g, float b) : tuple_(Tuple(r, g, b, 0)) {}

float Color::red() const {
    return tuple_.x;
}

float Color::green() const {
    return tuple_.y;
}

float Color::blue() const {
    return tuple_.z;
}

Color Color::operator+(const Color &other) {
    return Color(tuple_ + other.tuple_);
}

Color Color::operator-(const Color &other) {
    return Color(tuple_ - other.tuple_);
}

Color Color::operator*(float a) {
    return Color(tuple_ * a);
}

bool Color::operator==(const Color &other) const {
    return tuple_ == other.tuple_;
}

Color Color::operator*(const Color &other) {
    return Color(
        red() * other.red(),
        green() * other.green(),
        blue() * other.blue()
    );
}

Color operator*(float a, const Color &other) {
    return Color(a * other.tuple_);
}
