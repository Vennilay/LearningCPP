#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Введите количество свободных мест: ";
    cin >> n;

    vector<bool> a(55, false);

    cout << "Введите номера свободных мест (по одному):" << endl;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = true;
    }

    int max_k = 0;
    int k = 0;

    for (int i = 0; i < 9; ++i) {
        int p1 = i * 4 + 1;
        int p2 = 54 - i * 2 - 1;

        bool ok = true;

        for (int j = 0; j < 4; ++j) {
            if (!a[p1 + j]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            if (!a[p2] || !a[p2 + 1]) {
                ok = false;
            }
        }

        if (ok) {
            k++;
        } else {
            max_k = max(max_k, k);
            k = 0;
        }
    }

    max_k = max(max_k, k);

    cout << "Максимальное число подряд идущих свободных купе: " << max_k << endl;

    return 0;
}
