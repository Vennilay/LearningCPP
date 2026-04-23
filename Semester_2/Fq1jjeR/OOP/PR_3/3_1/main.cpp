#include <iostream>
#include <string>
#include "Items.h"

using namespace std;

int main()
{
    string n;
    int d, w;
    cin >> n >> d >> w;
    Items obj(n, d);

    repairItem(obj);
    cout << "After repair: " << obj.getName()
        << " durability = " << obj.getDurability()
        << endl;

    damageItem(obj);
    cout << "After damage: " << obj.getName()
        << " durability = " << obj.getDurability()
        << endl;

    Items* itemPtr = createBrokenItem(w);
    if (itemPtr == nullptr)
        cout << "Broken pointer is nullptr";

    else
        cout << "Broken item: " << itemPtr -> getName()
        << "durability = " << itemPtr -> getDurability()
        << endl;

    delete itemPtr;
    return(0);
}
