/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object

 Description:               This file declares the Object class.
 ******************************************************************************/

#ifndef AngrySomething_Object_h
#define AngrySomething_Object_h

#include <SDL/SDL.h>

class Object
{
    protected:
        SDL_Rect    pos;
        int         state;
        bool        drawable;
        bool        physical;
        bool        mechanical;
        int         type;   //1 = level, 2 = Utility

    public:
        Object(int x = 0, int y = 0, int w = 0, int h = 0);
        virtual ~Object();

        Object          operator=(const Object& other);
        void            setPos(SDL_Rect p);

        SDL_Rect        getPos();
        int             getState();
        int             getType();
        bool            isDrawable();
        bool            isPhysical();
        bool            isMechanical();

        virtual void    run();
};

#endif
