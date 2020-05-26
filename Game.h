#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

class Game {
private:
    SDL_Event g_event; //gameplay event
    SDL_Event m_event; //menu event
    SDL_Event i_event; //instruction event
public:
    void Menu(SDL_Renderer *renderer);
    void GamePlay(SDL_Renderer *renderer);
    void Instruction(SDL_Renderer *renderer);
    void GameIsRunning(SDL_Renderer *renderer);
};

#endif // GAME_H_INCLUDED
