#include "Obstacles.h"
#include <SDL.h>
#include <cstdlib>
#include <SDL_image.h>

const int HEIGHT = 600;
const int WIDTH = 600;
/*
void Obstacles::generateObs()
{
    ObsX = rand() % (600 / 10);
    ObsY = rand() % (600 / 10);
}
*/

void Obstacles::generateObs()
{
    ObsX = rand() % (WIDTH / 10);
    Obs.push_back(ObsX);
    ObsY = rand() % (HEIGHT / 10);
    Obs.push_back(ObsY);
}


void Obstacles::draw(SDL_Renderer* renderer)
{
    /*
    SDL_Rect rect;
    rect.w = 10;
    rect.h = 10;
    rect.x = 10 * ObsX;
    rect.y = 10 * ObsY;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    */
    SDL_Rect sourceRect;
    SDL_Rect desRect;
    SDL_Texture* load_obstacle = NULL;
    load_obstacle = IMG_LoadTexture(renderer,"obstacle.png");
    SDL_QueryTexture(load_obstacle, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
    sourceRect.y = 0;
    sourceRect.w /= 10;
    sourceRect.h /= 10;

    desRect.x = 10 * ObsX;
    desRect.y = 10 * ObsY;
    desRect.w = sourceRect.w;
    desRect.h = sourceRect.h;
    SDL_RenderCopy(renderer, load_obstacle, NULL, &desRect);
    SDL_DestroyTexture(load_obstacle);
}
