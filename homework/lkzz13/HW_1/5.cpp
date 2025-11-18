//1.5
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double s,p,n,r;
    cin >> s >>p >>n;
    r=p/100;
    if ((pow(1+r,n)-1)<0) {
        cout << "не возможно вычилсить"<<endl;
    }else {
        cout <<"m = " <<(s*r*pow(1+r,n))/(12*(pow(1+r,n)-1))<<endl;
    }
}