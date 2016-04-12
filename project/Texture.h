// Ann Keenan
// Feb 29

#ifndef _TEXTURE
#define _TEXTURE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>

using namespace std;

class Texture {
public:
    Texture();
    ~Texture();

    void free();
    void setUp(SDL_Renderer *);
    SDL_Texture * loadTexture(string);
    void loadFromFile(string);
    void render(int,int,SDL_Rect *,SDL_RendererFlip = SDL_FLIP_NONE,double = 0.0,SDL_Point * = NULL);

    Uint8 getAlpha(int,int);

    int getWidth();
    int getHeight();
private:
    SDL_Renderer *Renderer;
    SDL_Texture *mTexture;
    SDL_Surface *surface;
    int mWidth;
    int mHeight;
};

#endif