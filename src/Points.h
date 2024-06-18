#ifndef MYGAME_POINTS_H
#define MYGAME_POINTS_H
#include "SDL.h"

class Points{
public:
    Points(int x, int y);
    SDL_Rect mRect;
    void render(SDL_Renderer* renderer);
};
#endif //MYGAME_POINTS_H
