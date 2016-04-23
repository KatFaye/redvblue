// Level2.cpp
// Implementation of Level2 derived class
// Project: Breaking Blue
// Authors: Kate Barlock, Kat Herring, Ann Keenan

#include "Level2.h"

using namespace std;

Level2::Level2() {
    // initialize to 0
    CurrText = 0;
}

Level2::~Level2() {
    // free all textures
    Foreground.free();
}

void Level2::setUp(SDL_Renderer *renderer) {
    // set up renderer on all textures
    Level::setUp(renderer);
    Foreground.setUp(renderer);
    MissionParam.setUp(renderer);

    Level::setLevelWidth(1000);
    Level::setLevelHeight(4000);
}

void Level2::display() {
    // call display of Level class
    Level::display();
    // get current camera display
    SDL_Rect cam = *Level::getCamera();
    // render foreground onto screen
    getForeground()->render(0,0,&cam);
    // display the mission parameters
    if(CurrText == 1) {
        MissionParam.display(&cam, 0); // PLACEHOLDER
    }
}

void Level2::loadMedia() {
    // set up media from Level class
    Level::setBackground("imgs/bg/level1.png");
    Level::setMusic(Mix_LoadMUS("sound/mysterious.wav"));
    // load all foreground textures
    Foreground.loadFromFile("imgs/lvl2/base1.png");

    MissionParam.loadMedia("imgs/lvl1/missionParam.png"); // PLACEHOLDER
}

Texture * Level2::getForeground() {
    // get foreground
    return &Foreground;
}

int Level2::getLevelWidth() {
    return Level::getLevelWidth();
}

int Level2::getLevelHeight() {
    return Level::getLevelHeight();
}

void Level2::setCurrText() {
    CurrText++; // move to next direction for mission parameter text
}