#include "Game.h"
#include "buttons.h"
#include "Food.h"
#include "Snake.h"
#include "Obstacles.h"
#include "Pictures.h"
#include "CommonFunction.h"
#include "Sound.h"
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

Pictures picture = {};
Button button = {};
Snake snake = {};
Obstacles obstacles = {};
Food food = {};
Game game = {};
Sound sound = {};

///updating the snake

void Snake::update(Food &food, Obstacles &obstacles, SDL_Renderer* renderer)
{
    tail_start++; //tail
    tail_head++; //head
    std::cout << tail_head << std::endl;
    tail[tail_head % tail_max] = position_head; //head //tail_end
    //check if snake go outside of the screen, his head will reappear on the opposite side.
    if (position_head.x >= (WIDTH/snakeXY)) {position_head.x = 0;}
    if (position_head.y >= (HEIGHT/snakeXY)) {position_head.y = 0;} //60
    if (position_head.x < 0) {position_head.x = (WIDTH/snakeXY);}
    if (position_head.y < 0) {position_head.y = (HEIGHT/snakeXY);}
    //if snake's head gets the food, he will be longer in length
    if (position_head.x == food.FoodX && position_head.y == food.FoodY) {
            Score++;
            tail_length++;
            tail_start--;
            food.generateFood();
            obstacles.generateObs();
    }
    ///<--------- check lose ---------------->///
    for (int i = 0; i < tail_length; i++) { //tail_length
        Pos& tail_position = tail[(tail_start + i) % tail_max]; //tail_start
        if (tail_position.x == position_head.x && tail_position.y == position_head.y) {
            IsPlaying = false;
            tail_length = 0;
            Score = 0;
            tail_start = tail_head;
        }
    }
    if (obstacles.ObsX == position_head.x && obstacles.ObsY == position_head.y) {
            IsPlaying = false;
            tail_length = 0;
            Score = 0;
            tail_start = tail_head;
    }
}

///Updating the score

void Snake::Scoring(SDL_Renderer *renderer)
{
    std::stringstream score;
    score << Score;
    std::string str1 = score.str();
    TTF_Init();
    SDL_Color color = {0, 0, 0, 0};
    TTF_Font *font = TTF_OpenFont("shangri-la.ttf", 100);
    SDL_Surface *message = TTF_RenderText_Solid(font, str1.c_str(), color);
    SDL_Rect TextRect;
    SDL_Texture *text = NULL;
    text = SDL_CreateTextureFromSurface(renderer, message);
    SDL_QueryTexture(text, NULL, NULL, &TextRect.w, &TextRect.h);
    const int TextX = 50;
    const int TextY = 0;
    const int TextW = 40;
    const int TextH = 40;
    {TextRect.x = TextX, TextRect.y = TextY, TextRect.w = TextW, TextRect.h = TextH;}
    SDL_RenderCopy(renderer, text, NULL, &TextRect);
    TTF_CloseFont(font);
    SDL_FreeSurface(message);
    SDL_DestroyTexture(text);
}

///Menu Game

void Game::Menu(SDL_Renderer* renderer)
{
    picture.getMenuBackground(renderer);
    button.LoadButtons(renderer);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

///GamePlay

void Game::GamePlay(SDL_Renderer* renderer)
{
    snake.move();
    SDL_Delay(30);
    picture.getGamePlayBackground(renderer);
    snake.update(food, obstacles, renderer);
    snake.Scoring(renderer);
    snake.draw(renderer, snake);
    obstacles.draw(renderer);
    food.draw(renderer);
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
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

void Game::Instruction(SDL_Renderer* renderer)
{
    picture.getInstructionBackground(renderer);
    SDL_RenderPresent(renderer);
    while(SDL_PollEvent(&i_event)) {
    if (i_event.type == SDL_QUIT) {
        IsInstruction = false;
        Isrunning = false;
        }
    if (i_event.type == SDL_KEYDOWN) {
        switch (i_event.key.keysym.sym) {
        case SDLK_b:
            IsInstruction = false;
            }
        }
    }
}

///The main character is here

void Game::GameIsRunning(SDL_Renderer *renderer)
{
    ButtonCoor buttoncoor = {};
    while (Isrunning) {
    picture.getMenuBackground(renderer);
    button.LoadButtons(renderer);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    while (SDL_PollEvent(&m_event)) {
        if (m_event.type == SDL_QUIT) { //e
            Isrunning = false;
        }
        if (m_event.type == SDL_MOUSEBUTTONDOWN)
        {
            int x = m_event.motion.x;
            int y = m_event.motion.y;
            if (x >= buttoncoor.bPX && x <= buttoncoor.bPX + buttoncoor.bPW && y >= buttoncoor.bPY && y <= buttoncoor.bPY + buttoncoor.bPH) ///click PlayGame
            {
                 IsPlaying = true;
                 while(IsPlaying) {
                    game.GamePlay(renderer);
                }
            }
        else if (x >= buttoncoor.bIX && x <= buttoncoor.bIX + buttoncoor.bIW && y >= buttoncoor.bIY && y <= buttoncoor.bIY + buttoncoor.bIH) ///click instruction
        {
            IsInstruction = true;
            while (IsInstruction) {
                game.Instruction(renderer);
            }
        }
        else if (x >= buttoncoor.bEX && x <= buttoncoor.bEX + buttoncoor.bEW && y >= buttoncoor.bEY && y <= buttoncoor.bEY + buttoncoor.bEH) ///click exit button
        {
            Isrunning = false;
        }
        SDL_RenderClear(renderer);
    }
    //SDL_RenderClear(renderer);
    }
    }
}

