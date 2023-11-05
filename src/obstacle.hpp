#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include "object.hpp"
#include "player.hpp"
#include <string>
using namespace std;

class Game;

class Obstacle : public Object{

    protected:
        int point;

    public: 
        Obstacle(int, int, string, int);

        virtual void draw() const = 0;

        virtual void undraw() const = 0;

        virtual bool isPlayerHit(Player &) const = 0;

        virtual void playerHitAction(Game &) = 0;

        virtual bool isObjectOutsideScreen() const = 0;

        void move(int, int);
};

#endif