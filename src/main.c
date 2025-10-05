#include <stdio.h>
#include <stdbool.h>

// gcc -c src/main.c -o src/main.o -IC:/msys64/mingw64/include/SDL2
#include "gameE.h"
// gcc -c src/gameE.c -o src/gameE.o -IC:/msys64/mingw64/include/SDL2
#include "textures.h"
// gcc -c src/textures.c -o src/textures.o -IC:/msys64/mingw64/include/SDL2
#include "text.h"
// gcc -c src/text.c -o src/text.o -IC:/msys64/mingw64/include/SDL2
#include "sprite.h"
// gcc -c src/sprite.c -o src/sprite.o -IC:/msys64/mingw64/include/SDL2
#include "hex.h"
// gcc -c src/hex.c -o src/hex.o -IC:/msys64/mingw64/include/SDL2
#include "stats.h"
// gcc -c src/stats.c -o src/stats.o -IC:/msys64/mingw64/include/SDL2
#include "config.h"
// now compiles: 
        //  gcc src/main.o src/gameE.o src/textures.o src/sprite.o src/text.o src/hex.o src/stats.o -o main.exe 
        //  -LC:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2_gfx -lSDL2 -lSDL2_image 
        //-lSDL2_ttf 

#define DEBUG
#define NNULL

    /* Cosas por hacer
        1. Tareas
        4. Poner muebles y piso sobre hexagono
    */

void handleFloorOne(Game* game);
void renderFloorOne(Game* game);
void updateFloorOne(Game* game);

void handleFloorTwo(Game* game);
void updateFloorTwo(Game* game);
void renderFloorTwo(Game* game);

