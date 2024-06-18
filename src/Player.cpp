#include "Player.h"
#include "SDL2/SDL.h"
#include "Tile.h"
#include "Points.h"
#include <cmath>
#include <iostream>

Player::Player(int x, int y) {
    mRect.x = x;
    mRect.y =y;
    mRect.w = 20;
    mRect.h = 20;
    mVelocity.x = 0;
    mVelocity.y = 0;
}

void Player::walkingEvent(SDL_Event &event) {
    switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_A:
            mVelocity.x = -1;
            break;
        case SDL_SCANCODE_D:
            mVelocity.x = 1;
            break;
        case SDL_SCANCODE_S:
            mVelocity.y = 1;
            break;
        case SDL_SCANCODE_W:
            mVelocity.y = -1;
            break;
    }
}

void Player::update(int SCREEN_WIDTH, int SCREEN_HEIGHT, double dt, const std::vector<Tile>& tiles, std::vector<Points>& pointss) {
    int old_x = mRect.x;
    int old_y = mRect.y;
    mRect.x += mVelocity.x * 125 * dt;
    mRect.y += mVelocity.y * 125 * dt;

    const double friction = 0.05;
    if(fabs(mVelocity.x)>0.1){
        mVelocity.x *= 1.0 - friction;
    }
    else{
        mVelocity.x = 0;
    }
    if(fabs(mVelocity.y)>0.1){
        mVelocity.y *= 1.0 - friction;
    }
    else{
        mVelocity.y = 0;
    }
    for (const auto& tile : tiles) {
        if (SDL_HasIntersection(&mRect, &tile.mRect)) {
            mRect.x = old_x;
            mRect.y = old_y;
        }
    }
}

void Player::checkCollisionWithPoints(std::vector<Points>& pointss){
    std::cout << "called" << std::endl;
    for (auto& point : pointss) {
        if (SDL_HasIntersection(&mRect, &point.mRect)) {
            point = pointss.back();
            pointss.pop_back();
            break;
        }
    }
}
bool Player::checkCollision1(SDL_Rect tileRect) {
    if(SDL_HasIntersection(&tileRect, &mRect)){
        return true;
    }
    return false;
}


void Player::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 236, 21, 59, 1);
    SDL_RenderFillRect(renderer, &mRect);
}
