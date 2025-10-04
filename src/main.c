#include <stdio.h>
#include <stdbool.h>

#include "gameE.h"
// gcc -c gameE.c -o gameE.o -IC:/msys64/ucrt64/include/SDL2
#include "textures.h"
#include "text.h"
#include "config.h"
// now compiles: 
        //  gcc main.o gameE.o -o main.exe 
        //  -LC:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
        //-lSDL2_ttf

int main(int argc, char *argv[]){
    Game game;
    Sprite jimmy;
    game.sprite = &jimmy;
    
    initSDL(&game);
    
    loadtexture(game.sprite,&game,"",0,0,10,10);

    handleEvents(&game);

    close(&game);
}
