#ifndef STATS_H
#define STATS_H 
 
#include <SDL2/SDL.h>

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
    
    Uint32 last_meal_time;
    
}Stats;

void initStats(Stats* stats);
void updateMealConsumptionSDL(Stats* stats);

 #endif