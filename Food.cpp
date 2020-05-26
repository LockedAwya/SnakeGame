#include "Food.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

const int HEIGHT = 600;
const int WIDTH = 600;

void Food::generateFood()
{
    FoodX = rand() % (WIDTH / FoodWidth);
    Food.push_back(FoodX);
    FoodY = rand() % (HEIGHT / FoodHeight);
    Food.push_back(FoodY);
}

void Food::draw(SDL_Renderer *renderer)
{
    SDL_Rect sourceRect;
    SDL_Rect desRect;
    SDL_Texture* loadedcherry = NULL;
    loadedcherry = IMG_LoadTexture(renderer,"Optimized-cherryblah.png");
    SDL_QueryTexture(loadedcherry, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = FoodWidth;
	sourceRect.h = FoodHeight;

	desRect.x = sizeFoodXY * FoodX;
	desRect.y = sizeFoodXY * FoodY;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;
    SDL_RenderCopy(renderer, loadedcherry, NULL, &desRect);
    SDL_DestroyTexture(loadedcherry);
}
