#include "gtest/gtest.h"
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