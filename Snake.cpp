#include "Snake.h"
#include "Food.h"
#include "Obstacles.h"
#include "Pictures.h"
//#include "CommonFunction.h"
#include <iostream>
#include <SDL.h>
#include <algorithm>
#include <SDL_image.h>

using namespace std;

const int HEIGHT = 600;
const int WIDTH = 600;

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
    velocity.stepX = 0;
    velocity.stepY = -1;
    }
}
void Snake::TurnDown()
{
    if (velocity.stepY != -1) {
    velocity.stepX = 0;
    velocity.stepY = 1;
    }
}


void Snake::update(Food &food, Obstacles &obstacles, Pictures &picture, SDL_Renderer* renderer)
{
    tail_start++;
    tail_end++;
    tail[tail_end % tail_max] = position_head; //head
    //check if snake go outside of the screen, his head will reappear on the opposite side.
    if (position_head.x >= (WIDTH/10)) {position_head.x = 0;}
    if (position_head.y >= (HEIGHT/10)) {position_head.y = 0;} //60
    if (position_head.x < 0) {position_head.x = (WIDTH/10);}
    if (position_head.y < 0) {position_head.y = (HEIGHT/10);}
    //if snake's head gets the food, he will be longer in length
    if (position_head.x == food.FoodX && position_head.y == food.FoodY) { //food.FoodX, food.FoodY
            //cout << position_head.x << " " << position_head.y << endl;
            tail_length++;
            tail_start--;
            food.generateFood();
            obstacles.generateObs();
    }
    ///// check lose //////
    for (int i = 0; i < tail_length; i++) { //tail_length
        Pos& tail_position = tail[(tail_start + i) % tail_max]; //tail_start
        if (tail_position.x == position_head.x && tail_position.y == position_head.y) {
            tail_length = 0;
        tail_start = tail_end;
        }
    }
    if (obstacles.ObsX == position_head.x && obstacles.ObsY == position_head.y) {
        tail_length = 0;
        tail_start = tail_end;
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
	sourceRect.w = 16;
	sourceRect.h = 16;

	desRect.x = 12 * position_head.x; //10
	desRect.y = 12 * position_head.y;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;
    SDL_RenderCopy(renderer, loadHead, NULL, &desRect);
    SDL_DestroyTexture(loadHead);
}

void Snake::drawTails(SDL_Renderer *renderer, Pos& tail_position)
{
    for (int i = 0; i < tail_length; i++) {
        tail_position = tail[(tail_start + i) % 1000]; //tail_start + i
        SDL_Rect sourceRect;
        SDL_Rect desRect;
        SDL_Texture* loadTail = NULL;
        loadTail = IMG_LoadTexture(renderer,"red.png");
        SDL_QueryTexture(loadTail, NULL, NULL, &sourceRect.w, &sourceRect.h);
        sourceRect.x = 0;
        sourceRect.y = 0;
        sourceRect.w = 16;
        sourceRect.h = 16;

        desRect.x = 12 * tail_position.x;
        desRect.y = 12 * tail_position.y;
        desRect.w = sourceRect.w;
        desRect.h = sourceRect.h;
        SDL_RenderCopy(renderer, loadTail, NULL, &desRect);
        SDL_DestroyTexture(loadTail);
    }
}

void Snake::draw(SDL_Renderer* renderer, Snake &snake, Pos& tail_position)
{
    snake.drawHead(renderer);
    snake.drawTails(renderer, tail_position);
}


