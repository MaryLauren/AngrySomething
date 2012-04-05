/*******************************************************************************
 Filename:                  PhysicsEngine.h
 Classname:                 PhysicsEngine
 
 Description:               This file declares the PhysicsEngine class. The 
                            PhysicsEngine class is responsible for moving
                            objects and detecting collisions within the room.
 ******************************************************************************/

#ifndef AngrySomething_PhysicsEngine_h
#define AngrySomething_PhysicsEngine_h

#include <SDL/SDL.h>

#include "Room.h"
#include "PhysicalObject.h"     //included in .h for vect

enum side
{
    TOP             = 1,
    TOP_RIGHT       = 2,
    RIGHT           = 3,
    BOTTOM_RIGHT    = 4,
    BOTTOM          = 5,
    BOTTOM_LEFT     = 6,
    LEFT            = 7,
    TOP_LEFT        = 8
};

class PhysicsEngine
{
    public:
        PhysicsEngine();
        ~PhysicsEngine();
    
        void run(Room& room);
    
    private:
        void runObjects(Room& room);
        void detectCollisions(Room& room);
    
        void handleWallCollision(PhysicalObject* pObj);
        bool doIntersect(SDL_Rect a, SDL_Rect b);
        bool doCollide(PhysicalObject* a, PhysicalObject* b);
        int  sideOfCollision(PhysicalObject* obj, PhysicalObject* obj2);
        void handleCollision(PhysicalObject* obj, PhysicalObject* obj2, int side);
};

#endif