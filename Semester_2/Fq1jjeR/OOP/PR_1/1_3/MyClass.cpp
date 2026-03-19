#include "MyClass.h"

void MyClass::setHiddenValue(int hiddenValue)
{
    this->hiddenValue = hiddenValue;
}

int MyClass::getHiddenValue()
{
    return hiddenValue;
}

void MyClass::changeValues()
{
    if (openValue % 2 == 0) {
        openValue /= 2;
    } else {
        openValue *= 2;
    }

    if (hiddenValue % 2 == 0) {
        hiddenValue /= 2;
    } else {
        hiddenValue *= 2;
    }
}
