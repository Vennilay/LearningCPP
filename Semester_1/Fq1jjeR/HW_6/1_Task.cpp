#include <iostream>

using namespace std;

int main() {
    int A, B, C;

    cout << "Введите стоимость основания спиннера: ";
    cin >> A;

    cout << "Введите стоимость одной лопасти: ";
    cin >> B;

    cout << "Введите максимальную стоимость спиннера: ";
    cin >> C;

    cout << "Максимальное число лопастей: " << (C - A) / B << endl;

    return 0;
}
