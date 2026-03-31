#ifndef __S__H
#define __S__H

struct S{
    int publicProp;
    void setPrivate(int x);
    int getPrivate();

private:
    int privateProp;
};

#endif