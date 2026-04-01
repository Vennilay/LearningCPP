#include "Healer.h"

void Healer::heal(Character& c){
    c.health += 20;
    c.mana += 10;
}