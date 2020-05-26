#ifndef OBSTACLES_H_INCLUDED
#define OBSTACLES_H_INCLUDED
#include <SDL.h>
#include <vector>

class Obstacles
{
private:
    const int sizeObsXY = 10;
public:
    int ObsX, ObsY;
    const int ObsWidth = 20;
    const int ObsHeight = 20;
    std::vector <int> Obs;
    void generateObs();
    void draw(SDL_Renderer* renderer);
};
#endif // OBSTACLES_H_INCLUDED
