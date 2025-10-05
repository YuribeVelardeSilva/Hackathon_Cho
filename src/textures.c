#include "textures.h"
#include "gameE.h"

void loadtexture(SrcDis* dis,Game* game,
    char* filepath,int posX,int posY,int width,int height){
    dis->surface = IMG_Load(filepath);
    if(!dis->surface) printf("Surface null %s\n",IMG_GetError());

    dis->texture = SDL_CreateTextureFromSurface(game->render,dis->surface);
    if(!dis->texture) printf("Texture null %s\n",SDL_GetError());
    dis->src.x = posX;
    dis->src.y = posY;
    dis->src.w = width;
    dis->src.h = height;

    SDL_FreeSurface(dis->surface);
}   

void setSpriteSize(SrcDis* dis, int w,int h,int x,int y){
    dis->dest.w = w;
    dis->dest.h = h;
    dis->dest.x = x;
    dis->dest.y = y;
}

void renderTexture(Game* game, SrcDis* dis){
    if(SDL_RenderCopy(game->render,dis->texture,&dis->src,&dis->dest)!=0) printf("Nothing to copy\n");
}

void destroyTexture(SrcDis* dis){
    SDL_DestroyTexture(dis->texture);
}

// init frames w,h,x,y and their final size
void loadFondo(Game* juego){
    juego->fondo->props.surface = IMG_Load("assets/pav_earth_frames.png");  
    printf("Renderer: %p\n", juego->render);
    if(!juego->fondo->props.surface){
        printf("error loading image SDL: %s\n", SDL_GetError());
    }      
    juego->fondo->props.texture = SDL_CreateTextureFromSurface(juego->render,juego->fondo->props.surface);
    if(!juego->fondo->props.texture){
        printf("Error cargando fondo\n");
    }
    SDL_FreeSurface(juego->fondo->props.surface);
    
    //crop each frame to their source rect
    // Since h and w are constant
    // These are calculated for 12 frames
    int x,y;
    for(int i=0; i<12; i++){
        juego->f_tierra[i].rect.h = 70;
        juego->f_tierra[i].rect.w = 127-58;
        if( i < 3) y = 0;
        else if( i < 6) y = 105;
        else if( i < 9) y = 219;
        else y = 330;
        if ( i == 0 || i == 3 || i == 6 || i == 9 ) x = 58;
        else if ( i == 1 || i == 4 || i == 7 || i == 10 ) x = 170;
        else x = 283;
        juego->f_tierra[i].rect.x = x-30;
        juego->f_tierra[i].rect.y = y;
    }
}

void renderFondo(Game*juego){
    // Present background at frame 0;
    if(SDL_RenderCopy(juego->render, juego->fondo->props.texture, &juego->f_tierra[juego->frame_counter].rect, NULL)!=0){  
        printf("error renering copied rectangle: %s\n", SDL_GetError());
    }
    // Print a report once per second
    juego->current_time = SDL_GetTicks();
    if (juego->current_time > juego->last_time + 1000) { // wait x seconds to change frame
        printf("Current frame: %i\n",juego->frame_counter);
        juego->last_time = juego->current_time;
        if(juego->frame_counter<11) juego->frame_counter++; // reset to frame 0
        else juego->frame_counter=0;
    }
}