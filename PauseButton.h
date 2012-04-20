#ifndef PAUSEBUTTON_H_INCLUDED
#define PAUSEBUTTON_H_INCLUDED

#include <SDL/SDL.h>

#include "DrawableObject.h"
#include "MechanicsObject.h"

#include "ClickableObject.h"

#include <string>

using namespace std;

class PauseButton : public DrawableObject, public MechanicsObject, public ControllableObject
{
    private:
        ClickableObject* button1;
        ClickableObject* button2;
        ClickableObject* button3;
        ClickableObject* Unpause;

    public:
        PauseButton(const char* file, int x, int y, int w, int h);
        ~PauseButton();

        void        draw(SDL_Surface*);
        void        handle(SDL_Event);
};

#endif // PAUSEBUTTON_H_INCLUDED