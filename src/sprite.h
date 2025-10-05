#ifndef SPRITE_H
#define SPRITE_H

#include "gameE.h"
#include "text.h"
#include "srcdis.h"

typedef struct Game Game;

typedef struct Vector2D{
    int posX;
    int posY;
}Vector2D;

typedef struct Astronaut{
    // init resources
    char* nombre;
    // properties
    SrcDis props;
    Vector2D ubi;

    SDL_Rect colision;    
}Astronaut;

typedef struct Suelo {
    SrcDis props;
    float verticesX[7];
    float verticesY[7];
    float centerX;
    float centerY;
} Suelo;

typedef struct Module{
    // init resources
    SrcDis* props;
    // properties
    int plantas;
    float volume;
    Suelo suelo;
    char* name;

}Module;

void displayAstronaut(Game* game, Astronaut* astronaut);

void updateRectAstro(Game* game, Astronaut* astronaut);

void move_sprite(Game* game, Astronaut* astronaut, int SPEED);

void renderRectAstro(Game* game, Astronaut* astronaut);

void loadFondo(Game* juego);

void renderFondo(Game*juego);

#endif