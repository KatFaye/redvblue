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
    void setUp(SDL_Renderer *);
    void loadFromFile(string);
    void free();
    void render(int,int,SDL_Rect *,SDL_RendererFlip = SDL_FLIP_NONE,double = 0.0,SDL_Point * = NULL);
    int getWidth() const;
    int getHeight() const;

private:
    SDL_Renderer *Renderer;
    SDL_Texture *mTexture;
    int mWidth;
    int mHeight;
};

#endif