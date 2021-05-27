#include "robot.h"
#include <iostream>

Robot::Robot(unsigned int x, unsigned int y)
    : p(Position(x,y)),state(true), id(++staticId){}

Robot::~Robot()
{
    state = false;
}

int Robot::staticId = 0;

int Robot::getId(){
    return id;
}

void Robot::moveRobot(struct Position pos){
    int varX = p.x - pos.x; 
    int varY = p.y - pos.y;
    std::cout << varX << varY;
    if (varX > ZERO)
    {
        moveLeft();
    }
    else if (varX < ZERO)
    {
        moveRight();
    }
    if (varY > ZERO)
    {
        moveUp();
    }
    else if (varY < ZERO)
    {
        moveDown();
    }
}

bool Robot::getState()
{
    return state;
}

void Robot::killObj()
{
    state = false;
}

int Robot::getX() const
{
    return this->p.x;
}

void Robot::setX(unsigned int i)
{
    p.x = i;
}

int Robot::getY() const
{
    return p.y;
}

void Robot::setY(unsigned int j)
{
    p.y = j;
}

void Robot::moveUp()
{
    p.y--;
}

void Robot::moveDown()
{
    p.y++;
}

void Robot::moveRight()
{
    p.x++;
}

void Robot::moveLeft()
{
    p.x--;
}

Position Robot::getPosition()
{
    return p;
}

