#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include <SDL_image.h>
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

SDL_Event g_event; //gameplay event
SDL_Event m_event; //menu event
SDL_Event i_event; //instruction event

SDL_Window *window;

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
    ButtonCoor buttoncoor = {};
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

void GamePlay(SDL_Renderer *renderer, SDL_Event g_event, Pictures &picture, Obstacles &obstacles, Food &food, Snake &snake, Pos& tail_position)
{
    snake.move();
    picture.getMenuBackground(renderer);
    snake.update(food, obstacles, picture, renderer);
    obstacles.draw(renderer);
    snake.draw(renderer, snake, tail_position);
    food.draw(renderer);
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
    while(Isrunning) {
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


