#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    double y, x = -4;
    while (x <= 4) {
        if (x == 1) {
            cout << "При x = 1, функция в этой точке не существует" << endl;
        }
        else {
            y = (pow(x, 2) - 2 * x + 2) / (x - 1);
            cout << "При x = " << x << ", y = " << y << endl;
        }
        x = x + 0.5;
    }
	return 0;
}