#include "text.h"

int init_TTF(Texto* texto, char* filepath){
    //this opens a font style and sets a size
    texto->font = TTF_OpenFont(filepath, 32);
    if (!texto->font){
        printf("Error opening font: %s\n", TTF_GetError());
        return 1;
    }
    return 0;
}

int load_texto(Game* game, Texto* texto, int x, int y, int h){
// Elegimos el color del texto
    // or do MapRGB()
    texto->color.a = 0;
    texto->color.b = 0;
    texto->color.g = 0;
    texto->color.r = 0; // Negro

    //Count letters
    size_t length = strlen(texto->msg);
    printf("Characters: %zu\n", length);

    //length per character 
    int charW = h/4;
    //if(sprintf(texto->str_num, "%d", 10)<0) 
    //    printf("Failed concatenating strings\n"); 
    strcpy(texto->str_buffer, texto->msg);
    //strcat(texto->str_buffer,texto->str_num);

    texto->surface = TTF_RenderText_Solid(texto->font, texto->str_buffer, texto->color);
    if(!texto->surface) return 1;

    texto->texture = SDL_CreateTextureFromSurface(game->render, texto->surface);
    if(!texto->texture) return 1;
    
    SDL_FreeSurface(texto->surface);

    //Añadimos el rectángulo sobre el que se va a mostrar el texto
    texto->rect.h = h;
    texto->rect.w = length*charW;
    texto->rect.x = x;
    texto->rect.y = y;

    texto->background.h = texto->rect.h;
    texto->background.w = texto->rect.w;
    texto->background.x = texto->rect.x;
    texto->background.y = texto->rect.y;
    return 0;
}

int render_texto(Game* game, Texto* texto){
    if(SDL_RenderCopy(game->render, texto->texture,NULL, &texto->rect)!=0)  
        return 1;
    return 0;
}

void destroyFont(TTF_Font* font){
    TTF_CloseFont(font);
}