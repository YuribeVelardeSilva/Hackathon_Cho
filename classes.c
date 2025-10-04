#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct Game Game;
typedef struct Mouse Mouse;
typedef struct Sprite Sprite;
typedef struct GameState GameState;
typedef struct Vector2D;

typedef struct Mouse{
    int posm_x;
    int posm_y;
    int bpress;
}Mouse;

typedef struct Vector2D{
    int posX;
    int posY;
}Vector2D;

typedef struct Sprite{
    // init resources
    SDL_Surface* surface;
    SDL_Texture* texture;
    
    // display
    SDL_Rect src;
    SDL_Rect dest;
    
    // properties
    Vector2D ubi;
}Sprite;

typedef struct Player{
    // init resources
    SDL_Surface* surface;
    SDL_Texture* texture;
    
    // display
    SDL_Rect src;
    SDL_Rect dest;
    
    // properties

}Sprite;

typedef struct GameState{
    void (*handle_events)(struct Game*);
    int (*update)(struct Game*);
    int (*render)(struct Game*);
}GameState;

typedef struct Game{
    SDL_Renderer* render;
    SDL_Window* ventana;
    SDL_Event e;
    
    Mouse mouse;
    
    int running;
    int stateFlag;
    
    const Uint8* pkeys;

    // Game playState structs
    Sprite* sprite;

    // Game pauseState struct

    GameState* current_state;
    GameState* gamestates;
}Game;


