#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Sound.h"
#include "Snake.h"
#include "Food.h"
#include "Obstacles.h"
#include "buttons.h"
#include "Pictures.h"
#include "Game.h"
//#include "CommonFunction.h"

const int HEIGHT = 600;
const int WIDTH = 600;

SDL_Window *window;

//paste them here lool
int main(int argc, char* argv[])
{
    Game game = {};
    Sound sound = {};
    window = SDL_CreateWindow("Snake Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, HEIGHT, WIDTH, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    sound.GameSound();
    game.GameIsRunning(renderer);
    sound.FreeGameSound();
    //Mix_CloseAudio();
    //Destroy a window.
	SDL_DestroyWindow(window);
	//Destroy a renderer
	SDL_DestroyRenderer(renderer);
	//cleans up all initialized subsystems
    Mix_CloseAudio();
    TTF_Quit();
	SDL_Quit();
	return 0;
}


