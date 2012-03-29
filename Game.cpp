/*******************************************************************************
 Filename:                  Game.cpp
 Classname:                 Game

 Description:               This file defines the Game class. This class will
                            be the controller for the game. It is in charge of
                            running the game loop and handling communication
                            between the Room and the View
 ******************************************************************************/

#include "Game.h"

Game::Game()
{
    running = false;
}

void Game::init()
{
    running = room.load();
}

int Game::run()
{
    while(running)
    {
        phys.run(room);
        grph.run(room);
    }

    return 0;
}

