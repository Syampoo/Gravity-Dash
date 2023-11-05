#include "src/score.hpp"
#include <string>
#include <graphics.h>
using namespace std;
        
Score :: Score(int _x, int _y, int _width, int _height, int _font, int _fontSize, string _file) : Object(_x, _y, _file), width(_width), height(_height), font(_font), fontSize(_fontSize), score(0) {}

void Score :: draw() const{

    char cScore[6][3] = {"00", "01", "02", "03", "04", "05"};

    settextstyle(font, 0, fontSize);
    outtextxy(x + width + 25, y, cScore[score]);
    readimagefile(imageFile.c_str(), x, y - height / 4, x + width, y + height);
}

void Score :: undraw() const{

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(x + width + 5, y - 20, x + width + 100, y + height);
}

void Score :: incrementScore(int increment){

    undraw();
    score += increment;
    draw();
}

void Score :: resetScore(){

    undraw();
    score = 0;
    draw();
}

int Score :: getScore() const{

    return score;
}