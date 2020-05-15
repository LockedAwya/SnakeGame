#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

class Game {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    //void Menu();
    //void Run();
    //void Init(SDL_Window* window, SDL_Renderer* renderer);
    void MainMenuUpdate(SDL_Renderer *renderer);
    void gameUpdate();
    void mainMenuDraw();
    void gameDraw();
};

#endif // GAME_H_INCLUDED
