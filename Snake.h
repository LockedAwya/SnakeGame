#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "Food.h"
#include "Obstacles.h"
#include "Pictures.h"
#include <SDL.h>
#include <string>

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
    Vel velocity; //speed of the snake (which has directions)
    int tail_start, tail_end; //head, //tail
    int tail_length = 1000;
    Pos tail[tail_max];
    //bool isCollide(Obstacles &obstacles);
public:
    void move();
    void update(Food &food, Obstacles &obstacles, Pictures &picture, SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer, Snake &snake, Pos& tail_position);
    void drawHead(SDL_Renderer* renderer);
    void drawTails(SDL_Renderer* renderer, Pos& tail_position);
    void TurnLeft();
    void TurnRight();
    void TurnUp();
    void TurnDown();
    void GameOver(Food &food, Obstacles &obstacles, Pictures &picture, SDL_Renderer *renderer);
};

#endif // SNAKE_H_INCLUDED
