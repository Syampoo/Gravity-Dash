#include "src/player.hpp"
#include <graphics.h>
#include <string>

Player :: Player(int _x = 0, int _y = 0, int _width = 0, int _height = 0, string file = "") : Object(_x, _y, file), width(_width), height(_height) {

    speedY = 0;
}

void Player :: draw() const{

    readimagefile(imageFile.c_str(), x, y, x + width, y + height);
}

void Player :: undraw() const{

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);
}

void Player :: jump(int dy){

    undraw();
    speedY = dy;
    y += speedY;
    draw();
}

void Player :: fall(int speed, int limit){

    undraw();
    speedY += speed;
    y += speedY;

    if(y > limit){

        y = limit;
        speedY = 0;
    }

    draw();
}

int Player :: getWidth() const{

    return width;
}

int Player :: getHeight() const{

    return height;
}

void Player :: setSpeedY(int speed){

    speedY = speed;
}

void Player :: setY(int _y){

    undraw();
    y = _y;
    draw();
}