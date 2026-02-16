#include "classB.h"
#include <iostream>

classB::classB(){
    cout << "B default constructor\n";
}

classB::classB(const string&){
    cout << "B parameter constructor\n";
}

classB::~classB(){
    cout << "B destructor\n";
}