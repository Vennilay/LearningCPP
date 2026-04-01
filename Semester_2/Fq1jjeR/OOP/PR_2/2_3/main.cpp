#include <iostream>
#include <string>
#include <Character.h>
#include <Healer.h>

using namespace std;

int main()
{
    string name;
    int health, mana;

    cin >> name >> health >> mana;

    Character hero(name, health, mana);

    printCharacter(hero);

    Healer healer;
    healer.heal(hero);

    printCharacter(hero);

    return(0);
}
