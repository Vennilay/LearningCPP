#include <iostream>
using namespace std;

int main() {
    long long m;
    long long summ = 0, cf = 0, ct = 0;

    cout << "Введите M:";
    if (!(cin >> m)) {
        return 1;
    }

    if (m < 3) {
        cout << 0 << "\n" << 0 << endl;
        return 0;
    }

    bool found = false;
    for (cf = m / 4; cf >= 0; --cf) {
        summ = m - 4 * cf;
        if (summ % 3 == 0) {
            ct = summ / 3;
            found = true;
            break;
        }
    }

    if (found) {
        cout << ct << "\n" << cf << endl;
        cout << ct << "*3 + " << cf << "*4 = " << m << endl;
    } else {
        cout << 0 << " " << 0 << endl;
    }
    return 0;
}