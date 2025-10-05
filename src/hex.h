#ifndef HEX_H
#define HEX_H

#include "gameE.h"
#include <math.h>

void generateHexLowerCenterWithTriangles(Game* game, float length, Suelo* suelo);

void mapRectToHexTriangle(Game* game,SDL_Rect rect,
                           float* verticesX, float* verticesY,
                           float centerX, float centerY);

bool pointInTriangle(float px, float py,
                     float ax, float ay,
                     float bx, float by,
                     float cx, float cy);

double turnRadian(int angulo);

#endif
