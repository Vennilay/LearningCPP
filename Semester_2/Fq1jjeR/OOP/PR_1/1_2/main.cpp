#include "classA.h"
#include "classB.h"

int main()
{
    {
        classA a1;
        classA a2("Hello Word!");
    }

    classB *b1 = new classB();
    classB *b2 = new classB("Hello Word!");

    delete b1;
    delete b2;

    return(0);
}