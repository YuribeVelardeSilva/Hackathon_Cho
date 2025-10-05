#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct Nivel{
    Stats stats;
    Sprite* sprite;
   
}Nivel;

typedef struct Player{
    Nivel nivel;
    fondo* fondo;
    
}Player;



