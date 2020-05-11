#include "Game.h"
#include "buttons.h"
#include "Food.h"
#include "Snake.h"
#include "Obstacles.h"
/*
bool in_menu = true;
bool in_game = true;
const int HEIGHT = 600;
const int WIDTH = 600;
Game game = {};


void Game::MainMenuUpdate(SDL_Renderer *renderer)
{
    SDL_Rect sourceRect;
    SDL_Texture* loadedbackground = NULL;
    loadedbackground = IMG_LoadTexture(renderer ,"6.png");
    SDL_QueryTexture(loadedbackground, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = 50;
	sourceRect.h = 50;
    SDL_RenderCopy(renderer, loadedbackground, NULL, NULL);
	//desRect.x = 1;
	//desRect.y = 1;
	//desRect.w = sourceRect.w;
	//desRect.h = sourceRect.h;
    SDL_Event m_event;
    bool Isrunning = true;
    Button button = {};
    ButtonCoor buttoncoor;
    //button.getButtonInstruction(renderer);
    //button.getButtonPlay(renderer);
    bool selected = true;
    while(true) {
        SDL_Rect sourceRect;
        SDL_Texture* loadedbackground = NULL;
        loadedbackground = IMG_LoadTexture(renderer ,"6.png");
        SDL_QueryTexture(loadedbackground, NULL, NULL, &sourceRect.w, &sourceRect.h);
        sourceRect.x = 0;
        sourceRect.y = 0;
        sourceRect.w = 50;
        sourceRect.h = 50;
        SDL_RenderCopy(renderer, loadedbackground, NULL, NULL);
        button.getButtonInstruction(renderer);
        button.getButtonPlay(renderer);
        while(SDL_PollEvent(&m_event))
        {
            switch(m_event.type)
            {
            case SDL_QUIT:
                return 1;
            case SDL_MOUSEBUTTONDOWN:
                int x = e.motion.x;
                int y = e.motion.y;
                if (x > buttoncoor.bPX && x < buttoncoor.bPX + buttoncoor.bPW && y > buttoncoor.bPY && y < buttoncoor.bPY + buttoncoor.bPH)
                    //SDL_ShowSimpleMessageBox(0, "Mouse", "PlayButton clicked!", window);
                    return button.getButtonPlay(renderer);
                else if (x > buttoncoor.bIX && x < buttoncoor.bIX + buttoncoor.bIW && y > buttoncoor.bIY && y < buttoncoor.bIY + buttoncoor.bIH)
                    return button.getButtonInstruction(renderer);
                else if (x > buttoncoor.bEX && x < buttoncoor.bEX + buttoncoor.bEW && y > buttoncoor.bEY && y < buttoncoor.bEY + buttoncoor.bEH)
                    //SDL_ShowSimpleMessageBox(0, "Mouse", "ExitButton clicked!", window);
                    return button.getButtonExit(renderer);
            }
        }
    }
    while(in_menu) {
        if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = e.motion.x;
                int y = e.motion.y;
                if (x > buttoncoor.bPX && x < buttoncoor.bPX + buttoncoor.bPW && y > buttoncoor.bPY && y < buttoncoor.bPY + buttoncoor.bPH)
                    //SDL_ShowSimpleMessageBox(0, "Mouse", "PlayButton clicked!", window);
                    game.gameUpdate();
                else if (x > buttoncoor.bIX && x < buttoncoor.bIX + buttoncoor.bIW && y > buttoncoor.bIY && y < buttoncoor.bIY + buttoncoor.bIH)
                    SDL_ShowSimpleMessageBox(0, "Mouse", "InstructionButton clicked!", window);
            }
        }
        //SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, loadedbackground, NULL, NULL);
        //button.getButtonInstruction(renderer);
        //  button.getButtonPlay(renderer);
        SDL_RenderPresent(renderer);
    }
    //Destroy a window.
	SDL_DestroyWindow(window);

	//Destroy a renderer
	SDL_DestroyRenderer(renderer);

	//cleans up all initialized subsystems
	SDL_Quit();
	return 0;
}

void Game::gameUpdate()
{
    SDL_Rect sourceRect;
    //SDL_Rect desRect;
    SDL_Texture* loadedtexture = NULL;
    loadedtexture = IMG_LoadTexture(renderer ,"6.png");
    SDL_QueryTexture(loadedtexture, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = 50;
	sourceRect.h = 50;
    while(in_game) {
        snake.move();
        SDL_Delay(65);
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                IsPlaying = false;
            }
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
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
        snake.update(food, obstacles);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, loadedtexture, NULL, NULL);
        obstacles.draw(renderer);
        snake.draw(renderer);
        food.draw(renderer);
        //gameover.draw(renderer);
        //obstacles.draw(renderer);
        SDL_RenderPresent(renderer);
    }
}
*/

