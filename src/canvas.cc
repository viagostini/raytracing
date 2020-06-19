#include "canvas.h"

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    grid.assign(width, std::vector<Color>(height, Color::BLACK()));
}

void Canvas::writePixel(int x, int y, Color color) {
    grid[x][y] = color;
}

Color Canvas::pixelAt(int x, int y) const {
    return grid[x][y];
}