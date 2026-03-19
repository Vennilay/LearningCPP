#include <iostream>
#include "MyClass.h"

using namespace std;

int main()
{
    MyClass obj;
    int firstNum, secondNum;

    cin >> firstNum >> secondNum;

    obj.openValue = firstNum;
    obj.setHiddenValue(secondNum);
    obj.changeValues();

    cout << "Open value: " << obj.openValue << endl;
    cout << "Hidden value: " << obj.getHiddenValue() << endl;

    return 0;
}
