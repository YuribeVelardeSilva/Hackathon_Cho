#ifndef TEXTUR_H
#define TEXTUR_H

#include "gameE.h"

typedef struct Game Game;

typedef struct Sprite{
SDL_Surface* surface;
SDL_Texture* texture;

SDL_Rect src;
SDL_Rect dest;

}Sprite;

void loadtexture(Sprite* sprite,Game* game,char* filepath,int posX,int posY,int width,int height);

void setSpriteSize(Sprite* sprite, int w,int h,int x,int y);

void renderTexture(Game* game, Sprite* sprite);

#endif