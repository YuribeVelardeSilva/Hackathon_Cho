#include <stdio.h>
#include <stdbool.h>

#include "stats.h"

void initStats(Stats* stats) {
    stats->crew = 0;
    stats->meal = 100;  // Comida inicial
    stats->last_meal_time = time(NULL);
}


void updateMealConsumptionSDL(Stats* stats) {
    Uint32 current_ticks = SDL_GetTicks();
    
    if (current_ticks - stats->last_meal_time >= 1000) {  // 1000 ms = 1 segundo
        stats->meal -= 1;
        
        if (stats->meal < 0) stats->meal = 0;
        
        stats->last_meal_time = current_ticks;
        printf("Comida: %d\n", stats->meal);
    }
}