#ifndef STATS_H
#define STATS_H

#include "gameE.h"
#include "text.h"

typedef struct UI UI;

typedef struct Stats{
    //int crew;
    int exercise;
    //int social;
    //int capas;
    int hygiene;
    //int meal;
    //int health; 
    int fuel;
    int sleep;
    int timerMission;
    int stress;
}Stats;

int timer();

void functionsStats(Stats* stats);

void initStats(Stats* stats);

void update_UI(Game* game, UI* ui, Stats* stats);

void init_UI(Game* game, UI* ui);

void render_UI(Game* game, UI* ui);

#endif