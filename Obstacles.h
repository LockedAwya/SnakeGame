#ifndef OBSTACLES_H_INCLUDED
#define OBSTACLES_H_INCLUDED
#include <SDL.h>
#include <vector>
/*
struct ObstaclesCoor {
    int ObsX, ObsY;
    ObstaclesCoor(int _ObsX, int _ObsY) {
        ObsX = _ObsX;
        ObsY = _ObsY;
    }
};
*/
class Obstacles
{
public:
    int ObsX, ObsY;
    std::vector <int> Obs;
    void generateObs();
    void draw(SDL_Renderer* renderer);
};
/*
class Obstacles
{
    int _ObsX, _ObsY;
    Obstacles(int &ObsX, int &ObsY) {
        ObsX = _ObsX;
        ObsY = _ObsY;
    };
public:
    int ObsX, ObsY;
    std::vector<std::vector<Obstacles>> Obs(ObsY, std::vector<Obstacles> (ObsX));
    Obs.push_back(Obstacles(ObsX, ObsY));
    void generateObs();
    void draw(SDL_Renderer* renderer);
};
*/
#endif // OBSTACLES_H_INCLUDED
