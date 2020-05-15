#ifndef BUTTONS_H_INCLUDED
#define BUTTONS_H_INCLUDED
#include <SDL.h>

struct ButtonCoor {
    const int bPX = 230; //x-axis of playbutton
    const int bPY = 300; //y-axis of playbutton
    const int bPW = 100; //width-axis of playbutton
    const int bPH = 100; //height-axis of playbutton

    const int bIX = 250; //x-axis of Instructionbutton
    const int bIY = 400; //y-axis of Instructionbutton
    const int bIW = 50; //width-axis of Instructionbutton
    const int bIH = 50; //height-axis of Instructionbutton

    const int bEX = 250;
    const int bEY = 450;
    const int bEW = 70;
    const int bEH = 70;
    /*
    const int bSOnX = 0;
    const int bSOnY = 550;
    const int bSOnW = 50;
    const int bSOnH = 50;

    const int bSOffX = 0;
    const int bSOffY = 550;
    const int bSOffW = 50;
    const int bSOffH = 50;

    const int bBackX = 0;
    const int bBackY = 0;
    const int bBackW = 50;
    const int bBackH = 50;
    */
};

class Button
{
public:
    ButtonCoor buttoncoor;
    void getButtonPlay(SDL_Renderer* renderer); //upload play button
    void getButtonInstruction(SDL_Renderer* renderer); //upload instruction button
    void getButtonExit(SDL_Renderer* renderer);
};

#endif // BUTTONS_H_INCLUDED
