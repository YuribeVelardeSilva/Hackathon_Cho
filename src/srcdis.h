#ifndef SRCDIS_H
#define SRCDIS_H

#include <SDL2/SDL.h>

typedef struct SrcDis{
    SDL_Surface* surface;
    SDL_Texture* texture;
    
    SDL_Rect src;
    SDL_Rect dest;
}SrcDis;

#endif