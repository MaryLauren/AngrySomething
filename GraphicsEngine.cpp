/*******************************************************************************
 Filename:                  GraphicsEngine.cpp
 Classname:                 GraphicsEngine
 
 Description:               This file defines the GraphicsEngine class. The 
                            GraphicsEngine class is responsible for output to 
                            the screen.
 ******************************************************************************/

#include "GraphicsEngine.h"
#include "DrawableObject.h"
#include "Room.h"

/*******************************************************************************
 Name:              GraphicsEngine
 Description:       Default constructor for GraphicsEngine class
 ******************************************************************************/
GraphicsEngine::GraphicsEngine()
{
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
 
    if(!screen)
    {
        exit(-1);
    }
}

/*******************************************************************************
 Name:              GraphicsEngine
 Description:       Copy constructor for GraphicsEngine class
 
 Input:
    other           GraphicsEngine to be copied
 ******************************************************************************/
GraphicsEngine::GraphicsEngine(const GraphicsEngine& other)
{
    
}

/*******************************************************************************
 Name:              ~GraphicsEngine
 Description:       Deconstructor for GraphicsEngine class
 ******************************************************************************/
GraphicsEngine::~GraphicsEngine()
{
    SDL_FreeSurface(screen);
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for GraphicsEngine class
 
 Input:
    other           const GraphicsEngine&
 ******************************************************************************/
GraphicsEngine GraphicsEngine::operator=(const GraphicsEngine& other)
{
    if(&other != this)
    {
       
    }
    
    return *this;
}

/*******************************************************************************
 Name:              run
 Description:       This method updates the screen
 ******************************************************************************/
void GraphicsEngine::run(Room& room)
{
    for(int i = 0; i < room.getNumObjects(); i++)
    {
        room.getObjectAt(i)->draw(screen);
    }
    
    SDL_Flip(screen);
}
