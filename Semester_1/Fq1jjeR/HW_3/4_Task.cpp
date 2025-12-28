#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;


int division(int a, int b) {

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int subtraction(int a, int b) {

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int a, b, c;

    cout << "Введите первое число:";
    cin >> a;
    cout << "Введите второе число:";
    cin >> b;

    if (a == 0 && b == 0){
        cout << "НОД не определён";
        return 1;
    }

    cout << "Введите способ нахождения(0 - делением, 1 - вычитанием):";
    cin >> c;

    if (c == 0)
        cout << "НОД: " << division(a, b);
    else
        cout << "НОД: " << subtraction(a, b);
}