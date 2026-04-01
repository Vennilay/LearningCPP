#include "Character.h"
#include <iostream>

Character::Character(const std::string& n, int h, int m)
    :name(n), health(h), mana(m){}

void printCharacter(const Character& c){
    std::cout << "Hero: " << c.name << " | Health = " << c.health << " | Mana = " << c.mana << std::endl;
}