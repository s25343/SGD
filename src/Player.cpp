#include "Player.h"
#include "SDL2/SDL.h"
#include <cmath>
#include <iostream>

Player::Player(int x, int y) {
    mRect.x = x;
    mRect.y =y;
    mRect.w = 40;
    mRect.h = 60;
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

void Player::update(int SCREEN_WIDTH, int SCREEN_HEIGHT, double dt) {
    std::cout << "Kaka";
    mRect.x += mVelocity.x * 200 * dt;
    mRect.y += mVelocity.y * 200 * dt;

    int old_x = mRect.x;
    int old_y = mRect.y;

    if(mRect.x < 0 || mRect.y < 0 || mRect.x + mRect.w > SCREEN_WIDTH || mRect.y + mRect.h > SCREEN_HEIGHT){
        mRect.x = old_x;
        mRect.y = old_y;
    }

    const double friction = 0.03;
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
}

void Player::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &mRect);
}
