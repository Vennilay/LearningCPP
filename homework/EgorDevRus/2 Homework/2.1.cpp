#include <iostream>
#include <cmath>
#include<windows.h>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float x, a, w;
    cout << "Введите x: "; cin >> x;
    cout << "Введите a: "; cin >> a;
    if (abs(x) < 1 && x!=0) {
        w = a * log(abs(x));
        cout << w;
    }
    else if (abs(x) >= 1 && (a-pow(x,2)>=0)) {
        w = sqrt(a - pow(x, 2));
        cout << w;
    }
    else {

        cout << "Нет решений";
    }

    return 0;
}
