#include "gtest/gtest.h"

#include "canvas.h"

TEST(Canvas, createCanvas) {
    Canvas canvas = Canvas(10, 20);
    
    EXPECT_EQ(canvas.width, 10);
    EXPECT_EQ(canvas.height, 20);
    
    for (auto& row: canvas.grid)
        for (auto& col: row)
            EXPECT_EQ(col, Color::BLACK());
}

TEST(Canvas, writePixelToCanvas) {
    Canvas canvas = Canvas(10, 20);
    Color red = Color(1, 0, 0);

    canvas.writePixel(2, 3, red);
    EXPECT_EQ(canvas.pixelAt(2, 3), red);
}