#include "src/floor.hpp"
#include <graphics.h>
#include <string>

Floor :: Floor(int _x = 0, int _y = 0, int _width = 0, int _height = 0, string file = "") : Obstacle(_x, _y, file, 0), width(_width), height(_height) {}

void Floor :: draw() const{

    readimagefile(imageFile.c_str(), x, y, x + width, y + height);
}

void Floor :: undraw() const{

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);
}

int Floor :: getFloorLevel() const{

    return y;
}

void Floor :: redraw() const{

    undraw();
    draw();
}

bool Floor :: isPlayerHit(Player &player) const{

    return 0;
}

void Floor :: playerHitAction(Game &game){

    return;
}   

bool Floor :: isObjectOutsideScreen() const{

    bool checkX = (x + width <= 0) ? true : false;
    
    return checkX;
}