/*******************************************************************************
 Filename:                  TranComp.cpp
 Classname:                 TranComp

 Description:               This file defines the TranComp class.

 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "TranComp.h"

/*******************************************************************************
 Name:              TranComp
 Description:       Default constructor for TranComp class
 ******************************************************************************/
TranComp::TranComp() : Component(TRANCOMP)
{
    pos.x = 0;
    pos.y = 0;
    pos.w = 0;
    pos.h = 0;
}

/*******************************************************************************
 Name:              TranComp
 Description:       Copy constructor for TranComp class
 ******************************************************************************/
TranComp::TranComp(const TranComp& other): Component(TRANCOMP)
{
    pos = other.pos;
}

/*******************************************************************************
 Name:              ~TranComp
 Description:       Destructor for TranComp class
 ******************************************************************************/
TranComp::~TranComp()
{

}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for TranComp class

 Input:
 other           const TranComp&
 ******************************************************************************/
TranComp TranComp::operator=(const TranComp& other)
{
    if(&other != this)
    {
        pos = other.pos;
    }

    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getPos
 ******************************************************************************/
SDL_Rect TranComp::getPos()
{
    return pos;
}

/*******************************************************************************
 Name:              load
 Description:       This method loads the TranComp

 Input:
    file            fstream& from which to load the TranComp

 Output:
    returns         bool value of whether the TranComp loaded correctly
 ******************************************************************************/
bool TranComp::load(fstream& file)
{
    if(!file) return false;

    //load pos
    file.read(reinterpret_cast<char*>(&pos.x), sizeof(pos.x));
    file.read(reinterpret_cast<char*>(&pos.y), sizeof(pos.y));
    file.read(reinterpret_cast<char*>(&pos.w), sizeof(pos.w));
    file.read(reinterpret_cast<char*>(&pos.h), sizeof(pos.h));

    return true;
}

/*******************************************************************************
 Name:              save
 Description:       This method saves the current state of the component

 Output:
    returns         bool representing the success of the save
 ******************************************************************************/
bool TranComp::save(fstream& file)
{
    if(!file) return false;

    //write pos
    file.write(reinterpret_cast<char*>(&pos.x), sizeof(pos.x));
    file.write(reinterpret_cast<char*>(&pos.y), sizeof(pos.y));
    file.write(reinterpret_cast<char*>(&pos.w), sizeof(pos.w));
    file.write(reinterpret_cast<char*>(&pos.h), sizeof(pos.h));

    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the TranComp
 ******************************************************************************/
GameState TranComp::update()
{
    GameState temp;
    temp.eleState = 0;
    temp.roomNum = -1;
    return temp;
}


