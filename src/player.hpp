#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "object.hpp"
#include <string>
using namespace std;

class Player : public Object{

    private:
        int width, height, speedY;

    public:

        Player(int, int, int, int, string);

        void draw() const;

        void undraw() const;

        void jump(int);

        void fall(int, int);

        int getWidth() const;

        int getHeight() const;

        void setSpeedY(int);

        void setY(int);
};

#endif