#include <iostream>
#include <cmath>
using namespace std;

main() {
    cout << "Введите x: ";
    double x, a;
    cin >> x;
    cout << "Введите a: ";
    cin >> a;
    if(abs(x) < 1) {
        if(x != 0) {
            cout << "a*ln|x| = " << a*log(abs(x));
        }
        else{
            cout<<"x=0";
        }
    } else if(pow(x, 2) > a) {
        cout << "Подкоренное выражение меньше нуля";
    } else {
        cout << "sqrt(a-x²) = " << pow(a - pow(x, 2), 0.5);
    }
}