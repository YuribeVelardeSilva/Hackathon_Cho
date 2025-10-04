#include "textures.h"
#include "gameE.h"

void loadtexture(Sprite* sprite,Game* game,
    char* filepath,int posX,int posY,int width,int height){
    
    sprite->surface = IMG_Load(filepath);
    if(!sprite->surface) printf("Surface null %s\n",IMG_GetError());

    sprite->texture = SDL_CreateTextureFromSurface(game->render,sprite->surface);
    if(!sprite->texture) printf("Texture null %s\n",SDL_GetError());
    sprite->src.x = posX;
    sprite->src.y = posY;
    sprite->src.w = width;
    sprite->src.h = height;

    SDL_FreeSurface(sprite->surface);
}   

void setSpriteSize(Sprite* sprite, int w,int h,int x,int y){
    sprite->dest.w = w;
    sprite->dest.h = h;
    sprite->dest.x = x;
    sprite->dest.y = y;
}

void renderTexture(Game* game, Sprite* sprite){
    if(SDL_RenderCopy(game->render,sprite->texture,&sprite->src,&sprite->dest)!=0) printf("Nothing to copy\n");
}