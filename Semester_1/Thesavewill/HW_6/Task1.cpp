#include <iostream>
#include <windows.h>
#include <algorithm> // Для использования функции std::max, хотя она здесь не нужна

using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    long long a, b, c;

    if (!(cin >> a >> b >> c)) {
        return 1;
    }
    if (a > c) {
        cout << "A должно быть меньше либо равно C";
        return 2;
    }

    long long max_n = (c - a) / b;
    cout << max_n;

    return 0;
}