#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
struct VELOCITY {
    double x;
    double y;
};
#include "SDL2/SDL.h"
class Player {
public:
    Player(int x, int y);
    void walkingEvent(SDL_Event& event);
    void update(int SCREEN_WIDTH, int SCREEN_HEIGHT, double dt);
    void render(SDL_Renderer* renderer);
    SDL_Rect mRect;
private:
    VELOCITY mVelocity;
};

#endif //MYGAME_PLAYER_H
