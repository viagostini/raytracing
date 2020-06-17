#include "gtest/gtest.h"

#include <cmath>
#include <stdexcept>

#include "tuple.h"

const float sqrt14 = sqrt(14);

TEST(Tuple, defaultTuple) {
    Tuple tuple;
    EXPECT_FLOAT_EQ(tuple.x, 0.0);
    EXPECT_FLOAT_EQ(tuple.y, 0.0);
    EXPECT_FLOAT_EQ(tuple.z, 0.0);
    EXPECT_FALSE(tuple.isPoint());
    EXPECT_TRUE(tuple.isVector());
}

TEST(Tuple, createTupleAsPoint) {
    Tuple tuple = Tuple(4.3, -4.2, 3.1, 1.0);
    EXPECT_FLOAT_EQ(tuple.x, 4.3);
    EXPECT_FLOAT_EQ(tuple.y, -4.2);
    EXPECT_FLOAT_EQ(tuple.z, 3.1);
    EXPECT_FLOAT_EQ(tuple.w, 1.0);
    EXPECT_TRUE(tuple.isPoint());
    EXPECT_FALSE(tuple.isVector());
}

TEST(Tuple, createTupleAsVector) {
    Tuple tuple = Tuple(4.3, -4.2, 3.1, 0.0);
    EXPECT_FLOAT_EQ(tuple.x, 4.3);
    EXPECT_FLOAT_EQ(tuple.y, -4.2);
    EXPECT_FLOAT_EQ(tuple.z, 3.1);
    EXPECT_FLOAT_EQ(tuple.w, 0.0);
    EXPECT_FALSE(tuple.isPoint());
    EXPECT_TRUE(tuple.isVector());
}

TEST(Tuple, createPoint) {
    Tuple point = Point(4, -4, 3);
    Tuple tuple = Tuple(4, -4, 3, 1);
    EXPECT_EQ(point, tuple);
}

TEST(Tuple, createVector) {
    Tuple vector = Vector(4, -4, 3);
    Tuple tuple = Tuple(4, -4, 3, 0);
    EXPECT_EQ(vector, tuple);
}

TEST(Tuple, addPointVector) {
    Tuple point = Point(3, -2, 5);
    Tuple vector = Vector(-2, 3, 1);

    Tuple result = point + vector;
    Tuple expected = Point(1, 1, 6);
    EXPECT_EQ(result, expected);
}

TEST(Tuple, addVectorVector) {
    Tuple vector = Vector(3, -2, 5);
    Tuple other_vector = Vector(-2, 3, 1);

    Tuple result = vector + other_vector;
    Tuple expected = Vector(1, 1, 6);
    EXPECT_EQ(result, expected);
}

TEST(Tuple, addPointPointThrows) {
    Tuple point = Point(3, -2, 5);
    Tuple other_point = Point(-2, 3, 1);
    EXPECT_THROW(point + other_point, std::invalid_argument);
}

TEST(Tuple, subtractPointPoint) {
    Tuple point = Point(3, 2, 1);
    Tuple other_point = Point(5, 6, 7);

    Tuple result = point - other_point;
    Tuple expected = Vector(-2, -4, -6);
    EXPECT_EQ(result, expected);
}

TEST(Tuple, subtractPointVector) {
    Tuple point = Point(3, 2, 1);
    Tuple vector = Vector(5, 6, 7);

    Tuple result = point - vector;
    Tuple expected = Point(-2, -4, -6);
    EXPECT_EQ(result, expected);
}

TEST(Tuple, subtractVectorVector) {
    Tuple vector = Vector(3, 2, 1);
    Tuple other_vector = Vector(5, 6, 7);

    Tuple result = vector - other_vector;
    Tuple expected = Vector(-2, -4, -6);
    EXPECT_EQ(result, expected);
}

TEST(Tuple, negateTuple) {
    Tuple tuple = Tuple(1, -2, 3, 1);

    Tuple result = -tuple;
    Tuple expected = Tuple(-1, 2, -3, 1);
    EXPECT_EQ(result, expected);
}

