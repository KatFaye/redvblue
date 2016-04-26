// Master.h
// Interface for Master class to control gameplay
// Project: Breaking Blue
// Authors: Kate Barlock, Kat Herring, Ann Keenan

#ifndef _MASTER
#define _MASTER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>
#include <cmath>
#include "Player.h"
#include "Enemy.h"
#include "Sound.h"
#include "Levels.h"

using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 400;

class Master {
public:
    Master();
    ~Master();
    // initial functions
    void init();
    void loadMedia();
    // main function
    void play(); // play game
    // utility functions
    void reset(); // reset/initially set all game attributes
    void update(bool=true);
    void updateCamera();
    void animate(Person *); // play any sequential animations (doors,roll,punch,kick)
    void jump(Person *);
    void checkKeyboard(); // check keyboard for held motion
    void checkKeyPress(); // check keyboard for short motion
    int moveFigure(Person *,double,double,bool=true); // change figure position, only check new position if bool set to false
    // collision detection
    // to foreground
    int checkCollision(Person *); // checks for right/left/top collisions with foreground
    void fixCollision(Person *,int collisionType); // respond to collision
    int checkGround(Person *);
    // to enemy
    bool checkEnemy(); // true if collision
private:
    SDL_Window *Window; // window rendering to
    SDL_Renderer *Renderer; // window renderer
    bool Quit; // boolean to quit, false = do not quit, true = quit
    bool NextLevel; // true = move on to next level
    // three states
    // 0 - pre-hit, 1 - hit, 2 - wait for no collision->back to 0
    int Hit;
    // composition
    Sound sound;
    Player player;
    Enemy enemy;
    Levels levels;
};

#endif