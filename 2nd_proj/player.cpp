#include "player.h"

void Player::setTime(unsigned i)
{
    time = i;
}

unsigned Player::getTime()
{
    return time;
}

Player::Player(unsigned int x, unsigned int y)
    : Movable(x, y), out(false) {}

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

