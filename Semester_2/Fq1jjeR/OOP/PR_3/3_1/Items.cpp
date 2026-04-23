#include "Items.h"

#include <iostream>

using namespace std;

Items::Items(){
    name = "Unknown";
    durability = 0;
    cout << "Item (Cnstr): " << name << endl;

}

Items::Items(string n, int d){
    name = n;
    durability = d;
    cout << "Item (ParamCnstr): " << name << endl;

}

Items::Items(const Items& other){
    name = other.name;
    durability = other.durability;
    cout << " Item (CopyCnstr): " << name << endl;
}

Items::~Items(){ cout << "~Item (Dcnstr): " << name << endl; }

void Items::increaseDurability(int value){ durability += value;}

void Items::decreaseDurability(int value){ durability -= value;}

string Items::getName(){ return name; }

int Items::getDurability(){ return durability; }

void repairItem(Items& obj){ obj.increaseDurability(10);}

void damageItem(Items obj){
    obj.decreaseDurability(5);
    cout << "Inside damageItem: " << obj.getName()
        << "durability = " << obj.getDurability() << endl;

}

Items* createBrokenItem(int work){
    if( work == 0){
        return nullptr;
    }
    else{
        Items *obj = new Items("Broken", 0);
        return obj;
    }
}