int main(int argc, char *argv[]){
    #ifdef DEBUG
        printf("Program started\n");
    #endif
    Game game = {0};
    
    Sprite spr_obj = {0};
    
    Fondo fondo = {0};
    Fondo frames[12] = {0};

    UI playerUI = {0};

    Astronaut jimmy;
    Astronaut johnson;
    Astronaut spaceCrew[] = {jimmy, johnson};
    SrcDis scenario[9];
    scenario[0].dest.x = W_Width/2;
    scenario[0].dest.y = W_Height/2;
    scenario[0].dest.h = 50;
    scenario[0].dest.w = 50;

    scenario[1].dest.x = W_Width/2;
    scenario[1].dest.y = W_Height/3;
    scenario[1].dest.h = 50;
    scenario[1].dest.w = 50;

    scenario[2].dest.x = W_Width/3;
    scenario[2].dest.y = 4*W_Height/5;
    scenario[2].dest.h = 50;
    scenario[2].dest.w = 50;
    
    scenario[3].dest.x = 2*W_Width/3;
    scenario[3].dest.y = 2*W_Height/3;
    scenario[3].dest.h = 50;
    scenario[3].dest.w = 50;
    
    scenario[4].dest.x = W_Width/3;
    scenario[4].dest.y = 2*W_Height/3;
    scenario[4].dest.h = 50;
    scenario[4].dest.w = 50;
    
    scenario[5].dest.x = W_Width/2;
    scenario[5].dest.y = 3*W_Height/5;
    scenario[5].dest.h = 50;
    scenario[5].dest.w = 50;
    
    scenario[6].dest.x = W_Width/3;
    scenario[6].dest.y = W_Height/2;
    scenario[6].dest.h = 50;
    scenario[6].dest.w = 50;
    
    scenario[7].dest.x = W_Width/2;
    scenario[7].dest.y = W_Height/3;
    scenario[7].dest.h = 50;
    scenario[7].dest.w = 50;
    
    scenario[8].dest.x = W_Width/2;
    scenario[8].dest.y = W_Height/3;
    scenario[8].dest.h = 500;
    //scenario[8].dest.w = 500;

    game.sprite = &spr_obj;
    game.fondo = &fondo;
    game.f_tierra = frames;
    spr_obj.astronauta = spaceCrew;

    GameState floorOne = { 
        .handle_events = handleFloorOne,
        .update = updateFloorOne,
        .render = renderFloorOne,
    };
    GameState floorTwo = { 
        .handle_events = handleFloorTwo,
        .update = updateFloorTwo,
        .render = renderFloorTwo
    };
    
    GameState gamestates[] = {floorOne, floorTwo};
    
    game.current_state = &floorOne;
    game.gamestates = gamestates;
    
    Suelo suelo;
    game.sprite->suelo = &suelo;

    Fondo logo = {.props.src = {.h = 32,
                                .w = 32,
                                .x = 0,
                                .y = 0
                                }, 
    .props.dest.h = W_Height/2,
    .props.dest.w = W_Width/2,
    .props.dest.x = 180,
    .props.dest.y = 90
    }; 

    //-------------------------------------------------//
    
    initSDL(&game);
    
    // load textures for both sprites_A
    loadtexture(&game.sprite->astronauta[0].props,&game,"assets/valenauta.png",0,0,400,400);
    loadtexture(&game.sprite->astronauta[1].props,&game,"assets/valenauta.png",0,0,400,400);
    // load texture for logo
    loadtexture(&logo.props,&game,"assets/chocolate.jpeg",0,0,200,200);
    SrcDis hexagon;
    hexagon.dest.h = 500;
    hexagon.dest.w = 500;
    hexagon.dest.x = W_Width - hexagon.dest.w - 130;
    hexagon.dest.y = W_Height - hexagon.dest.h + 40;
    loadtexture(&hexagon,&game,"assets/hexaClear.png",0,0,500,500);
    // load scenario
    loadtexture(&scenario[0],&game,"assets/cama.png",0,0,69,68);
    loadtexture(&scenario[1],&game,"assets/mesa.png",0,0,67,57);
    loadtexture(&scenario[2],&game,"assets/mueble2.png",0,0,68,71);
    loadtexture(&scenario[3],&game,"assets/mueble1.png",0,0,67,68);
    loadtexture(&scenario[4],&game,"assets/mueble3.png",0,0,67,68);
    loadtexture(&scenario[5],&game,"assets/mueble4.png",0,0,55,57);
    loadtexture(&scenario[6],&game,"assets/baño.png",0,0,58,49);
    loadtexture(&scenario[7],&game,"assets/sofa.png",0,0,67,70);
    //loadtexture(&scenario[8],&game,"assets/hexaClear.png",0,0,500,500);

    //loadtexture(&scenario[0], &game, "", 0, 0, 0, 0);
    printf("Debugging\n");
    // load fondo
    loadFondo(&game);

    init_UI(&game, &playerUI);
    
    setSpriteSize(&game.sprite->astronauta[0].props, 100,100,W_Width/2,W_Height/2);
    setSpriteSize(&game.sprite->astronauta[1].props, 100,100,W_Width/2,W_Height/2);
    setSpriteSize(&game.sprite->suelo->props, 200,200,W_Width/2,W_Height/2);
    
    displayAstronaut(&game, &game.sprite->astronauta[0]);
    displayAstronaut(&game, &game.sprite->astronauta[1]);
    
    Stats playerStats = {.exercise = 100, .fuel = 100 ,.sleep = 100 ,.hygiene = 100, .stress = 0, .timerMission = 30};
    
    // intro 
    renderTexture(&game, &logo.props);
    SDL_RenderPresent(game.render);
    SDL_Delay(1000);
    printf("Go Sleep!\n");
    // gameloop
    while(game.gameRunning==1){
    game.current_state->handle_events(&game);   
    
    game.current_state->update(&game);
    functionsStats(&playerStats);
    update_UI(&game, &playerUI, &playerStats);
    SDL_SetRenderDrawColor(game.render,0,0,0,255);
    SDL_RenderClear(game.render);
    renderFondo(&game);
    renderTexture(&game, &hexagon);
    
    game.current_state->render(&game);

    //for mission go sleep
    if(game.triangleNum == 1){
        printf("Mission achieved!\n");
    }
    
    if(game.current_state == &game.gamestates[0]){
        generateHexLowerCenterWithTriangles(&game,200, &suelo);
        mapRectToHexTriangle(&game, game.sprite->astronauta[0].colision,
                            suelo.verticesX,suelo.verticesY,
                            suelo.centerX, suelo.centerY);
        renderTexture(&game, &scenario[0]);
        renderTexture(&game, &scenario[1]);
        renderTexture(&game, &scenario[3]);
        renderTexture(&game, &scenario[4]);
    }
    else if(game.current_state == &game.gamestates[1]){
        generateHexLowerCenterWithTriangles(&game,200, &suelo);
        mapRectToHexTriangle(&game, game.sprite->astronauta[1].colision,
                            suelo.verticesX,suelo.verticesY,
                            suelo.centerX, suelo.centerY);
        
        renderTexture(&game, &scenario[2]);
        renderTexture(&game, &scenario[5]);
        renderTexture(&game, &scenario[7]);
        renderTexture(&game, &scenario[6]);
                    
                        }
    if(playerStats.timerMission == 0){ // ENDING SCREEN
        SDL_SetRenderDrawColor(game.render,0,0,0,255);
        SDL_RenderClear(game.render);
        renderTexture(&game, &logo.props);
        render_UI(&game, &playerUI);
        SDL_RenderPresent(game.render);
        if(playerStats.stress > 60) printf("Won!\n");
        else printf("Lost\n");
        SDL_Delay(1000);
        game.gameRunning = 0;
    }
    render_UI(&game, &playerUI);
    SDL_RenderPresent(game.render);
    }

    // end loop
 
    close(&game);
    destroyFont(playerUI.textboxes[0].font);
    destroyFont(playerUI.textboxes[1].font);
    destroyFont(playerUI.textboxes[2].font);
    destroyFont(playerUI.textboxes[3].font);
    destroyTexture(&game.sprite->astronauta[0].props);
    destroyTexture(&game.sprite->astronauta[1].props);
}

