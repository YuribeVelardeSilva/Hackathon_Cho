#include "hex.h"

void generateHexLowerCenterWithTriangles(Game* game, float length, Suelo* suelo) {
    float verticesX[7];
    float verticesY[7];

    float originX = W_Width / 2.0f;
    float originY = W_Height - 200.0f; // adjust so it's visible

    // angles for flat-topped hexagon (degrees)
    float angles[6] = { 0, 60, 120, 180, 240, 300 };

    // generate hexagon vertices
    for (int i = 0; i < 6; i++) {
        float rad = turnRadian(angles[i]);
        verticesX[i] = originX + length * cos(rad);
        verticesY[i] = originY + length * sin(rad);
    }
    // close shape
    verticesX[6] = verticesX[0];
    verticesY[6] = verticesY[0];

    for (int i = 0; i < 7; i++) {
    suelo->verticesX[i] = verticesX[i];
    suelo->verticesY[i] = verticesY[i];
    }

    suelo->centerX = originX;
    suelo->centerY = originY;

    // Draw hexagon edges
    SDL_SetRenderDrawColor(game->render, 0, 0, 0, 0);
    for (int i = 0; i < 6; i++) {
        SDL_RenderDrawLineF(game->render,
            verticesX[i], verticesY[i],
            verticesX[i+1], verticesY[i+1]);
    }

    // Draw triangles inside hexagon
    for (int i = 0; i < 6; i++) {
        // center → vertex[i] → vertex[i+1]
        SDL_RenderDrawLineF(game->render,
            originX, originY,
            verticesX[i], verticesY[i]);
        SDL_RenderDrawLineF(game->render,
            originX, originY,
            verticesX[i+1], verticesY[i+1]);
    }
}

bool pointInTriangle(float px, float py,
                     float ax, float ay,
                     float bx, float by,
                     float cx, float cy) {
    float v0x = cx - ax;
    float v0y = cy - ay;
    float v1x = bx - ax;
    float v1y = by - ay;
    float v2x = px - ax;
    float v2y = py - ay;

    float dot00 = v0x*v0x + v0y*v0y;
    float dot01 = v0x*v1x + v0y*v1y;
    float dot02 = v0x*v2x + v0y*v2y;
    float dot11 = v1x*v1x + v1y*v1y;
    float dot12 = v1x*v2x + v1y*v2y;

    float invDenom = 1.0f / (dot00*dot11 - dot01*dot01);
    float u = (dot11*dot02 - dot01*dot12) * invDenom;
    float v = (dot00*dot12 - dot01*dot02) * invDenom;

    return (u >= 0) && (v >= 0) && (u + v <= 1);
}

void mapRectToHexTriangle(Game* game, SDL_Rect rect,
                           float* verticesX, float* verticesY,
                           float centerX, float centerY) {
    float px = rect.x + rect.w/2.0f; // rect center
    float py = rect.y + rect.h/2.0f;
                            
    for (int i = 0; i < 6; i++){
        if (pointInTriangle(px, py,
                            centerX, centerY,
                            verticesX[i], verticesY[i],
                            verticesX[i+1], verticesY[i+1])) {
            game->triangleNum = i+1;
        }
        else 
            game->triangleNum = 0;
    }
}

double turnRadian(int angulo){
    return (angulo*PI)/180.0f;
}
