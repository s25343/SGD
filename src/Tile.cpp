#include "Tile.h"
Tile::Tile(int x, int y){
    mRect.x = x;
    mRect.y = y;
    mRect.w = 50;
    mRect.h = 50;
}
void Tile::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 64, 125, 175, 1);
    SDL_RenderFillRect(renderer, &mRect);
}

bool Tile::checkCollision(SDL_Rect playerRect) {
    if(SDL_HasIntersection(&playerRect, &mRect)){
        return true;
    }
    return false;
}
