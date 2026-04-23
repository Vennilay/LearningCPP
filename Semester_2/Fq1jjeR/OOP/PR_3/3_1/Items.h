#ifndef __ITEMS__H
#define __ITEMS__H

#include <string>

using namespace std;

class Items{
    string name;
    int durability;

public:
    Items();
    Items(string n, int d);
    Items(const Items& other);
    ~Items();
    void increaseDurability(int value);
    void decreaseDurability(int value);
    string getName();
    int getDurability();
};

void repairItem(Items& obj);
void damageItem(Items obj);
Items* createBrokenItem(int work);

#endif
