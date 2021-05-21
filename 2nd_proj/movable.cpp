#include "movable.h"

Robot::Robot(unsigned int x, unsigned int y, unsigned int n)
    : id(n), Movable(x, y) {}

Robot::~Robot()
{
    state = false;
}

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
    return x;
}

void Movable::setX(unsigned int i)
{
    x = i;
}

int Movable::getY()
{
    return y;
}

void Movable::setY(unsigned int j)
{
    y = j;
}

void Movable::moveUp()
{
    y--;
}

void Movable::moveDown()
{
    y++;
}

void Movable::moveRight()
{
    x++;
}

void Movable::moveLeft()
{
    x--;
}

void Player::setTime(unsigned i)
{
    time = i;
}

unsigned Player::getTime()
{
    return time;
}

Player::Player(unsigned int x, unsigned int y)
    : Movable(x, y) , out(false){}

Player::~Player()
{
    state = false;
    x = 0;
    y = 0;
}

bool Player::isOut()
{
    return out;
}

void Player::gotOut()
{
    out = true;
}
