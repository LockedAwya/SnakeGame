#include "Pictures.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <sstream>

using namespace std;

int Score = 0;

void Pictures::getGamePlayBackground(SDL_Renderer *renderer)
{
    SDL_Texture* loadGamePlayBackground = NULL;
    loadGamePlayBackground = IMG_LoadTexture(renderer ,"GamePlayBackground.png");
    SDL_RenderCopy(renderer, loadGamePlayBackground, NULL, NULL);
    SDL_DestroyTexture(loadGamePlayBackground);
}

void Pictures::getMenuBackground(SDL_Renderer *renderer)
{
    SDL_Texture* loadMenuBackground = NULL;
    loadMenuBackground = IMG_LoadTexture(renderer ,"6.png");
    SDL_RenderCopy(renderer, loadMenuBackground, NULL, NULL);
    SDL_DestroyTexture(loadMenuBackground);
}

void Pictures::getInstructionBackground(SDL_Renderer *renderer)
{
    SDL_Texture* loadInstructionBackground = NULL;
    loadInstructionBackground = IMG_LoadTexture(renderer ,"InsBackground.png");
    SDL_RenderCopy(renderer, loadInstructionBackground, NULL, NULL);
    SDL_DestroyTexture(loadInstructionBackground);
}


