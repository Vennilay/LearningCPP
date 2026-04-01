#ifndef __CHARACTER__H
#define __CHARACTER__H

#include <string>

class Healer;

class Character {
private:
    std::string name;
    int health;
    int mana;

    friend void printCharacter(const Character& c);
    friend class Healer;

public:
    Character(const std::string& n, int h, int m);

};

void printCharacter(const Character& c);

#endif
