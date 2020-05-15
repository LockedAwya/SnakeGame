#include "buttons.h"
#include <SDL.h>
#include <SDL_image.h>

ButtonCoor buttoncoor = {};

void Button::getButtonPlay(SDL_Renderer* renderer)
{
    SDL_Rect desRect;
    SDL_Rect sourceRect;
    SDL_Texture* loadedplaybutton = NULL;
    loadedplaybutton = IMG_LoadTexture(renderer ,"playbutton.png");
    SDL_QueryTexture(loadedplaybutton, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = 100;
	sourceRect.h = 100;

	desRect.x = buttoncoor.bPX;
	desRect.y = buttoncoor.bPY;
	desRect.w = buttoncoor.bPW;
	desRect.h = buttoncoor.bPH;

	SDL_RenderCopy(renderer, loadedplaybutton, NULL, &desRect);
    SDL_DestroyTexture(loadedplaybutton);
}

void Button::getButtonInstruction(SDL_Renderer* renderer)
{
    SDL_Rect desRect;
    SDL_Rect sourceRect;
    SDL_Texture* loaded_instruction_button = NULL;
    loaded_instruction_button = IMG_LoadTexture(renderer ,"instruction.png");
    SDL_QueryTexture(loaded_instruction_button, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = buttoncoor.bIW;
	sourceRect.h = buttoncoor.bIH;

	desRect.x = buttoncoor.bIX;
	desRect.y = buttoncoor.bIY;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;

    SDL_RenderCopy(renderer, loaded_instruction_button, NULL, &desRect);
    SDL_DestroyTexture(loaded_instruction_button);
}

void Button::getButtonExit(SDL_Renderer* renderer)
{
    SDL_Rect desRect;
    SDL_Rect sourceRect;
    SDL_Texture* loaded_exit_button = NULL;
    loaded_exit_button = IMG_LoadTexture(renderer ,"exit.png");
    SDL_QueryTexture(loaded_exit_button, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = buttoncoor.bEW;
	sourceRect.h = buttoncoor.bEH;

	desRect.x = buttoncoor.bEX;
	desRect.y = buttoncoor.bEY;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;

    SDL_RenderCopy(renderer, loaded_exit_button, NULL, &desRect);
    SDL_DestroyTexture(loaded_exit_button);
}
/*
void Button::getButtonSoundOn(SDL_Renderer *renderer)
{
    SDL_Rect desRect;
    SDL_Rect sourceRect;
    SDL_Texture* load_SoundOn_button = NULL;
    load_SoundOn_button = IMG_LoadTexture(renderer ,"SoundOn.png");
    SDL_QueryTexture(load_SoundOn_button, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = buttoncoor.bSOnW;
	sourceRect.h = buttoncoor.bSOnH;

	desRect.x = buttoncoor.bSOnX;
	desRect.y = buttoncoor.bSOnY;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;

    SDL_RenderCopy(renderer, load_SoundOn_button, NULL, &desRect);
    SDL_DestroyTexture(load_SoundOn_button);
}

void Button::getButtonSoundOff(SDL_Renderer *renderer)
{
    SDL_Rect desRect;
    SDL_Rect sourceRect;
    SDL_Texture* load_SoundOff_button = NULL;
    load_SoundOff_button = IMG_LoadTexture(renderer ,"SoundOff.png");
    SDL_QueryTexture(load_SoundOff_button, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = buttoncoor.bSOffW;
	sourceRect.h = buttoncoor.bSOffH;

	desRect.x = buttoncoor.bSOffX;
	desRect.y = buttoncoor.bSOffY;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;

    SDL_RenderCopy(renderer, load_SoundOff_button, NULL, &desRect);
    SDL_DestroyTexture(load_SoundOff_button);
}

void Button::getButtonBack(SDL_Renderer *renderer)
{
    SDL_Rect desRect;
    SDL_Rect sourceRect;
    SDL_Texture* load_SoundOff_button = NULL;
    load_SoundOff_button = IMG_LoadTexture(renderer ,"BackButton.png");
    SDL_QueryTexture(load_SoundOff_button, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = buttoncoor.bBackW;
	sourceRect.h = buttoncoor.bBackH;

	desRect.x = buttoncoor.bBackX;
	desRect.y = buttoncoor.bBackY;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;

    SDL_RenderCopy(renderer, load_SoundOff_button, NULL, &desRect);
    SDL_DestroyTexture(load_SoundOff_button);
}
*/
