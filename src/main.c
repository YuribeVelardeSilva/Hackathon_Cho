#include <stdio.h>
#include <stdbool.h>

#include "stats.h"


// gcc -c src/main.c -o src/main.o -IC:/msys64/mingw64/include/SDL2
#include "gameE.h"
// gcc -c src/gameE.c -o src/gameE.o -IC:/msys64/mingw64/include/SDL2
#include "textures.h"
// gcc -c src/textures.c -o src/textures.o -IC:/msys64/mingw64/include/SDL2
#include "text.h"
// gcc -c src/text.c -o src/text.o -IC:/msys64/mingw64/include/SDL2
#include "sprite.h"
// gcc -c src/sprite.c -o src/sprite.o -IC:/msys64/mingw64/include/SDL2
#include "config.h"
// now compiles: 
        //  gcc src/main.o src/gameE.o src/textures.o src/sprite.o src/text.o -o main.exe 
        //  -LC:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
        //-lSDL2_ttf

#define DEBUG
#define NULL

void handleEvents(Game* game);
void render(Game* game);
void update(Game* game);



int main(int argc, char *argv[]){
    #ifdef DEBUG
        printf("Program started\n");
    #endif
    /*Game game = {0};
    Astronaut jimmy;
    Sprite spr_obj = {0};
    Fondo fondo = {0};
    Fondo frames[12] = {0};*/

    Game game = {0};
    initStats(&game.stats); 
    updateMealConsumptionSDL(&game.stats);

    /*game.sprite = &spr_obj;
    game.fondo = &fondo;
    game.f_tierra = frames;
    game.sprite->astronauta = &jimmy;
     
    Texto hola = {.msg = "PruebaS"};*/

    #ifdef DEBUG
        printf("Sprites and Game stated\n");
    #endif
    GameState initState = { 
        .handle_events = handleEvents,
        .update = update,
        .render = render
    };
    
    GameState gamestates[] = {initState};

    game.current_state = &initState;
    game.gamestates = gamestates;
    //-------------------------------------------------//
    
    initSDL(&game);
    #ifdef DEBUG
        printf("initSDL ended\n");
    #endif
    #ifdef NULL
    #else
        init_TTF(&hola, "assets/calibri.ttf");
        load_texto(&game, &hola, 0,0,200);
        loadtexture(&game.sprite->astronauta->props,&game,"assets/Astro.jfif",0,0,200,200);
        loadFondo(&game);
        #ifdef DEBUG
            printf("loaded textures and text\n");
        #endif
        setSpriteSize(&game.sprite->astronauta->props, 200,200,0,0);
        displayAstronaut(&game, game.sprite->astronauta);
        printf("Display set\n");
    #endif

    // gameloop
    while(game.gameRunning==1){
    //SDL_SetRenderDrawColor(game.render, 255,255,255,255);
    SDL_RenderClear(game.render);
    game.current_state->handle_events(&game);   

    game.current_state->update(&game);
    
    game.current_state->render(&game);
    render_texto(&game,&hola);

    SDL_RenderPresent(game.render);
    }
    // end loop
    close(&game);
    destroyFont(hola.font);
    destroyTexture(&game.sprite->astronauta->props);
}
//---------------------------------------------------------- FUNCTION POINTERS -----//
void handleEvents(Game* game){
    while(SDL_PollEvent(&game->event)){
        game->keyboard.pkeys=SDL_GetKeyboardState(NULL);
        if(game->event.type == SDL_QUIT) game->gameRunning = 0;
    }
    move_sprite(game, game->sprite->astronauta, 250);
}

void update(Game* game){
    updateRectAstro(game,game->sprite->astronauta);
}

void render(Game* game){
    renderFondo(game);
    renderTexture(game, &game->sprite->astronauta->props);
    renderRectAstro(game, game->sprite->astronauta);
}
//---------------------------------------------------------- FUNCTION POINTERS LEVEL 0 -----//
void handleLevelNull(Game* game){
    while(SDL_PollEvent(&game->event)){
        game->keyboard.pkeys=SDL_GetKeyboardState(NULL);
        if(game->event.type == SDL_QUIT) game->gameRunning = 0;
    }
    move_sprite(game, game->sprite->astronauta, 250);
}

void updateLevelNull(Game* game){
    updateRectAstro(game,game->sprite->astronauta);
}

void renderLevelNull(Game* game){
    renderFondo(game);
    renderTexture(game, &game->sprite->astronauta->props);
    renderRectAstro(game, game->sprite->astronauta);
}