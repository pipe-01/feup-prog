#include "player.h"

Player::Player(unsigned int x, unsigned int y){
    p = Position(x,y);
    state = true;
}

bool Player::isOut()
{
    return out;
}

void Player::gotOut()
{
    out = true;
}

bool Player::getState()
{
    return state;
}

void Player::killObj()
{
    state = false;
}

int Player::getX()
{
    return p.x;
}

void Player::setX(unsigned int i)
{
    p.x = i;
}

int Player::getY()
{
    return p.y;
}

void Player::setY(unsigned int j)
{
    p.y = j;
}

void Player::moveUp()
{
    p.x--;
}

void Player::moveDown()
{
    p.x++;
}

void Player::moveRight()
{
    p.y++;
}

void Player::moveLeft()
{
    p.y--;
}

Position Player::getPosition()
{
    return p;
}

