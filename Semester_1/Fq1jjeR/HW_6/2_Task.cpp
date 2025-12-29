#include <iostream>

using namespace std;

int main() {
    long long M;

    cout << "Введите общее количество лопастей (M): ";
    cin >> M;

    long long count_4 = M % 3;

    if (4 * count_4 > M)
        cout << 0 << endl << 0;

    else {
        long long count_3 = (M - 4 * count_4) / 3;

        cout << "Спиннеров с 3 лопастями: " << count_3 << endl;
        cout << "Спиннеров с 4 лопастями: " << count_4 << endl;
    }

    return 0;
}
