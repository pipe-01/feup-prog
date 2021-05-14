#include "movable.h"

Robot::Robot(unsigned int x,unsigned int y, unsigned int n )
:id(n),Movable(x,y){}

Robot::~Robot()
{
    state = NULL;
}

Movable::getState()
{
    return this.state;
}

Movable::killObj()
{
    this.state = false;
}

Movable::getX()
{
    return this.x;
}

Movable::setX(int i)
{
    this.x = i;
}

Movable::getY()
{
    return this.y;
}

Movable::setY(int j)
{
    this.y = j;
}

Movable::moveUp()
{
    this.y--;
}

Movable::moveDown()
{
    this.y++;
}

Movable::moveRight()
{
    this.x++;
}

Movable::moveLeft()
{
    this.x--;
}

Player::Player(unsigned int x, unsigned int y)
:Movable(x,y){}

Player::~Player()
{
    state = NULL;
}