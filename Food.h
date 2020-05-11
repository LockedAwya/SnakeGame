#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include "Snake.h"
#include <SDL.h>

class Food
{
public:
    int FoodX, FoodY;
    void generateFood();
    void draw(SDL_Renderer* renderer);
};

//SDL_Rect sourceRect;
//SDL_Rect desRect;

#endif // FOOD_H_INCLUDED
