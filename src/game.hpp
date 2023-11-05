#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "platform.hpp"
#include "coin.hpp"
#include "spike.hpp"
#include "score.hpp"
#include "obstacle.hpp"
#include <string>
#include <vector>
#include <graphics.h>
using namespace std;

//Player Attributes
#define PLAYER_X 100
#define PLAYER_Y 620
#define PLAYER_WIDTH 80
#define PLAYER_HEIGHT 80

//Floor Attributes
#define FLOOR_X 0
#define FLOOR_Y 700
#define FLOOR_WIDTH getmaxwidth()
#define FLOOR_HEIGHT getmaxheight()-400

//Score Attributes
#define SCORE_X getmaxwidth()-200
#define SCORE_Y 50
#define SCORE_WIDTH 80
#define SCORE_HEIGHT 80
#define SCORE_FONT SMALL_FONT
#define SCORE_FONT_SIZE 18

//Spawn Objects Atrributes
#define SPAWN_POS_X getmaxwidth()

//Platform Attributes
#define SPAWN_PLATFORM_Y1 400
#define SPAWN_PLATFORM_Y2 300
#define PLATFORM_HEIGHT 40
#define PLATFORM_WIDTH1 500
#define PLATFORM_WIDTH2 300

//Spike Attributes
#define SPAWN_SPIKE_Y 620
#define SPIKE_WIDTH 200
#define SPIKE_HEIGHT 80

//Coin Attributes
#define SPAWN_COIN_Y 600
#define COIN_WIDTH 50
#define COIN_HEIGHT 50

//Game Rule 
#define PLAYER_ON_PLATFORM 1
#define GAME_WIN 2
#define GAME_LOSE 3

//Win and Lose Image
#define TEXT_X 580
#define TEXT_Y 100
#define TEXT_WIDTH 200
#define TEXT_HEIGHT 200

class Obstacle;
class Floor;

class Game{

    private:
        string spikeImage, coinImage, platformImage, loseImage, winImage;
        Player player;
        Floor* floor;
        Score score;
        vector<Obstacle*> obstacle;
        bool isObjectSpawned, isPlayerOnPlatform, isGameLose, isGameWin;

    public:
        Game(string, string, string, string, string, string, string);

        void loadScene() const;

        void winGame() const;

        void loseGame() const;

        void spawnObject(int);

        void despawnAllObject();

        void despawnObject();

        bool getIsObjectSpawned();

        void changeGameRule(int);

        void incrementScore(int);

        bool getIsGameLose();

        bool getIsGameWin();

        void action(char);
};

#endif