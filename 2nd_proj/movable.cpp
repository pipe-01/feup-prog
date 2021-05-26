#include "movable.h"

bool Movable::getState()
{
    return state;
}

void Movable::killObj()
{
    state = false;
}

int Movable::getX()
{
    return p.x;
}

void Movable::setX(unsigned int i)
{
    p.x = i;
}

int Movable::getY()
{
    return p.y;
}

void Movable::setY(unsigned int j)
{
    p.y = j;
}

void Movable::moveUp()
{
    p.y--;
}

void Movable::moveDown()
{
    p.y++;
}

void Movable::moveRight()
{
    p.x++;
}

void Movable::moveLeft()
{
    p.x--;
}

Position Movable::getPosition(){
    return p;
}




