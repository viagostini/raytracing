#include <vector>
#include "color.h"

struct Canvas {
    int width;
    int height;
    std::vector<std::vector<Color>> grid;

    Canvas() {}
    Canvas(int width, int height);
    
    Color pixelAt(int x, int y) const;
    void writePixel(int x, int y, Color color);
};