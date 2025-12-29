#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<bool> is_free(55, false);

    int N; cin >> N;
    if (!N) return 1;

    for (int i = 0; i < N; ++i) {
        int seat_num; cin >> seat_num;
        if (seat_num > 54 || seat_num <= 0) {
            return 2;
        }
        is_free[seat_num] = true;
    }

    int max_consecutive_free_compartments = 0;
    int current_consecutive_free_compartments = 0;

    for (int compartment_num = 1; compartment_num <= 9; ++compartment_num) {
        int main_start = (compartment_num - 1) * 4 + 1;
        int main_end = main_start + 3;
        int side_start = 54 - (compartment_num - 1) * 2 - 1;
        int side_end = 54 - (compartment_num - 1) * 2;

        bool all_free = true;
        for (int j = main_start; j <= main_end; ++j) {
            if (!is_free[j]) all_free = false;
        }
        for (int j = side_start; j <= side_end; ++j) {
            if (!is_free[j]) all_free = false;
        }

        if (all_free) {
            current_consecutive_free_compartments++;
        } else {
            max_consecutive_free_compartments = max(max_consecutive_free_compartments, current_consecutive_free_compartments);
            current_consecutive_free_compartments = 0;
        }
    }
    max_consecutive_free_compartments = max(max_consecutive_free_compartments, current_consecutive_free_compartments);

    cout << max_consecutive_free_compartments << endl;
    return 0;
}
