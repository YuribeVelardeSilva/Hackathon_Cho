#ifndef GAMEE_H
#define GAMEE_H

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "config.h"
#include "textures.h"

typedef struct Sprite Sprite;

typedef struct Game Game;

typedef struct GameState{
    void (*handle_events)(struct Game*);
    void (*update)(struct Game*);
    void (*render)(struct Game*);
}GameState;

typedef struct Game{
    SDL_Renderer* render;
    SDL_Window* window;

    SDL_Event event;
    int gameRunning;

    Sprite* sprite;

    GameState* current_state;
    GameState* gamestates;
}Game;


int initSDL(Game* game);

void close(Game* game);
/* Void close has currently:
    SDL_Quit();
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->render);
*/



#endif