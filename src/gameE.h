#ifndef GAMEE_H
#define GAMEE_H

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "config.h"
#include "textures.h"
#include "text.h"
#include "stats.h"

typedef struct Sprite Sprite;
typedef struct Game Game;
typedef struct Fondo Fondo;
typedef struct Texto Texto;

typedef struct UI{
    Texto* textboxes;
}UI;

typedef struct Mouse{
    int posm_x;
    int posm_y;
    int bpress;
}Mouse;

typedef struct Keyboard{
    const Uint8* pkeys;
}Keyboard;

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
    int triangleNum;

    UI ui;

    Fondo* fondo;
    Fondo* f_tierra;
    int frame_counter;
    int current_time;
    int last_time;

    Mouse mouse;
    Keyboard keyboard;

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


