#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Snake.h"
#include "Food.h"
#include "Obstacles.h"
#include "buttons.h"
#include "Pictures.h"
//#include "CommonFunction.h"

const int HEIGHT = 600;
const int WIDTH = 600;
bool IsPlaying = true;
bool Isrunning = true;
bool IsInstruction = true;
bool TurnOffSound = true;
bool TurnOnSound = true;
bool GameOver = true;

SDL_Event g_event; //gameplay event
SDL_Event m_event; //menu event
SDL_Event i_event; //instruction event
SDL_Event gameOver_event;

SDL_Window *window;

/*
void Snake::GameOver(Food &food, Obstacles &obstacles, Pictures &picture, SDL_Renderer* renderer)
{
     for (int i = 0; i < tail_length; i++) { //tail_length
        Pos& tail_position = tail[(tail_start + i) % tail_max]; //tail_start
        if (tail_position.x == position_head.x && tail_position.y == position_head.y) {
            IsPlaying = false;
            while(!IsPlaying) {
                picture.getGameOver(renderer);
            }
        }
    }
    if (obstacles.ObsX == position_head.x && obstacles.ObsY == position_head.y) {
        IsPlaying = false;
            while(!IsPlaying) {
                picture.getGameOver(renderer);
            }
    }
}
*/


void Menu(SDL_Renderer *renderer, Pictures &picture, Button &button)
{
    picture.getMenuBackground(renderer);
    button.getButtonInstruction(renderer);
    button.getButtonPlay(renderer);
    button.getButtonExit(renderer);
    button.getButtonSoundOn(renderer);
    //button.getButtonSoundOff(renderer);
    SDL_RenderPresent(renderer);
}

void Instruction(SDL_Renderer *renderer, SDL_Event i_event, Pictures &picture, Button &button)
{
    picture.getInstructionBackground(renderer);
    button.getButtonBack(renderer);
    SDL_RenderPresent(renderer);
    while(SDL_PollEvent(&i_event)) {
    if (i_event.type == SDL_QUIT) {
        IsInstruction = false;
        //Isrunning = false;
        }
    if (i_event.type == SDL_KEYDOWN) {
        switch (i_event.key.keysym.sym) {
        case SDLK_b:
            IsInstruction = false;
        }
    }
    }
}

void Snake::update(Food &food, Obstacles &obstacles, Pictures &picture, SDL_Renderer* renderer, uint32_t delta_time)
{
    Snake snake = {};
    accumulator += delta_time;
    if (accumulator > 1000 - tail_length) {
    accumulator = 0;
    tail_start++;
    tail_end++;
    tail[tail_end % tail_max] = position_head; //head //tail_end
    //check if snake go outside of the screen, his head will reappear on the opposite side.
    if (position_head.x >= (WIDTH/12)) {position_head.x = 0;}
    if (position_head.y >= (HEIGHT/12)) {position_head.y = 0;} //60
    if (position_head.x < 0) {position_head.x = (WIDTH/12);}
    if (position_head.y < 0) {position_head.y = (HEIGHT/12);}
    //if snake's head gets the food, he will be longer in length
    if (position_head.x == food.FoodX && position_head.y == food.FoodY) { //food.FoodX, food.FoodY //position_head
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
            //IsPlaying = false;
            //SDL_Delay(50);
            IsPlaying = false;
            tail_length = 0;
            tail_start = tail_end;
            position_head.x = rand() % (600 / 12);
            position_head.y = rand() % (600 / 12);

        }
    if (obstacles.ObsX == position_head.x && obstacles.ObsY == position_head.y) {
        //tail_length = 0;
        //tail_start = tail_end;
            IsPlaying = false;
            tail_length = 0;
            tail_start = tail_end;
            snake.Setup();
    }
}
    }
}


void GamePlay(SDL_Renderer *renderer, SDL_Event g_event, Pictures &picture, Obstacles &obstacles, Food &food, Snake &snake, Pos& tail_position)
{
    uint32_t delta_time;
    ///snake.move();
    //SDL_Delay(5);
    //snake.update(food, obstacles, picture, renderer, delta_time);
    picture.getGamePlayBackground(renderer);
    //snake.Setup();
    //snake.draw(renderer, snake, tail_position);
    ///snake.update(food, obstacles, picture, renderer, delta_time);
    ///snake.draw(renderer, snake, tail_position);
    ///obstacles.draw(renderer);
    ///food.draw(renderer);
    //snake.update(food, obstacles, picture, renderer, delta_time);
    //while (snake.GameOver(food, obstacles, picture)) {picture.getGameOver(renderer);}
    //picture.getGameOver(renderer);
    SDL_RenderPresent(renderer);
    while (SDL_PollEvent(&g_event)) {
        if (g_event.type == SDL_QUIT) {
            IsPlaying = false;
            Isrunning = false;
        }
        if (g_event.type == SDL_KEYDOWN) {
            switch (g_event.key.keysym.sym) {
            case SDLK_ESCAPE:
                IsPlaying = false;
                break;
            case SDLK_UP:
                snake.TurnUp();
                break;
            case SDLK_DOWN:
                snake.TurnDown();
                break;
            case SDLK_LEFT:
                snake.TurnLeft();
                break;
            case SDLK_RIGHT:
                snake.TurnRight();
                break;
            default:
                break;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    Pictures picture = {};
    Button button = {};
    ButtonCoor buttoncoor = {};
    Snake snake = {};
    Food food = {};
    Obstacles obstacles = {};
    Pos tail_position = {};
    window = SDL_CreateWindow("Snake Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, HEIGHT, WIDTH, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
        uint32_t current_time = 0, previous_time, delta_time;
    while(Isrunning) {
        previous_time = current_time;
        current_time = SDL_GetTicks();
        delta_time = current_time - previous_time;
        Menu(renderer, picture, button);
        while (SDL_PollEvent(&m_event)) {
            if (m_event.type == SDL_QUIT) { //e
                Isrunning = false;
            }
            if (m_event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = m_event.motion.x;
                int y = m_event.motion.y;
                if (x >= buttoncoor.bPX && x <= buttoncoor.bPX + buttoncoor.bPW && y >= buttoncoor.bPY && y <= buttoncoor.bPY + buttoncoor.bPH) //click PlayGame
                {//SDL_ShowSimpleMessageBox(0, "Mouse", "PlayButton clicked!", window);
                     IsPlaying = true;
                     while(IsPlaying) {
                        GamePlay(renderer, g_event, picture, obstacles, food, snake, tail_position);
                    }
                }
            else if (x >= buttoncoor.bIX && x <= buttoncoor.bIX + buttoncoor.bIW && y >= buttoncoor.bIY && y <= buttoncoor.bIY + buttoncoor.bIH) //click instruction
            {   //SDL_ShowSimpleMessageBox(0, "Mouse", "InstructionButton clicked!", window);
                IsInstruction = true;
                while (IsInstruction) {
                    Instruction(renderer, i_event, picture, button);
                }
            }
            else if (x >= buttoncoor.bEX && x <= buttoncoor.bEX + buttoncoor.bEW && y >= buttoncoor.bEY && y <= buttoncoor.bEY + buttoncoor.bEH) //click exit
            {
                Isrunning = false;
            }
        }
    }
    }
        //SDL_RenderPresent(renderer);
    //Destroy a window.
	SDL_DestroyWindow(window);

	//Destroy a renderer
	SDL_DestroyRenderer(renderer);

	//cleans up all initialized subsystems
	SDL_Quit();
	return 0;
}


