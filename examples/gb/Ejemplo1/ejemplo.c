// C:\gbdk-win\gbdk\examples\gb\Ejemplo1>compile.bat

#include <gb/gb.h>
#include <stdio.h>
#include "Tile1.c"
#include "Tile2.c"

struct Objeto {
    UBYTE spritids[4];
    UINT8 x, y;
};

unsigned char plx, ply;
struct Objeto jugador;

void moverObjeto(struct Objeto* obj, UINT8 x, UINT8 y) {
    move_sprite(obj->spritids[0], x, y);
    move_sprite(obj->spritids[1], x + 8, y);
    move_sprite(obj->spritids[2], x, y + 8);
    move_sprite(obj->spritids[3], x + 8, y + 8);
}

void setupJugador() {
    jugador.x = plx;
    jugador.y = ply;

    set_sprite_tile(1,1);
    jugador.spritids[0] = 1;

    set_sprite_tile(2,2);
    jugador.spritids[1] = 2;

    set_sprite_tile(3,3);
    jugador.spritids[2] = 3;

    set_sprite_tile(4,4);
    jugador.spritids[3] = 4;
}

void main() {
    printf("Hello, Game Boy!\n");
    plx = 16;
    ply = 16;

    set_sprite_data(0, 14, TileLabel2);
    set_sprite_tile(0, 0);

    SHOW_SPRITES;

    setupJugador();

    while(1) {

        jugador.x = plx;
        jugador.y = ply;    

        if (joypad() & J_LEFT) {
            --plx;  
        }
        if (joypad() & J_RIGHT) {
            ++plx;
        }
        if (joypad() & J_UP) {
            --ply;
        }
        if (joypad() & J_DOWN) {
            ++ply;
        }

        moverObjeto(&jugador, plx, ply);
        delay(10);
    }

}