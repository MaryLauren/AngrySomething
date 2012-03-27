/*******************************************************************************
 Filename:                  Game.h
 Classname:                 Game
 
 Description:               This file declares the Game class. This class will
                            be the controller for the game. It is in charge of
                            running the game loop and handling communication
                            between the Room and the View
 ******************************************************************************/

#ifndef AngrySomething_Game_h
#define AngrySomething_Game_h

#include <fstream>
#include <SDL/SDL.h>

#include "Base.h"

class Room;
class View;

using namespace std;

class Game : public Base
{
    private:
        Room *room;
        View *view;
        bool running;
    
    public:
        Game();
        Game(const Game&);
        ~Game();
    
        Game    operator=(const Game& other);
    
        Room*   getRoom();
        View*   getView();
        bool    getRunning();
    
        void    init(int roomNum = 0);
        bool    save();
        int     run();
};

#endif
