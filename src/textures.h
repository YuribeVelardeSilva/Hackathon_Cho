#ifndef TEXTUR_H
#define TEXTUR_H

#include "gameE.h"
#include "sprite.h"
#include "srcdis.h"

typedef struct Game Game;
typedef struct SrcDis SrcDis;
typedef struct Module Module;
typedef struct Astronaut Astronaut;
typedef struct Suelo Suelo;

typedef struct Sprite{
    Astronaut* astronauta;
    Suelo* suelo;
    Module* module;
}Sprite;

typedef struct Fondo{
    SrcDis props;
    SDL_Rect rect;
}Fondo;

void loadtexture(SrcDis* dis,Game* game,char* filepath,int posX,int posY,int width,int height);

void setSpriteSize(SrcDis* dis, int w,int h,int x,int y);

void renderTexture(Game* game, SrcDis* dis);

void destroyTexture(SrcDis* dis);

#endif