#ifndef PIG_H
#define PIG_H
#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MechanicsObject.h"

class Pig : public DrawableObject, public PhysicalObject, public MechanicsObject
{
    private:
        int health;
    public:
        Pig(const char* file, int x, int y, int vx, int vy);
        Pig(const Pig& other);
        ~Pig();

        Pig&     operator=(const Pig& other);

        virtual void    run();
        void            applyForce(int m, Vect v, int dir);

};

#endif // PIG_H
