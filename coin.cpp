#include "src/coin.hpp"
#include <graphics.h>
#include <string>

Coin :: Coin(int _x = 0, int _y = 0, int _width = 0, int _height = 0, string file = "") : Obstacle(_x, _y, file, 0), width(_width), height(_height) {}

void Coin :: draw() const{

    readimagefile(imageFile.c_str(), x, y, x + width, y + height);
}

void Coin :: undraw() const{

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width + 5, y + height + 5);
}

bool Coin :: isPlayerHit(Player &player) const{
    
    bool checkX = (player.getX() + player.getWidth() >= x && player.getX() <= x + width) ? true : false;
    bool checkY = (player.getY() + player.getHeight() >= y && player.getY() <= y + height) ? true : false;

    if(checkX && checkY)
        return true;
    return false;
}

void Coin :: playerHitAction(Game &game){
    
    game.incrementScore(1);
    game.despawnObject();
}

bool Coin :: isObjectOutsideScreen() const{

    bool checkX = (x + width <= 0) ? true : false;
    
    return checkX;
}