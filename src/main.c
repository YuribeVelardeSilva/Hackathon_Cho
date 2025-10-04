#include <stdio.h>
#include <stdbool.h>

#include "gameE.h"
// gcc -c src/gameE.c -o src/gameE.o -IC:/msys64/mingw64/include/SDL2
#include "textures.h"
// gcc -c src/textures.c -o src/textures.o -IC:/msys64/mingw64/include/SDL2
#include "text.h"
// gcc -c src/text.c -o src/text.o -IC:/msys64/mingw64/include/SDL2
#include "config.h"
// now compiles: 
        //  gcc main.o gameE.o -o main.exe 
        //  -LC:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
        //-lSDL2_ttf

void handleEvents(Game* game);
void render(Game* game);

int main(int argc, char *argv[]){
    Game game;
    Sprite jimmy;
    game.sprite = &jimmy;
    Texto hola = {.msg = "PruebaS"};

    GameState initState = { 
        .handle_events = handleEvents,
        .update = NULL,
        .render = render
    };
    
    GameState gamestates[] = {initState};

    game.current_state = &initState;
    game.gamestates = gamestates;

    //-------------------------------------------------//
    
    initSDL(&game);
    init_TTF(&hola, "assets/calibri.ttf");
    
    load_texto(&game, &hola, 0,0,200);
    loadtexture(game.sprite,&game,"assets/Astro.jfif",0,0,200,200);

    setSpriteSize(game.sprite, 200,200,0,0);

    // gameloop
    while(game.gameRunning==1){
    SDL_SetRenderDrawColor(game.render, 255,255,255,255);
    SDL_RenderClear(game.render);
    game.current_state->handle_events(&game);
    //game.current_state->update(&game);
    game.current_state->render(&game);
    
    render_texto(&game,&hola);

    SDL_RenderPresent(game.render);
    }
    close(&game);
    destroyFont(hola.font);
}

void handleEvents(Game* game){
    while(SDL_PollEvent(&game->event)){
        if(game->event.type == SDL_QUIT) game->gameRunning = 0;
    }
}

void render(Game* game){

    renderTexture(game, game->sprite);
}