#ifndef FLOOR_HPP
#define FLOOR_HPP
#include "obstacle.hpp"
#include "player.hpp"
#include "game.hpp"
#include <string>
using namespace std;

class Game;

class Floor : public Obstacle{

    private:
        int width, height;

    public:
        Floor(int, int, int, int, string);

        void draw() const;

        void undraw() const;

        int getFloorLevel() const;

        void redraw() const;

        bool isPlayerHit(Player &) const;

        void playerHitAction(Game &);

        bool isObjectOutsideScreen() const;

};

#endif