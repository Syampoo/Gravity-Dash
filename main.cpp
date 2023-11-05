//==========================================================
//PROJECT DELIVARABLES 4 | PROGRAMMING TECHNIQUE II
//LECTURER : DR JUMAIL BIN TALIBA
//GROUP : GROUP 1
//GROUP MEMBERS : 1. HISYAMUDDIN FIRDAUS BIN HAMZAH 
//                2. MUHAMMAD DANIEL HAKIM BIN SYAHRULNIZAM 
//                3. KEVIN FACHREZY 
//PROJECT NAME : GRAVITY DASH
//VIDEO LINK : https://youtu.be/KnXRaI6iQYg
//===========================================================

#include <iostream>
#include <graphics.h>
#include <string>
#include <time.h>
#include <iostream>

#include "src/game.hpp"
using namespace std;

int generateRandomNumber(int startLimit, int endLimit){

    //Generate random number through the use of random number generator
    int random = startLimit + rand() % endLimit;
    return random;
}

int main(){

    int screenHeight = getmaxheight();
    int screenWidth = getmaxwidth();

    //Image directories and store them into their corresponding string variables
    string playerImage = "resources/player_cube.jpg";
    string floorImage = "resources/floor.jpg";
    string platformImage = "resources/platform_cube.jpg";
    string spikeImage = "resources/spike.jpg";
    string coinImage = "resources/coin.jpg";
    string loseImage = "resources/lose.jpg";
    string winImage = "resources/win.jpg";
    initwindow(screenWidth, screenHeight, "Gravity Dash");

    //Generate random number seed to be used by rand()
    srand(time(NULL));

    //Instances from Game class
    Game game(playerImage, floorImage, spikeImage, platformImage, coinImage, loseImage, winImage);

    //Variables
    //Key is used to capture keyboard key when the keybaord is pressed.
    //upperLim, lowerLim and randomNum are used in the random number generator to generate random number.
    //upperLim provides upper limit for the range of the random number and lowerLim provides lower limit.
    //randomNum is the result of the random number generator.
    char key = 0;
    int upperLim = 21;
    int lowerLim = 0;
    int randomNum;

    //Load the game scene at the start of the program
    game.loadScene();

    //Loop the entire frame in the scene only if the player did not press ESC key,
    //The player did not win or lose the game.
    //If one of the conditions is true, it will end the game.
    while(key != 27 && (!game.getIsGameLose() && !game.getIsGameWin())){

        key = 0;
        if(kbhit())
            key = getch();
        
        //Call the action method in Game class.
        //Action method is used to update the frame of the game,
        //and respond to the changes in the game rule and user's interaction.
        game.action(key);

        //Generate random number 
        if(!game.getIsObjectSpawned())
            randomNum = generateRandomNumber(lowerLim, upperLim);

        //Spawn the objects if there are no object on the screen.
        //Despawn the objects if the objects reached the end of the screen.
        game.spawnObject(randomNum);
        game.despawnAllObject();
        delay(2);
    }

    system("pause");
    return 0;
}