#include "Sound.h"
#include <SDL.h>
#include <SDL_mixer.h>

void Sound::GameSound()
{
    Mix_OpenAudio(2000, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_Music *PlaySound = NULL;
    PlaySound = Mix_LoadMUS("MenuSound2.mp3");
    Mix_PlayMusic(PlaySound, -1);
    SDL_Delay(3000);
}

void Sound::FreeGameSound()
{
    Mix_Music *PlaySound = NULL;
    Mix_FreeMusic(PlaySound);
}

