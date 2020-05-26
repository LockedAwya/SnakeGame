#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include "Snake.h"
#include <SDL.h>
#include <vector>

class Food
{
private:
    const int FoodWidth = 12;
    const int FoodHeight = 12;

    const int sizeFoodXY = 10;
public:
    int FoodX, FoodY;
    std::vector <int> Food;
    void generateFood();
    void draw(SDL_Renderer* renderer);
};

#endif // FOOD_H_INCLUDED
