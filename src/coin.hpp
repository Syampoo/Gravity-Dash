#ifndef COIN_HPP
#define COIN_HPP
#include "obstacle.hpp"
#include "player.hpp"
#include "game.hpp"
#include <string>
using namespace std;

class Game;

class Coin : public Obstacle{

    private:
        int height, width;

    public:
        Coin(int, int, int, int, string);

        void draw() const;

        void undraw() const;

        bool isPlayerHit(Player &) const;

        void playerHitAction(Game &);
        
        bool isObjectOutsideScreen() const;

};

#endif