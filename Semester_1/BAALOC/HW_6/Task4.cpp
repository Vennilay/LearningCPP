#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Введите количество свободных мест: ";
    cin >> n;

    vector<bool> seats(55, false);

    cout << "Введите номера свободных мест (по одному):" << endl;
    for (int i = 0; i < n; ++i) {
        int seat;
        cin >> seat;
        seats[seat] = true;
    }

    int max_consecutive = 0;
    int current_consecutive = 0;

    for (int i = 0; i < 9; ++i) {
        int main_start = i * 4 + 1;
        int side_start = 54 - i * 2 - 1;

        bool is_full_compartment = true;

        for (int j = 0; j < 4; ++j) {
            if (!seats[main_start + j]) {
                is_full_compartment = false;
                break;
            }
        }

        if (is_full_compartment) {
            if (!seats[side_start] || !seats[side_start + 1]) {
                is_full_compartment = false;
            }
        }

        if (is_full_compartment) {
            current_consecutive++;
        } else {
            max_consecutive = max(max_consecutive, current_consecutive);
            current_consecutive = 0;
        }
    }

    max_consecutive = max(max_consecutive, current_consecutive);

    cout << "Максимальное число подряд идущих свободных купе: " << max_consecutive << endl;

    return 0;
}
