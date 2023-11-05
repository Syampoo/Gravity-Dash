#include "src/spike.hpp"
#include <graphics.h>
#include <string>
#include <iostream>
using namespace std;

Spike :: Spike(int _x = 0, int _y = 0, int _width = 0, int _height = 0, string file = "") : Obstacle(_x, _y, file, 0), width(_width), height(_height) {}

void Spike :: draw() const{

    readimagefile(imageFile.c_str(), x, y, x + width, y + height);
}

void Spike :: undraw() const{

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width + 5, y + height + 5);
}

bool Spike :: isPlayerHit(Player &player) const{
    
    bool checkX = (player.getX() + player.getWidth() >= x && player.getX() + player.getWidth() <= x + width) ? true : false;
    bool checkY = (player.getY() + player.getHeight() >= y && player.getY() + player.getHeight() <= y + height) ? true : false;

    if(checkX && checkY){

        return true;
    }
    return false;
}

void Spike :: playerHitAction(Game &game){
    
    game.changeGameRule(GAME_LOSE);
}

bool Spike :: isObjectOutsideScreen() const{

    bool checkX = (x + width <= 0) ? true : false;
    
    return checkX;
}
