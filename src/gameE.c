
#include "gameE.h"
#include "text.h"
#include "textures.h"

int initSDL(Game* game){
    Uint32 systemFlags = SDL_INIT_VIDEO;
    if(SDL_Init(systemFlags)!=0) printf("Failed init\n");
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) & (IMG_INIT_JPG | IMG_INIT_PNG);

    game->window = SDL_CreateWindow("{colisiones}", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_Width, W_Height, 0);
    if(!game->window) printf("Window failed %s\n", SDL_GetError());
    
    game->render = NULL;
    game->render = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if(!game->render)printf("Render is null %s\n",SDL_GetError());

    game->gameRunning = 1;
    return 0;
}

void handleEvents(Game* game){
    while(game->gameRunning==1){
        while(SDL_PollEvent(&game->event)){
            if(game->event.type == SDL_QUIT) game->gameRunning = 0;
        }
        SDL_SetRenderDrawColor(game->render, 255,255,255,255);
        SDL_RenderClear(game->render);

        renderTexture(game, game->sprite);

        SDL_RenderPresent(game->render);
    }
}

void close(Game* game){
    SDL_Quit();
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->render);
}