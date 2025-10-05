#include "stats.h"
#include "gameE.h"

// returns 1 every second
int timer() {
    static Uint64 last_time = 0;  // stores the last printed time
    Uint64 current_time = SDL_GetTicks64();  // current time in ms

    if (current_time > last_time + 1000) {   // 1000 ms = 1 second
        printf("One second passed! Current time: %llu ms\n", current_time);
        last_time = current_time;  // reset timer
        return 1;
    }
    else
        return 0;
}

void functionsStats(Stats* stats){
    if(timer() == 1){
        stats->exercise = stats->exercise - 1;    
        stats->fuel = stats->fuel - 1;
        stats->hygiene = stats->hygiene - 1;
        stats->sleep = stats->sleep - 1;
        stats->stress = 0;
        stats->timerMission = stats->timerMission - 1;
    }
}

void initStats(Stats* stats){
    stats->exercise = 100;
    stats->fuel = 100;
    stats->hygiene = 100;
    stats->sleep = 100;
}

void init_UI(Game* game, UI* ui) {
    static Texto textboxes[6];  // 6 stats
    ui->textboxes = textboxes;
    
    const char* labels[6] = {"Fuel", "Exercise", "Hygiene", "Sleep","Stress","LTT"};
    int startY = 50;
    for (int i = 0; i < 6; i++) {
        init_TTF(&ui->textboxes[i], "assets/calibri.ttf");
        ui->textboxes[i].msg = (char*)labels[i];

        // background color (light gray)
        ui->textboxes[i].fill = (SDL_Color){200, 200, 200, 255};

        // draw text in black
        ui->textboxes[i].color = (SDL_Color){0, 0, 0, 255};

        // position each stat box              x coordenate    y coordenate     height
        if(load_texto(game, &ui->textboxes[i], 0             ,startY + i * 40, 40)!=0)
            printf("Failed loading text: %s\n", SDL_GetError());
    }
}

void render_UI(Game* game, UI* ui) {
    for (int i = 0; i < 6; i++) {
        Texto* t = &ui->textboxes[i];

        // Draw background rectangle
        SDL_SetRenderDrawColor(game->render, t->fill.r, t->fill.g, t->fill.b, t->fill.a);
        if(SDL_RenderFillRect(game->render, &t->background)!=0)
            printf("Not filled Rect\n");

        // Draw text
        if(render_texto(game, t)!=0)
            printf("Failed rendering text\n");
    }
}

void update_UI(Game* game, UI* ui, Stats* stats) {
    char buffer[64];
    const char* labels[6] = {"Fuel", "Exercise", "Hygiene", "Sleep","Stress","LTT"};
    int values[6] = {stats->fuel, stats->exercise, stats->hygiene, stats->sleep, stats->stress, stats->timerMission};

    for (int i = 0; i < 6; i++) {
        snprintf(buffer, sizeof(buffer), "%s: %d", labels[i], values[i]);
        ui->textboxes[i].msg = buffer;
        load_texto(game, &ui->textboxes[i], 
                   ui->textboxes[i].rect.x,
                   ui->textboxes[i].rect.y,
                   ui->textboxes[i].rect.h);
    }
}