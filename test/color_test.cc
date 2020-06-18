#include "gtest/gtest.h"

#include "color.h"

TEST(Color, defaultColor) {
    Color color = Color();
    ASSERT_FLOAT_EQ(color.red(), 0);
    ASSERT_FLOAT_EQ(color.green(), 0);
    ASSERT_FLOAT_EQ(color.blue(), 0);
}

TEST(Color, createColor) {
    Color color = Color(-0.5, 0.4, 1.7);
    ASSERT_FLOAT_EQ(color.red(), -0.5);
    ASSERT_FLOAT_EQ(color.green(), 0.4);
    ASSERT_FLOAT_EQ(color.blue(), 1.7);
}


TEST(Color, createFromTuple) {
    Tuple tuple = Tuple(1, 1, 1, 1);
    Color color = Color(tuple);

    ASSERT_FLOAT_EQ(color.red(), 1);
    ASSERT_FLOAT_EQ(color.green(), 1);
    ASSERT_FLOAT_EQ(color.blue(), 1);
}

TEST(Color, addColor) {
    Color c1 = Color(0.9, 0.6, 0.75);
    Color c2 = Color(0.7, 0.1, 0.25);

    Color result = c1 + c2;
    Color expected = Color(1.6, 0.7, 1.0);
    ASSERT_EQ(result, expected);
}

TEST(Color, subtractColor) {
    Color c1 = Color(0.9, 0.6, 0.75);
    Color c2 = Color(0.7, 0.1, 0.25);

    Color result = c1 - c2;
    Color expected = Color(0.2, 0.5, 0.5);
    ASSERT_EQ(result, expected);
}

TEST(Color, multiplyColorScalar) {
    Color color = Color(0.2, 0.3, 0.4);

    Color result = color * 2;
    Color expected = Color(0.4, 0.6, 0.8);
    ASSERT_EQ(result, expected);

    result = 0.5 * color;
    expected = Color(0.1, 0.15, 0.2);
    ASSERT_EQ(result, expected);
}

TEST(Color, colorProduct) {
    Color c1 = Color(1, 0.2, 0.4);
    Color c2 = Color(0.9, 1, 0.1);

    Color result = c1 * c2;
    Color expected = Color(0.9, 0.2, 0.04);
    ASSERT_EQ(result, expected);
}