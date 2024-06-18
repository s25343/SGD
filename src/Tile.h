#ifndef MYGAME_TILE_H
#define MYGAME_TILE_H
#include "SDL.h"

class Tile{
public:
    SDL_Rect mRect;
    Tile(int x, int y);

    void render(SDL_Renderer* renderer);

    bool checkCollision(SDL_Rect playerRect);
};
#endif //MYGAME_TILE_H
