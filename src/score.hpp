#ifndef SCORE_HPP
#define SCORE_HPP
#include "object.hpp"
#include <string>
using namespace std;

class Score : public Object{

    private:
        int width, height, score, font, fontSize;

    public:
        Score(int, int, int, int, int, int, string);

        void draw() const;

        void undraw() const;

        void incrementScore(int);

        void resetScore();

        int getScore() const;

};

#endif