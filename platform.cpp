#include "src/platform.hpp"
#include <graphics.h>
#include <string>

Platform :: Platform(int _x = 0, int _y = 0, int _width = 0, int _height = 0, string file = "") : Obstacle(_x, _y, file, 0), width(_width), height(_height) {}

void Platform :: draw() const{

    readimagefile(imageFile.c_str(), x, y, x + width, y + height);
}

void Platform :: undraw() const{

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width + 10, y + height + 10);
}

bool Platform :: isPlayerHit(Player &player) const{

    bool checkX = (player.getX() + player.getWidth() >= x && player.getX() <= x + width) ? true : false;
    bool checkYAbove = (player.getY() + player.getHeight() >= y && player.getY() + player.getHeight() <= y + height) ? true : false;
    bool checkYBelow = (player.getY() >= y + height / 2 && player.getY() <= y + height) ? true : false;

    if(checkX && checkYAbove){

        player.setSpeedY(0);
        return true;
    }
    else if(checkX && checkYBelow){

        player.setY(y + height);
        player.setSpeedY(0);
        return false;
    }
    return false;
}

void Platform :: playerHitAction(Game &game){
    
    game.changeGameRule(PLAYER_ON_PLATFORM);
}

bool Platform :: isObjectOutsideScreen() const{

    bool checkX = (x + width <= 0) ? true : false;
    
    return checkX;
}