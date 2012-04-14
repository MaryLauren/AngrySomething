/*******************************************************************************
 Filename:                  Room.cpp
 Classname:                 Room

 Description:               This file defines the Room class.
 ******************************************************************************/

#include "Room.h"
#include "Object.h"
#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MultiObject.h"
#include "Sling.h"
#include "Wall.h"
#include "Pig.h"

/*******************************************************************************
 Name:              Room
 Description:       Default constructor for Room class
 ******************************************************************************/
Room::Room()
{

}

/*******************************************************************************
 Name:              Room
 Description:       Copy constructor for Room class

 Input:
    other           Room object to be copied
 ******************************************************************************/
Room::Room(const Room& other)
{

}

/*******************************************************************************
 Name:              ~Room
 Description:       Destructor for Room class
 ******************************************************************************/
Room::~Room()
{

}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for Room class

 Input:
    other           const Room&
 ******************************************************************************/
Room Room::operator=(const Room& other)
{
    if(&other != this)
    {

    }

    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getObjectAt, getNumObjects
 ******************************************************************************/
Object* Room::getObjectAt(int i)
{
    return object[i];
}

int Room::getNumObjects()
{
    return (int)object.size();
}

void Room::remove(int i)
{
    object.erase(object.begin()+i);
}
/*******************************************************************************
 Name:              load
 Description:       This method dynamically allocates and loads objects in the
                    room

 Output:
    returns         bool value of whether the component loaded correctly
 ******************************************************************************/
bool Room::load()
{
    object.push_back(new Sling("Stretchy.bmp", 100, 350, "NNNNNNNNNNNNNNNN"));
    object.push_back(new Projectile("Proj.bmp", 100, 415, 0, 0));
    object.push_back(new Projectile("Proj.bmp", 400, 415, -7, 0));
    object.push_back(new Projectile("Proj.bmp", 230, 415, 8, 0));
//    object.push_back(new Pig("TestB.bmp",  425, 440, 0, 0));
//    object.push_back(new Pig("TestB.bmp",  495, 440, 0, 0));
//    object.push_back(new Pig("TestB.bmp",  460, 340, 0, 0));
//    object.push_back(new Wall("TestC.bmp", 400, 400, 0, 0, 20, 80));
//    object.push_back(new Wall("TestC.bmp", 470, 400, 0, 0, 20, 80));
//    object.push_back(new Wall("TestC.bmp", 540, 400, 0, 0, 20, 80));
//    object.push_back(new Wall("TestC.bmp", 400, 380, 0, 0, 80, 20));
//    object.push_back(new Wall("TestC.bmp", 480, 380, 0, 0, 80, 20));
//    object.push_back(new Wall("TestC.bmp", 430, 300, 0, 0, 20, 80));
//    object.push_back(new Wall("TestC.bmp", 510, 300, 0, 0, 20, 80));
//    object.push_back(new Wall("TestC.bmp", 440, 270, 0, 0, 80, 20));

    return true;
}

void Room::add(Object* obj)
{
    object.push_back(obj);
}
