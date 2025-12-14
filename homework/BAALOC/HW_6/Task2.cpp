#include <iostream>

using namespace std;

int main() {
    long long m;

    cout << "Введите общее количество лопастей (M): ";
    cin >> m;

    long long cnt4 = m % 3;

    if (4 * cnt4 > m) {
        cout << "Невозможно собрать спиннеры" << endl;
    } else {
        long long cnt3 = (m - 4 * cnt4) / 3;
        cout << "Спиннеров с 3 лопастями: " << cnt3 << endl;
        cout << "Спиннеров с 4 лопастями: " << cnt4 << endl;
    }

    return 0;
}
