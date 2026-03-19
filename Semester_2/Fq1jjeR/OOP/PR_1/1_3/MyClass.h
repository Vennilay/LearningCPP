#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    int openValue;

    void setHiddenValue(int hiddenValue);
    int getHiddenValue();
    void changeValues();

private:
    int hiddenValue;
};

#endif
