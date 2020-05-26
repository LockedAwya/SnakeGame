#ifndef PICTURES_H_INCLUDED
#define PICTURES_H_INCLUDED
#include <SDL.h>

struct ButtonCoor;

class Pictures
{
public:
    void getMenuBackground(SDL_Renderer *renderer);
    void getInstructionBackground(SDL_Renderer *renderer);
    void getGamePlayBackground(SDL_Renderer *renderer);
};

#endif // PICTURES_H_INCLUDED
