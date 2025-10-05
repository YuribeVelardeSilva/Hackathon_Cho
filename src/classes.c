#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct Stats{
    // properties
    int crew;
    int exercise;
    int social;
    int capas;
    int hygiene;
    int meal;
    int health; 
    int fuel;
    int sleep;
}Stats;

typedef struct Nivel{
    Stats stats;
    Sprite* sprite;
   
}Nivel;

typedef struct Player{
    Nivel nivel;
    fondo* fondo;
    
}Player;



