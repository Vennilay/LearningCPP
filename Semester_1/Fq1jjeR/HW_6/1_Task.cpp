#include <iostream>

using namespace std;

int main() {
    long long A, B, C;

    cout << "Введите стоимость основания спиннера: ";
    cin >> A;

    cout << "Введите стоимость одной лопасти: ";
    cin >> B;

    cout << "Введите максимальную стоимость спиннера: ";
    cin >> C;

    if (A < 0 || B <= 0 || C < 0) {
        cout << "Ошибка: Цены не могут быть отрицательными, а B должно быть > 0." << endl;
        return 1;
    }

    cout << "Максимальное число лопастей: " << (C - A) / B << endl;

    return 0;
}
