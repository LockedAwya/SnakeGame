#ifndef BUTTONS_H_INCLUDED
#define BUTTONS_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>

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
};

class Button
{
public:
    ButtonCoor buttoncoor;
    void LoadButtons(SDL_Renderer* renderer);
};

#endif // BUTTONS_H_INCLUDED
