#ifndef __MYCLASS__H
#define __MYCLASS__H


class MyClass
{
public:
    int openValue;
private:
    int hiddenValue;

public:
    void setHiddenValue(int hiddenValue);
    int getHiddenValue();
    void changeValues();

};
#endif
