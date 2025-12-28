#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double y;


    cout << "|===========|==============|" << endl;
    cout << "|     x     |       y      |" << endl;
    cout << "|===========|==============|" << endl;

    for (float x = -4.0; x <= 4.0; x += 0.5) {
        y = ((x * x) - 2 * x + 2) / (x - 1);

        cout << "|";
        cout.width(9); cout.precision(3); cout << x << "  |";

        if (x != 1) {
            cout.width(13); cout.precision(3); cout << y << " |" << endl;
        }
        else {
            cout.width(13); cout << "не определена |" << endl;
        }
    }

    cout << "|===========|==============|" << endl;
}