TEST(Tuple, scalarMult) {
    Tuple tuple = Tuple(1, -2, -3, 1);

    Tuple result = 2.0 * tuple;
    Tuple expected = Tuple(2, -4, -6, 1);
}

TEST(Tuple, scalarMultFraction) {
    Tuple tuple = Tuple(1, -2, -3, 1);

    Tuple result = tuple * 0.5;
    Tuple expected = Tuple(0.5, -1, -1.5, 1);
}

TEST(Tuple, scalarDiv) {
    Tuple tuple = Tuple(1, -2, -3, 1);

    Tuple result = tuple / 2;
    Tuple expected = Tuple(0.5, -1, -1.5, 1);
}

TEST(Tuple, scalarDivFraction) {
    Tuple tuple = Tuple(1, -2, -3, 1);

    Tuple result = tuple / 0.5;
    Tuple expected = Tuple(2, -4, -6, 1);
}

TEST(Tuple, scalarDivZeroThrows) {
    Tuple tuple = Tuple(1, -2, -3, 1);

    EXPECT_THROW(tuple / 0, std::overflow_error);
}

TEST(Tuple, magnitude) {
    Tuple vector = Vector(1, 0, 0);
    EXPECT_FLOAT_EQ(vector.magnitude(), 1);

    vector = Vector(0, 1, 0);
    EXPECT_FLOAT_EQ(vector.magnitude(), 1);

    vector = Vector(0, 0, 1);
    EXPECT_FLOAT_EQ(vector.magnitude(), 1);

    vector = Vector(1, 2, 3);
    EXPECT_FLOAT_EQ(vector.magnitude(), sqrt14);

    vector = Vector(-1, -2, -3);
    EXPECT_FLOAT_EQ(vector.magnitude(), sqrt14);
}

TEST(Tuple, normalize) {
    Tuple vector = Vector(4, 0, 0);

    vector.normalize();
    Tuple expected = Vector(1, 0, 0);
    EXPECT_EQ(vector, expected);
    EXPECT_FLOAT_EQ(vector.magnitude(), 1);

    vector = Vector(1, 2, 3);
    Tuple result = vector.normalized();
    expected = Vector(1/sqrt14, 2/sqrt14, 3/sqrt14);
    EXPECT_EQ(result, expected);
    EXPECT_FLOAT_EQ(result.magnitude(), 1);
}

TEST(Tuple, normalizeZeroMagnitudeThrows) {
    Tuple vector = Vector(0, 0, 0);
    ASSERT_THROW(vector.normalize(), std::overflow_error);
}

TEST(Tuple, dotProduct) {
    Tuple vector = Vector(1, 2, 3);
    Tuple other_vector = Vector(2, 3, 4);
    ASSERT_FLOAT_EQ(vector.dot(other_vector), 20);
}

TEST(Tuple, dotProductWithPointsThrows) {
    Tuple vector = Vector(1, 2, 3);
    Tuple point = Point(2, 3, 4);
    ASSERT_THROW(vector.dot(point), std::invalid_argument);

    point = Point(1, 2, 3);
    vector = Vector(1, 2, 3);
    ASSERT_THROW(point.dot(vector), std::invalid_argument);
}

TEST(Tuple, crossProduct) {
    Tuple vector = Vector(1, 2, 3);
    Tuple other_vector = Vector(2, 3, 4);
    
    Tuple result = vector.cross(other_vector);
    Tuple expected = Vector(-1, 2, -1);
    EXPECT_EQ(result, expected);

    result = other_vector.cross(vector);
    EXPECT_EQ(result, -expected);
}

TEST(Tuple, crossProductWithPointsThrows) {
    Tuple vector = Vector(1, 2, 3);
    Tuple point = Point(2, 3, 4);
    ASSERT_THROW(vector.cross(point), std::invalid_argument);

    point = Point(1, 2, 3);
    vector = Vector(1, 2, 3);
    ASSERT_THROW(point.cross(vector), std::invalid_argument);
}