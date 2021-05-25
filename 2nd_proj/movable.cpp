#include "movable.h"

Robot::Robot(unsigned int x, unsigned int y, unsigned int n)
    : id(n), Movable(x, y) {}

Robot::~Robot()
{
    state = false;
}

void Robot::placeObj(vector<vector<char>> &tiles, const unsigned playerX, const unsigned playerY){
    int varX = x - playerX; 
    int varY = y - playerY;

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

char Player::checkCollision(vector<vector<char>> &tiles)
{
    if(tiles[getY()][getX()] == LIVEHUMAN){
        return '2';
    }
    else if (tiles[getY()][getX()] != ' ')
    {
        if (tiles[getY()][getX()]==EXITDOOR){
            gotOut();
            return '4';
        }
        else if (tiles[getY()][getX()] == '*' || tiles[getY()][getX()] == LIVEROBOT)
        {
            killObj();
            return '0';
        }
        else
        {
            if (tiles[getY()][getX()] == DEADROBOT || tiles[getY()][getX()] == NONELECPOST)
            {
                printDeadRobotCollision();
                return '1';
            }
            else
            {
                killObj();
                return '0';
            }
        }
    }
    else
    {
        return '2';
    }
}

void Player::placePlayer(vector<vector<char>> &tiles, const unsigned prevX, const unsigned prevY)
{
    tiles[prevY][prevX] = ' ';
    tiles[getY()][getX()] = LIVEHUMAN;
}