#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    int k_count;

    cin >> n >> k_count;

    vector<long long> occupied_seats;
    occupied_seats.push_back(0);
    occupied_seats.push_back(n + 1);

    for (int k = 0; k < k_count; ++k) {
        long long max_d = -1;
        long long best_left_idx = -1;
        long long best_new_seat = -1;

        for (int i = 0; i < occupied_seats.size() - 1; ++i) {
            long long current_gap = occupied_seats[i + 1] - occupied_seats[i] - 1;

            if (current_gap > max_d) {
                max_d = current_gap;
                best_left_idx = i;
            }
        }


        long long gap_len = occupied_seats[best_left_idx + 1] - occupied_seats[best_left_idx];
        best_new_seat = occupied_seats[best_left_idx] + (gap_len / 2);

        occupied_seats.insert(occupied_seats.begin() + best_left_idx + 1, best_new_seat);

        if (k == k_count - 1) {
            long long left_gap = best_new_seat - occupied_seats[best_left_idx] - 1;
            long long right_gap = occupied_seats[best_left_idx + 2] - best_new_seat - 1;

            long long min_gap = (left_gap < right_gap) ? left_gap : right_gap;
            long long max_gap = (left_gap > right_gap) ? left_gap : right_gap;

            cout << min_gap << endl << max_gap;
        }
    }
}
