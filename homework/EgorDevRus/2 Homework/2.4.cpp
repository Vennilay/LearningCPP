#include <windows.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float y;
    /*for (float x = -4; x <= 4; x += 0.5)
        if ((x - 1) == 0) {
            cout << "x: " << x << " " << "y: Деление на ноль" << endl;
        }
        else {
            y = (pow(x, 2) - 2 * x + 2) / (x - 1);
            cout << "x: " << x<<" "<< "y: " << y<<endl;
        }*/
    float x = -4;

    while (x <= 4) {
        if ((x - 1) == 0) {
            cout << "x: " << x << " " << "y: Деление на ноль" << endl;
        }
        else {
            y = (pow(x, 2) - 2 * x + 2) / (x - 1);
            cout << "x: " << x << " " << "y: " << y << endl;
        }
        x += 0.5;
    }


    return 0;
}
