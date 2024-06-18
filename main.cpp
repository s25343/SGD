#include <SDL.h>
#include <stdio.h>
#include "Player.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main(int argc, char** argv){
    Player player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    double dt = 1/60.0;
    double gameTime = 0;
    Uint32 lastTime = SDL_GetTicks();

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(!window){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    bool running = true;
    while(running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;

                default:
                    player.walkingEvent(event);
                    break;
            }
        }
        Uint32 currentTime = SDL_GetTicks();
        lastTime = currentTime;
        gameTime += dt;
        Uint32 deltaTime = currentTime - lastTime;

        player.update(SCREEN_WIDTH, SCREEN_HEIGHT, dt);
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderClear(renderer);
        player.render(renderer);
        SDL_RenderPresent(renderer);

        if (deltaTime < 1000/60) {
            SDL_Delay((1000/60) - deltaTime);
        }

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}