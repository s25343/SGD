#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include "Player.h"
#include "Tile.h"

using namespace std;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

vector<Tile> tiles;
vector<Points> pointss;
Player player(50,50);

int map[14][25] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int count = 0;
void drawPoints(){
    pointss.clear();
    const int pointSize = 55;
    int mapPoints[14][25] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 25; j++) {
            if (mapPoints[i][j] == 1) {
                pointss.emplace_back(j * pointSize, i * pointSize);
                count++;
            }
        }
    }
}

void drawMap() {
    tiles.clear();
    const int tileSize = 50;
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 25; j++) {
            if (map[i][j] == 1) {
                tiles.emplace_back(j * tileSize, i * tileSize);
            }
        }
    }
}

//std::shared_ptr<SDL_Texture> load_image(SDL_Renderer *renderer, const std::string &file_name) {
//    SDL_Surface *surface;
//    SDL_Texture *texture;
//    surface = SDL_LoadBMP(file_name.c_str());
//    if (!surface) {
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
//        throw std::invalid_argument(SDL_GetError());
//    }
//    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format,0, 255, 255));
//    texture = SDL_CreateTextureFromSurface(renderer, surface);
//    if (!texture) {
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
//        throw std::invalid_argument(SDL_GetError());
//    }
//    SDL_FreeSurface(surface);
//    return {texture, [](SDL_Texture *t) {
//        SDL_DestroyTexture(t);
//    }};
//}

int main(int argc, char** argv){
    drawMap();
    drawPoints();
    double dt = 1/60.0;
    double gameTime = 0;
    Uint32 lastTime = SDL_GetTicks();

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Labirynt", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(!window){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

//    auto player_texture = load_image(renderer, "player.bmp");
//    auto tiles_texture = load_image(renderer, "30_122667.bmp");
//    auto background_texture = load_image(renderer, "background.bmp");

    bool game = true;
    while(game){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    game = false;
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

        if(player.mRect.x < 0 || player.mRect.x + player.mRect.w > SCREEN_WIDTH || player.mRect.y < 0  || player.mRect.y + player.mRect.h > SCREEN_HEIGHT){
            game = false;
        }

        SDL_SetRenderDrawColor(renderer, 169, 214, 216, 1);
        SDL_RenderClear(renderer);

        for(auto& tile: tiles){
            tile.render(renderer);
        }
        for(auto& point: pointss){
            point.render(renderer);
        }

        player.update(SCREEN_WIDTH, SCREEN_HEIGHT, dt, tiles, pointss);
        player.render(renderer);

        if(player.checkCollisionWithPoints(pointss)){
            count--;
            if(count == 25){
                map[4][24] = 0;
                drawMap();
            }
        }

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