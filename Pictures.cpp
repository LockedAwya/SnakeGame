#include "Pictures.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

void Pictures::getGamePlayBackground(SDL_Renderer *renderer)
{
    SDL_Texture* loadMenuBackground = NULL;
    loadMenuBackground = IMG_LoadTexture(renderer ,"GamePlayBackground.png");
    //paste text in the background
    SDL_Color color = {144, 77, 255, 255};
    TTF_Font *font = TTF_OpenFont("shangri-la.ttf", 20);
    SDL_Surface *message = TTF_RenderText_Solid(font, "Score:", color);
    SDL_Rect TextRect;
    SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, message);
    SDL_QueryTexture(text, NULL, NULL, &TextRect.w, &TextRect.h);
    TextRect.x = 0;TextRect.y = 0; TextRect.w = 300; TextRect.h = 300;
    //SDL_RenderCopy(renderer, text, NULL, &TextRect);
    //
    SDL_RenderCopy(renderer, loadMenuBackground, NULL, NULL);
    SDL_RenderCopy(renderer, text, NULL, NULL);
    SDL_DestroyTexture(loadMenuBackground);
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

void Pictures::getGameOver(SDL_Renderer *renderer)
{
    SDL_Rect desRect;
    SDL_Rect sourceRect;
    SDL_Texture* loadGameOver = NULL;
    loadGameOver = IMG_LoadTexture(renderer ,"GameOver.png");

    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w /= 2;
	sourceRect.h /= 2;

	desRect.x = 450;
	desRect.y = 450;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;

    SDL_RenderCopy(renderer, loadGameOver, NULL, NULL);
    SDL_DestroyTexture(loadGameOver);
}
