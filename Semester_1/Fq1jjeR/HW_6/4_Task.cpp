#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> free_seats;
    for (int i = 0; i < n; ++i) {
        int seat_num;
        cin >> seat_num;
        free_seats.insert(seat_num);
    }

    int max_c = 0;
    int cur_c = 0;
    int main_start;
    int main_end;
    int side1;
    int side2;

    for (int k = 1; k <= 9; ++k) {
        main_start = 4 * (k - 1) + 1;
        main_end = 4 * k;
        side1 = 54 - 2 * (k - 1);
        side2 = 53 - 2 * (k - 1);

        bool is_c_free = true;
        for (int s = main_start; s <= main_end; ++s) {
            if (free_seats.find(s) == free_seats.end()) {
                is_c_free = false;
                break;
            }
        }

        if (is_c_free) {
            if (free_seats.find(side1) == free_seats.end() || free_seats.find(side2) == free_seats.end())
                is_c_free = false;
        }

        if (is_c_free)
            cur_c++;

        else {
            max_c = (cur_c > max_c) ? cur_c : max_c;
            cur_c = 0;
        }
    }

    max_c = (cur_c > max_c) ? cur_c : max_c;

    cout << max_c << endl;
}
