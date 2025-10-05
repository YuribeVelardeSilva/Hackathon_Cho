#ifndef TEXT_H
#define TEXT_H

#include "gameE.h"
#include <SDL2/SDL_ttf.h>
#include <string.h>

typedef struct Game Game;

typedef struct Texto{
    TTF_Font* font;
    SDL_Color color;
    char str_buffer[60];
    char* msg;

    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    SDL_Rect background;
    SDL_Color fill;
}Texto;

int init_TTF(Texto* texto, char* filepath);

int load_texto(Game* game, Texto* texto, int x, int y, int h);

int render_texto(Game* game, Texto* texto);

void destroyFont(TTF_Font* font);

#endif