#include "Obstacles.h"
#include <SDL.h>
#include <cstdlib>
#include <SDL_image.h>

const int HEIGHT = 600;
const int WIDTH = 600;

class ObstaclesCoor;

void Obstacles::generateObs()
{
    ObsX = rand() % (WIDTH / 16); //12
    Obs.push_back(ObsX);
    ObsY = rand() % (HEIGHT / 16); //12
    Obs.push_back(ObsY);
}


void Obstacles::draw(SDL_Renderer* renderer)
{
    Obstacles obstacles = {};
    SDL_Rect sourceRect;
    SDL_Rect desRect;
    SDL_Texture* load_obstacle = NULL;
    load_obstacle = IMG_LoadTexture(renderer,"obstacle.png");
    SDL_QueryTexture(load_obstacle, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
    sourceRect.y = 0;
    sourceRect.w = obstacles.ObsWidth;
    sourceRect.h = obstacles.ObsHeight;

    desRect.x = sizeObsXY * ObsX;
    desRect.y = sizeObsXY * ObsY;
    desRect.w = sourceRect.w;
    desRect.h = sourceRect.h;
    SDL_RenderCopy(renderer, load_obstacle, NULL, &desRect);
    //SDL_RenderClear(renderer);
    SDL_DestroyTexture(load_obstacle);

}
