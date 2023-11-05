#ifndef SPIKE_HPP
#define SPIKE_HPP
#include "obstacle.hpp"
#include "player.hpp"
#include "game.hpp"
#include <string>
using namespace std;

class Game;

class Spike : public Obstacle{

    private:
        int width, height;
    
    public:
        Spike(int, int, int, int, string);

        void draw() const;

        void undraw() const;

        bool isPlayerHit(Player &) const;

        void playerHitAction(Game &);

        bool isObjectOutsideScreen() const;

};

#endif
