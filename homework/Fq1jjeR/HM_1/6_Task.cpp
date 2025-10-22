#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float h, R, r;

    cout << "h = ";
    cin >> h;

    cout << "R = ";
    cin >> R;

    cout << "r = ";
    cin >> r;

    float l = sqrt(h * h + (R - r) * (R - r));

    float V = (1.0 / 3.0) * 3.14 * h * ((R * R) + R * r + (r*r));
    float S = 3.14 * ((R * R) + (R + r) * l + (r * r));

    cout << "V = " << V << " " << "S = " << S;

}
