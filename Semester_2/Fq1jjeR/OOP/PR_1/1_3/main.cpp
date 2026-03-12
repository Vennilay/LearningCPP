#include <iostream>
#include "MyClass.h"

using namespace std;

int main()
{
    MyClass obj;
    int firstNum, secondNum;

    if(!(cin >> firstNum >> secondNum)){
        return 1;
    }

    obj.openValue = firstNum;
    obj.setHiddenValue(secondNum);
    obj.changeValues();

    cout << "Open value: " << obj.openValue << endl;
    cout << "Hidden value: " << obj.getHiddenValue() << endl;

    return(0);
}
