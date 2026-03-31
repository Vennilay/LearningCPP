#include "S.h"

void S::setPrivate(int x){
    x = x * 2;
    privateProp = x;
}
int S::getPrivate() {
    return privateProp;
}
