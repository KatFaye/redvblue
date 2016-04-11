// Breaking Blue
// Master.h

#ifndef _MASTER
#define _MASTER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>
#include "Person.h"
#include "Sound.h"
#include "Level1.h"

using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 400;
const int GroundLevel = SCREEN_HEIGHT-300;

class Master {
public:
    Master();
    ~Master();
    void init();
    void loadMedia();
    SDL_Texture *loadTexture(string path);

    void play();
    void move(const double);
    void update();
    void stopMusic();

private:
    SDL_Window *Window; // window rendering to
    SDL_Renderer *Renderer; // window renderer

    Sound sound;
    Person person;
    Level1 level1;
};

#endif