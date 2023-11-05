#include "src/game.hpp"
#include "src/obstacle.hpp"
#include "src/floor.hpp"
#include <string>
#include <vector>
#include <graphics.h>
#include <time.h>
#include <iostream>
using namespace std;

Game :: Game(string _playerImage = "", string _floorImage = "", string _spikeImage = "", string _platformImage = "", string _coinImage = "", string _loseImage = "", string _winImage = "") : player(PLAYER_X, PLAYER_Y, PLAYER_WIDTH, PLAYER_HEIGHT, _playerImage),
                                                                                                                                          floor(new Floor(FLOOR_X, FLOOR_Y, FLOOR_WIDTH, FLOOR_HEIGHT, _floorImage)),
                                                                                                                                          score(SCORE_X, SCORE_Y, SCORE_WIDTH, SCORE_HEIGHT, SCORE_FONT, SCORE_FONT_SIZE, _coinImage),
                                                                                                                                          spikeImage(_spikeImage), platformImage(_platformImage), coinImage(_coinImage),
                                                                                                                                          loseImage(_loseImage), winImage(_winImage),
                                                                                                                                          isObjectSpawned(false), isPlayerOnPlatform(false), isGameLose(false), isGameWin(false) {}

void Game :: loadScene() const{

    //Load the scene at the start of the game
    score.draw();
    player.draw();
    floor -> draw();
}

void Game :: winGame() const{

    readimagefile(winImage.c_str(), TEXT_X, TEXT_Y, TEXT_WIDTH, TEXT_HEIGHT);
}

void Game :: loseGame() const{

    readimagefile(loseImage.c_str(), TEXT_X, TEXT_Y, TEXT_WIDTH, TEXT_HEIGHT);
}

void Game :: spawnObject(int random){

    //Spawn objects based on two different groups of objects
    //One contains a spike and a coin
    //And another one contains a platform, a spike and a coin
    //The rarity of the spawned objects configuration is determined
    //by random number generator in main() function.
   if(random < 10 && !isObjectSpawned){

        obstacle.push_back(new Spike(SPAWN_POS_X, SPAWN_SPIKE_Y, SPIKE_WIDTH, SPIKE_HEIGHT, spikeImage));
        obstacle.push_back(new Coin(SPAWN_POS_X + SPIKE_WIDTH / 2, SPAWN_COIN_Y - SPIKE_HEIGHT - 100, COIN_WIDTH, COIN_HEIGHT, coinImage));
        isObjectSpawned = true;
   }
   else if(random < 15 && !isObjectSpawned){

        obstacle.push_back(new Platform(SPAWN_POS_X + SPIKE_WIDTH, SPAWN_PLATFORM_Y1, PLATFORM_WIDTH1, PLATFORM_HEIGHT, platformImage));
        obstacle.push_back(new Spike(SPAWN_POS_X + PLATFORM_WIDTH1, SPAWN_SPIKE_Y, SPIKE_WIDTH, SPIKE_HEIGHT, spikeImage));
        obstacle.push_back(new Coin(SPAWN_POS_X + PLATFORM_WIDTH1, SPAWN_PLATFORM_Y1 - PLATFORM_HEIGHT - 20, COIN_WIDTH, COIN_HEIGHT, coinImage));
        isObjectSpawned = true;
   }

    //Draw all the spawned objects
    //If there is no object spawned
    //then the program will ignore the loop.
   for(int i = 0; i < obstacle.size(); i++){

        obstacle[i] -> draw();
   }

}

void Game :: despawnAllObject(){

    //Check all the objects
    //whethere the spawned objects have reached the end of the screen
    //If true, it will despawn the object that reached the end of the screen
    for(int i = 0; i < obstacle.size(); i++){
        
        if(isObjectSpawned && obstacle[0] -> isObjectOutsideScreen())
            obstacle.erase(obstacle.begin());
    }

    //Set the game rule for isObjectSpawned to default which is false
    //Allowing the other objects to spawn again.
    if(obstacle.size() == 0)
        isObjectSpawned = false;
}

void Game :: despawnObject(){

    //Despawn an object particularly the last element in the vector
    //Coin object is placed as the last element in the vectorr
    //Hence when this method is called, the coin object will be the first one to be erased.
    obstacle[obstacle.size() - 1] -> undraw();
    obstacle.pop_back();
}

bool Game :: getIsObjectSpawned(){

    return isObjectSpawned;
}

void Game :: changeGameRule(int rule){

    //Change the game rule to dictate the gameplay of the game
    //Whether the player is on the platform or the player wins the game or lose the game.
    //When isPlayerOnPlatform is setted to be true, it will prevent the player from falling.
    //When isGameWin is setted to be true, the player wins the game.
    //When isGameLose is setted to be true, the player lose the game.
    switch(rule){

        case PLAYER_ON_PLATFORM:
            isPlayerOnPlatform = true;
            break;

        case GAME_WIN:
            isGameWin = true;
            break;

        case GAME_LOSE:
            isGameLose = true;
            break;

        //Set all the game rules to default value which are false.
        default:
            isPlayerOnPlatform = false;
            isGameWin = false;
            isGameLose = false;
            break;
    }
}

void Game :: incrementScore(int increment){

    //Increment the player score by calling incrementScore method in Score class.
    score.incrementScore(increment);
    cout << endl << score.getScore() << endl;
}

bool Game :: getIsGameLose(){

    return isGameLose;
}

bool Game :: getIsGameWin(){

    return isGameWin;
}

void Game :: action(char key){

    //Check all the spawned objects
    //Whether the player hit a certain object through the use of Polymorphism
    //If the player hits a certain object, then a specific type of player action will be executed
    //through the playerHitAction() method which also used the concept of Polymorphism
    for(int i = 0; i < obstacle.size(); i++){

        if(obstacle[i] -> isPlayerHit(player)){

            obstacle[i] -> playerHitAction(*this);
        }
    }
    
    //Check the goal of the game which is when the player succesfully obtained five coins,
    //If the player successfully obtained five coins, the player wins the game.
    if(score.getScore() == 2)
        isGameWin = true;

    //If the player wins or loses the game, it will automatically exit the method
    if(isGameLose){

        loseGame();
        return;
    }
    else if(isGameWin){

        winGame();
        return;
    }

    //Check the condition to allow the player to jump or fall.
    //When the player presses space bar and the player is on the floor,
    //The player will execute jump.
    //When the player is above the floor and is not on the platform,
    //The player will fall down the floor or nearby platform.
    //If the player hits a platform or floor, it will prevent the player from falling.
    int playerBottomY = player.getY() + player.getHeight();
    if(key == ' ' && playerBottomY == floor -> getFloorLevel()){

        player.jump(-36);
    }
    else if(playerBottomY > floor -> getFloorLevel()){

        player.setY(PLAYER_Y);
        floor -> redraw();
    }
    else if(playerBottomY < floor -> getFloorLevel() && !isPlayerOnPlatform){

        player.fall(2, playerBottomY);
    }
    else if(isPlayerOnPlatform){

        player.setY(SPAWN_PLATFORM_Y1 - player.getHeight());
    }


    //Move all the spawned objects through the use of Polymorphism
    for(int i = 0; i < obstacle.size(); i++){

        obstacle[i] -> move(-20, 0);
    }

    //Set all the game rule to default which are false.
    changeGameRule(0);
}