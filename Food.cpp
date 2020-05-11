#include "Food.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

const int HEIGHT = 600;
const int WIDTH = 600;


void Food::generateFood()
{
    FoodX = rand() % (WIDTH / 12);
    FoodY = rand() % (HEIGHT / 12);
    cout << FoodX << " " << FoodY << endl;
}

void Food::draw(SDL_Renderer *renderer)
{
    SDL_Rect sourceRect;
    SDL_Rect desRect;
    SDL_Texture* loadedcherry = NULL;
    loadedcherry = IMG_LoadTexture(renderer,"cherry.png");
    SDL_QueryTexture(loadedcherry, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = 16;
	sourceRect.h = 16;

	desRect.x = 12 * FoodX;
	desRect.y = 12 * FoodY;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;
    SDL_RenderCopy(renderer, loadedcherry, NULL, &desRect);
    SDL_DestroyTexture(loadedcherry);
}
