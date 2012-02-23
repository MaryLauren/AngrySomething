/*******************************************************************************
 Filename:                  Game.cpp
 Classname:                 Game
 
 Description:               This file defines the Game class. This class will
                            be the controller for the game. It is in charge of
                            running the game loop and handling communication
                            between the Room and the View
 
 Last Modified:            				02.04.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "Game.h"

/*******************************************************************************
 Name:              Game
 Description:       Default constructor for Game class
 ******************************************************************************/
Game::Game() : Base("game")
{
    room = new Room;
    view = new View("bgtest.bmp");
}

/*******************************************************************************
 Name:              Game
 Description:       Copy constructor for Game class
 
 Input:
    other           Game object to be copied
 ******************************************************************************/
Game::Game(const Game& other) : Base("game")
{
    running = other.running;
    *room = *(other.room);
    *view = *(other.view);
}

/*******************************************************************************
 Name:              ~Game
 Description:       Destructor for Game class
 ******************************************************************************/
Game::~Game()
{
    if(room) delete room;
    if(view) delete view;
    
    SDL_Quit();
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for Game class
 
 Input:
    other           const Game&
 ******************************************************************************/
Game Game::operator=(const Game& other)
{
    if(&other != this)
    {
        running = other.running;
        *room = *(other.room);
        *view = *(other.view);
    }
    
    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getRoom, getView, getRunning
 ******************************************************************************/
Room* Game::getRoom()
{
    return room;
}

View* Game::getView()
{
    return view;
}

bool Game::getRunning()
{
    return running;
}

/*******************************************************************************
 Name:              init
 Description:       This method handles any initialization involved before the
 run loop begins
 Output:
 returns         boolean value representing if the game initialized correctly
 ******************************************************************************/
bool Game::init()
{
    return true;
}

/*******************************************************************************
 Name:              run
 Description:       This method starts the game and controls the game loop
 
 Output:
    returns         int value representing the exit state of the game
 ******************************************************************************/
int Game::run()
{
    running = init();
    
    SDL_Event event;
    
    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            handleEvent(&event);
        }
        
        for(int i = 0; i < room->getNumObjects(); i++)
        {
            (room->getObjectAt(i)).update();
            
            if((room->getObjectAt(i)).getNeedsUpdate())
            {
                view->draw(room->getObjectAt(i));
            }
        }
        
        view->update();
    }
    
    return 0;
}

/*******************************************************************************
 Name:              handleEvent
 Description:       This method handles event in the game loop. If the event
                    does not affect the game as a whole, it is tested against
                    the individual objects within the game
 
 Input:
    event           SDL_Event*
 ******************************************************************************/
void Game::handleEvent(SDL_Event* event)
{
    if(event->type == SDL_QUIT)
    {
        running = false; //Exit run loop
    }
}
