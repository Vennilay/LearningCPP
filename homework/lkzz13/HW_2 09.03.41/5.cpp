//2.5
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double s, p, n,r;
    cin >>s>>p >>n;
    r=p/100;
    if (p == 0) {
        cout << "m = " << s /(n*12) << endl;
    }
    else if ((pow(1+r,n)-1) <= 0) {
        cout << "не возможно вычислить" << endl;
    }
    else {
        cout << "m = " << (s*r*pow(1+r,n))/(12*(pow(1+r,n)-1))<<endl;
    }
    return 0;
}