//---------------------------------------------------------- FUNCTION POINTERS LEVEL 0 -----//
void handleFloorOne(Game* game){
    while(SDL_PollEvent(&game->event)){
        game->keyboard.pkeys=SDL_GetKeyboardState(NULL);
        if(game->event.type == SDL_QUIT) game->gameRunning = 0;
    }
    if(game->keyboard.pkeys[SDL_SCANCODE_2]){
        game->current_state = &game->gamestates[1];
    }
    if(game->keyboard.pkeys[SDL_SCANCODE_1]){
        game->current_state = &game->gamestates[0];
    }
}

void updateFloorOne(Game* game){
    move_sprite(game, &game->sprite->astronauta[0], 250);
    updateRectAstro(game,&game->sprite->astronauta[0]);
}

void renderFloorOne(Game* game){
    //renderFondo(game);
    renderTexture(game, &game->sprite->astronauta[0].props);
    renderRectAstro(game, &game->sprite->astronauta[0]);
}
//---------------------------------------------------------- FUNCTION POINTERS AT EACH LEVEL -----//
void handleFloorTwo(Game* game){
    while(SDL_PollEvent(&game->event)){
        game->keyboard.pkeys=SDL_GetKeyboardState(NULL);
        if(game->event.type == SDL_QUIT) game->gameRunning = 0;
    }
    if(game->keyboard.pkeys[SDL_SCANCODE_2]){
        game->current_state = &game->gamestates[1];
    }
    if(game->keyboard.pkeys[SDL_SCANCODE_1]){
        game->current_state = &game->gamestates[0];
    }
}

void updateFloorTwo(Game* game){
    move_sprite(game, &game->sprite->astronauta[1], 250);
    updateRectAstro(game,&game->sprite->astronauta[1]);
}

void renderFloorTwo(Game* game){
    //renderFondo(game);
    renderTexture(game, &game->sprite->astronauta[1].props);
    renderRectAstro(game, &game->sprite->astronauta[1]);
}
