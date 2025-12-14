#include <iostream>

using namespace std;

int main() {
    long long a, b, c;

    cout << "Введите стоимость основания спиннера: ";
    cin >> a;

    cout << "Введите стоимость одной лопасти: ";
    cin >> b;

    cout << "Введите максимальную стоимость спиннера: ";
    cin >> c;

    cout << "Максимальное число лопастей: " << (c - a) / b << endl;

    return 0;
}
