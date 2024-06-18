#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
struct VELOCITY {
    double x;
    double y;
};
#include "SDL2/SDL.h"
#include "Tile.h"
#include "Points.h"

class Player {
public:
    Player(int x, int y);
    void walkingEvent(SDL_Event& event);
    void update(int SCREEN_WIDTH, int SCREEN_HEIGHT, double dt, const std::vector<Tile>& tiles, std::vector<Points>& pointss);
    void render(SDL_Renderer* renderer);
    SDL_Rect mRect;
    void checkCollisionWithPoints(std::vector<Points>& pointss);
    bool checkCollision1(SDL_Rect tileRect);

private:
    VELOCITY mVelocity;

};

#endif //MYGAME_PLAYER_H
