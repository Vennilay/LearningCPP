#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int var, s = 0;
    cout << "¬ведите вариант (1 или 2): "; cin >> var;
    if (var == 1) {
        int m = 37, i = 3, c = 64, g;
        cout << "¬ведите целое число: "; cin >> g;
        for (int n = 0; n < g; n++) {
            s = (m * s + i) % c;
        }
        cout << s << endl;
    }
    else {
        int m = 25173, i = 13849, c = 65537, g;
        cout << "¬ведите целое число: "; cin >> g;
        for (int n = 0; n < g; n++) {
            s = (m * s + i) % c;
        }
        cout << s << endl;
    }
    return 0;
}