//1.4
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cout << "X\t" << "Y"<<endl;
    for (double x=-4;x<=4;x+=0.5) {
        if (x-1==0) {
            cout <<x <<"\t"<<"Функция не определена" << endl;
        }else {
            cout << x<<"\t" << round(((pow(x,2)-2*x+2)/(x-1))*100)/100<<endl;
        }
    }
    return 0;
}