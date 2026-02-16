#include "classA.h"
#include <iostream>

classA::classA(){
    cout << "A default constructor\n";
}

classA::classA(const string&){
    cout << "A parameter constructor\n";
}

classA::~classA(){
    cout << "A destructor\n";
}