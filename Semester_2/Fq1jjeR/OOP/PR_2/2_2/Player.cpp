#include "Player.h"

void Player::setHealth(int h){
    health = h;
}

int Player::getHealth() const {
    return health;
}

void Player::changeHealth(int value){
    health += value;
}