#include "sprite.h"

void displayAstronaut(Game* game, Astronaut* astronaut){
    // Rect from astronaut
        // get coords from rect from astronaut and setup collision rect
    astronaut->colision.h = 1; // dy
    astronaut->colision.w = astronaut->props.dest.w/4; // dx
    astronaut->colision.x = astronaut->props.dest.w;
    astronaut->colision.y = astronaut->props.dest.y;
}

void updateRectAstro(Game* game, Astronaut* astronaut){
    astronaut->colision.x = astronaut->props.dest.x + astronaut->props.dest.w/2;
    astronaut->colision.y = astronaut->props.dest.h + astronaut->props.dest.y - astronaut->colision.h;
}

void renderRectAstro(Game* game, Astronaut* astronaut){
    if(SDL_SetRenderDrawColor(game->render, 100,100,100,255)!=0)
        printf("Failed to fill rect\n");
    if(SDL_RenderFillRect(game->render, &astronaut->colision)!=0) 
        printf("Failed to fill rect\n");
}

void move_sprite(Game* game, Astronaut* astronaut, int SPEED){
    if(astronaut->props.dest.x < W_Width/2 + 200 
    && astronaut->props.dest.x > W_Width/2 - 200){
        if (game->keyboard.pkeys[SDL_SCANCODE_UP]) astronaut->props.dest.y  -= SPEED/60;
        if (game->keyboard.pkeys[SDL_SCANCODE_DOWN]) astronaut->props.dest.y += SPEED/60;
        if (game->keyboard.pkeys[SDL_SCANCODE_LEFT]) astronaut->props.dest.x -= SPEED/60;
        if (game->keyboard.pkeys[SDL_SCANCODE_RIGHT]) astronaut->props.dest.x += SPEED/60;
    }
    else{
        astronaut->props.dest.x = W_Width/2;
    }
    SDL_Delay(1000/60);
}

