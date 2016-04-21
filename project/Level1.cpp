// Level1.cpp
// Implementation of Level1 derived class
// Project: Breaking Blue
// Authors: Kate Barlock, Kat Herring, Ann Keenan

#include "Level1.h"
#include "Texture.h"

using namespace std;

Level1::Level1() {
    CurrDoor = 0;
    CurrDoor1 = 0;
}

Level1::~Level1() {
    for (int f=0;f<4;f++)
        Foreground[f].free();

    Door1Texture.free();
    Door2Texture.free();
    Door3Texture.free();
}

void Level1::setUp(SDL_Window *window, SDL_Renderer *renderer) {
    Levels::setUp(window,renderer);

    for (int f=0;f<4;f++)
        Foreground[f].setUp(renderer);

    Door1Texture.setUp(renderer);
    Door2Texture.setUp(renderer);
    Door3Texture.setUp(renderer);
}

void Level1::display() {
    Levels::display(int(CurrDoor));

    SDL_Rect cam = *Levels::getCamera();

    getForeground()->render(0,0,&cam);
    cam.y = 400*int(CurrDoor1);
    Door1Texture.render(0,0,&cam);
    cam.y = 400*int(CurrDoor2);
    Door2Texture.render(0,0,&cam);
    cam.y = 400*int(CurrDoor3);
    Door3Texture.render(0,0,&cam);
}

void Level1::loadMedia() {
    Levels::setBackground("imgs/bg/level1.png");
    Levels::setMusic(Mix_LoadMUS("sound/mysterious.wav"));

    Foreground[0].loadFromFile("imgs/fg/level1_base1.png");
    Foreground[1].loadFromFile("imgs/fg/level1_base2.png");
    Foreground[2].loadFromFile("imgs/fg/level1_base3.png");
    Foreground[3].loadFromFile("imgs/fg/level1_base4.png");

    //Levels::setText("Level 00 Mission Files: Escape Red Compound" );

    Door1Texture.loadFromFile("imgs/fg/level1_door1.png");
    Door2Texture.loadFromFile("imgs/fg/level1_door2.png");
    Door3Texture.loadFromFile("imgs/fg/level1_door3.png");
}

Texture * Level1::getForeground() {
    // get foreground corresponding to whichever door has yet to be broken
    if (CurrDoor < 1) // no doors knocked down
        return &Foreground[0];
    else if (CurrDoor < 2)
        return &Foreground[1];
    else if (CurrDoor < 3)
        return &Foreground[2];
    else // all doors knocked down
        return &Foreground[3];
}

double Level1::getCurrDoor(int door) {
    if (door == 0)
        return CurrDoor;
    else if (door == 1)
        return CurrDoor1;
    else if (door == 2)
        return CurrDoor2;
    else
        return CurrDoor3;
}

void Level1::setCurrDoor(int door, double currDoor) {
    if (door == 0)
        CurrDoor = currDoor;
    else if (door == 1)
        CurrDoor1 = currDoor;
    else if (door == 2)
        CurrDoor2 = currDoor;
    else if (door == 3)
        CurrDoor3 = currDoor;
}

int Level1::getLevelWidth() {
    return LEVEL_WIDTH;
}
