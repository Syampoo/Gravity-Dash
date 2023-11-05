#include "src/object.hpp"
#include <string>
#include <graphics.h>

Object :: Object(int _x, int _y, string file) : x(_x), y(_y), imageFile(file) {}

int Object :: getX() const{

    return x;
}

int Object :: getY() const{

    return y;
}