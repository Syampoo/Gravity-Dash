#ifndef PLATFORM_HPP
#define PLATFORM_HPP
#include "obstacle.hpp"
#include "player.hpp"
#include "game.hpp"
#include <string>
using namespace std;

class Game;

class Platform : public Obstacle{

    private:
        int width, height;
    
    public:
        Platform(int, int, int, int, string);

        void draw() const;

        void undraw() const;

        bool isPlayerHit(Player &) const;

        void playerHitAction(Game &);

        bool isObjectOutsideScreen() const;

};

#endif