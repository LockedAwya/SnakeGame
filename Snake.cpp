#include "Snake.h"
#include "Food.h"
#include "Obstacles.h"
#include "Pictures.h"
#include "Sound.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <sstream>
#include <SDL_ttf.h>

void Snake::move()
{
    position_head.x += velocity.stepX;
    position_head.y += velocity.stepY;
}
void Snake::TurnLeft()
{
    if (velocity.stepX != 1) {
        velocity.stepX = -1;
        velocity.stepY = 0;
    }
}

void Snake::TurnRight()
{
    if (velocity.stepX != -1) {
    velocity.stepX = 1;
    velocity.stepY = 0;
    }
}
void Snake::TurnUp()
{
    if (velocity.stepY != 1) {
    velocity.stepY = -1;
    velocity.stepX = 0;
    }
}
void Snake::TurnDown()
{
    if (velocity.stepY != -1) {
    velocity.stepY = 1;
    velocity.stepX = 0;
    }
}

void Snake::drawHead(SDL_Renderer* renderer)
{
    SDL_Rect sourceRect;
    SDL_Rect desRect;
    SDL_Texture* loadHead = NULL;
    loadHead = IMG_LoadTexture(renderer,"yellow.png");
    SDL_QueryTexture(loadHead, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = snakeWidth;
	sourceRect.h = snakeHeight;

	desRect.x = snakeXY * position_head.x;
	desRect.y = snakeXY * position_head.y;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;
    SDL_RenderCopy(renderer, loadHead, NULL, &desRect);
    SDL_DestroyTexture(loadHead);
}

void Snake::drawTails(SDL_Renderer *renderer)
{
    SDL_Texture* loadTail = NULL;
    for (int i = 0; i < tail_length; i++) {
        Pos& tail_position = tail[(tail_start + i) % tail_max]; //tail_start + i
        SDL_Rect sourceRect;
        SDL_Rect desRect;
        loadTail = IMG_LoadTexture(renderer,"red.png");
        SDL_QueryTexture(loadTail, NULL, NULL, &sourceRect.w, &sourceRect.h);
        sourceRect.x = 0;
        sourceRect.y = 0;
        sourceRect.w = snakeWidth; //12
        sourceRect.h = snakeHeight; //12

        desRect.x = snakeXY * tail_position.x; //tail_position
        desRect.y = snakeXY * tail_position.y;
        desRect.w = sourceRect.w;
        desRect.h = sourceRect.h;
        SDL_RenderCopy(renderer, loadTail, NULL, &desRect);
        SDL_DestroyTexture(loadTail);
    }
}


void Snake::draw(SDL_Renderer* renderer, Snake &snake)
{
    snake.drawHead(renderer);
    snake.drawTails(renderer);
}


