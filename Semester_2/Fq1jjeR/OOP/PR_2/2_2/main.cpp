#include <iostream>
#include "Player.h"
using namespace std;

void modifyByPointer(Player* p){
    if (p -> getHealth() < 50){
        p -> changeHealth(10);
    }
    else{
        p -> changeHealth(-5);
    }
}

void modifyByValue(Player p){
    if (p.getHealth() < 50){
        p.changeHealth(10);
    }
    else{
        p.changeHealth(-5);
    }
}

int main()
{
    int initialHealth;
    cin >> initialHealth;

    Player* playerPtr = new Player();

    playerPtr -> setHealth(initialHealth);

    modifyByPointer(playerPtr);

    modifyByValue(*playerPtr);

    cout << "HealthPoint: " << playerPtr->getHealth() << endl;

    delete playerPtr;

    return(0);
}
