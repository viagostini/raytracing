#include "gtest/gtest.h"

#include <stdexcept>

#include "tuple.h"

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

TEST(Tuple, addPointPoint) {
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

TEST(Tuple, scalarDivZero) {
    Tuple tuple = Tuple(1, -2, -3, 1);

    EXPECT_THROW(tuple / 0, std::overflow_error);
}