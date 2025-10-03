#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double numberA = 0;
    double numberB = 0;
    double numberC = 0;

    cout << "Введите число A: " << endl;
    cin >> numberA;
    cout << "Введите число B: " << endl;
    cin >> numberB;
    cout << "Введите число C: " << endl;
    cin >> numberC;

    if (numberA == 0) {
        if (numberB == 0) {
            if (numberC == 0) {
                cout << "Бесконечно много решений (любое x)" << endl;
            } else {
                cout << "Решений нет (тк: " << numberC << " != 0)" << endl;
            }
        } else {
            double x = -numberC / numberB;
            cout << "Линейное уравнение. Решение: x = " << x << endl;
        }
    }
    else {
        double discriminant = numberB * numberB - 4 * numberA * numberC;

        cout << "Дискриминант D = " << discriminant << endl;

        if (discriminant < 0) {
            cout << "Действительных корней нет (D < 0)" << endl;
        }
        else if (discriminant == 0) {
            double x = -numberB / (2 * numberA);
            cout << "Один корень: x = " << x << endl;
        }
        else {
            double x1 = (-numberB + sqrt(discriminant)) / (2 * numberA);
            double x2 = (-numberB - sqrt(discriminant)) / (2 * numberA);
            cout << "Два корня:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
    return 0;
}
