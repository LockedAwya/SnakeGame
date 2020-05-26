#include "buttons.h"
#include <SDL.h>
#include <SDL_image.h>
//#include "CommonFunction.h"

ButtonCoor buttoncoor = {};
SDL_Rect desRect;
SDL_Rect sourceRect;

SDL_Texture* loadedplaybutton = NULL;
SDL_Texture* loaded_instruction_button = NULL;
SDL_Texture* loaded_exit_button = NULL;

void Button::LoadButtons(SDL_Renderer* renderer)
{
    loadedplaybutton = IMG_LoadTexture(renderer ,"playbutton.png");
    SDL_QueryTexture(loadedplaybutton, NULL, NULL, &sourceRect.w, &sourceRect.h);
    {sourceRect.x = 0;  sourceRect.y = 0;   sourceRect.w = 100;   sourceRect.h = 100;}
    {desRect.x = buttoncoor.bPX;  desRect.y = buttoncoor.bPY;  desRect.w = buttoncoor.bPW;  desRect.h = buttoncoor.bPH;}
    SDL_RenderCopy(renderer, loadedplaybutton, NULL, &desRect);
    SDL_DestroyTexture(loadedplaybutton);

    loaded_instruction_button = IMG_LoadTexture(renderer ,"instruction.png");
    SDL_QueryTexture(loaded_instruction_button, NULL, NULL, &sourceRect.w, &sourceRect.h);
    {sourceRect.x = 0;  sourceRect.y = 0;  sourceRect.w = buttoncoor.bIW;  sourceRect.h = buttoncoor.bIH;}
    {desRect.x = buttoncoor.bIX;  desRect.y = buttoncoor.bIY;  desRect.w = sourceRect.w;  desRect.h = sourceRect.h;}
    SDL_RenderCopy(renderer, loaded_instruction_button, NULL, &desRect);
    SDL_DestroyTexture(loaded_instruction_button);
    //free();

    loaded_exit_button = IMG_LoadTexture(renderer ,"exit.png");
    SDL_QueryTexture(loaded_exit_button, NULL, NULL, &sourceRect.w, &sourceRect.h);
    {sourceRect.x = 0;  sourceRect.y = 0;  sourceRect.w = buttoncoor.bEW;  sourceRect.h = buttoncoor.bEH;}
    {desRect.x = buttoncoor.bEX;  desRect.y = buttoncoor.bEY;  desRect.w = sourceRect.w;  desRect.h = sourceRect.h;}
    SDL_RenderCopy(renderer, loaded_exit_button, NULL, &desRect);
    SDL_DestroyTexture(loaded_exit_button);

}

