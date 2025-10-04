#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct Game Game;
typedef struct Mouse Mouse;
typedef struct Sprite Sprite;
typedef struct GameState GameState;
typedef struct Vector2D;

typedef struct Vector2D{
    int posX;
    int posY;
}Vector2D;

typedef struct Astronaut{
    // init resources
    char* nombre;
    SDL_Surface* surface;
    SDL_Texture* texture;
    
    // display
    SDL_Rect src;
    SDL_Rect dest;
    
    // properties
    Vector2D ubi;
    char* name;
}Astronaut;

typedef struct Suelo{
    // init resources
    SDL_Surface* surface;
    SDL_Texture* texture;
    
    // display
    SDL_Rect src;
    SDL_Rect dest;
    
    // properties
   
}Suelo;

typedef struct Module{
    // init resources
    SDL_Surface* surface;
    SDL_Texture* texture;
    
    // display
    SDL_Rect src;
    SDL_Rect dest;
    
    // properties
   int plantas;
   float area;
   float volume;
   Suelo suelo;
   char* name;

   
}Module;

typedef struct fondo{
    // init resources
    SDL_Surface* surface;
    SDL_Texture* texture;
    
    // display
    SDL_Rect src;
    SDL_Rect dest;
}fondo;

typedef struct Stats{
    // properties
    int crew;
    int exercise;
    int social;
    int capas;
    int hygiene;
    int meal;
    int health; 
    int fuel;
    int sleep;
    

    
}Stats;

typedef struct Nivel{
    Stats stats;
    Sprite* sprite;
   
}Nivel;



typedef struct Sprite{
    Astronaut* astronauta;
    Suelo* suelo;
    Module* module;
    
}Sprite;

typedef struct Player{
    Nivel nivel;
    Stats stats;
    Sprite* sprite;
    fondo* fondo;
    
}Player;

typedef struct Keyboard{
    const Uint8* pkeys;
}Keyboard;

typedef struct Mouse{
    int posm_x;
    int posm_y;
    int bpress;
}Mouse;

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


