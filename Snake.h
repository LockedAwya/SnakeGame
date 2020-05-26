#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "Food.h"
#include "Obstacles.h"
#include "Pictures.h"
#include <SDL.h>

int const tail_max = 1000;

class Food;
class Obstacles;

struct Vel {
    int stepX = 0, stepY = 0;
};

struct Pos {
    int x, y;
};

class Snake
{
private:
    Pos position_head; //snake's head position
    Vel velocity; //speed of the snake
    int tail_start = 0, tail_end = 0; //head, //tail
    int tail_length = 1000;
    Pos tail[tail_max];
    int Score = 0;
    const int snakeWidth = 12;
    const int snakeHeight = 12;

    const int snakeXY = 10;
public:
    void move();
    void update(Food &food, Obstacles &obstacles, SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer, Snake &snake);
    void drawHead(SDL_Renderer* renderer);
    void drawTails(SDL_Renderer* renderer);
    void TurnLeft();
    void TurnRight();
    void TurnUp();
    void TurnDown();
    void Scoring(SDL_Renderer* renderer); //Update the scoring stuff
};

#endif // SNAKE_H_INCLUDED
