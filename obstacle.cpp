#include "src/obstacle.hpp"
#include <graphics.h>
#include <string>

Obstacle :: Obstacle(int _x = 0, int _y = 0, string file = "", int _point = 0) : Object(_x, _y, file), point(_point) {}

void Obstacle :: move(int dx, int dy){

    undraw();
    x += dx;
    y += dy;
    draw();
}