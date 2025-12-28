//3.5
#include <iostream>
using namespace  std;
int prostoe(int a) {
    bool prost=false;
    int del=0;
    for (int j=1;j<=a;j++) {
        if (a%j==0) {
                del++;
        }
    }
    if (del==2) {
        prost=true;
    }else {
        prost=false;
    }
    return prost;
}
int main() {
    int a;
    cin >> a;
    for (int i=2;i<=a;i++) {
        if (prostoe(i)==true) {
            cout <<i<<" ";
        }
    }
    return 0;
}