#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int l = 170, h = 25, CountPI = 3;
    double step = CountPI * M_PI / l, y = 0.5;
    int midY = h / 2;
    int midX = l / 2;
    cout << "График функции y = sin(x)" << endl;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            double x = j * step;
            if (CountPI % 2 == 0) {
                y = sin(x);
            }
            else {
                y = cos(x);
            }
            int yPos = round(midY - y * 10);

            if (i == midY and j == midX)
                cout << "+";
            else if (i == midY)
                cout << "-";
            else if (j == midX)
                cout << "|";
            else if (i == yPos)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}