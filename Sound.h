#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED
#include <SDL.h>
#include <SDL_mixer.h>

class Sound
{
public:
    void GameSound();
    void FreeGameSound();
};

#endif // SOUND_H_INCLUDED
