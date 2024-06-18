#include "Points.h"

Points::Points(int x, int y) {
    mRect.x = x;
    mRect.y = y;
    mRect.w = 10;
    mRect.h = 10;

}
void Points::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 248, 182, 68, 1);
    SDL_RenderFillRect(renderer, &mRect);
}