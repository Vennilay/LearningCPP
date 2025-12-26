#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n; // N - количество мест
    int k_count; // K - количество школьников

    if (!(cin >> n >> k_count) || cin.peek() == '.' || cin.peek() == ',') {
        return -1;
    }

    vector<long long> occupied_seats;
    occupied_seats.push_back(0);      // Левая граница
    occupied_seats.push_back(n + 1);  // Правая граница

    for (int k = 0; k < k_count; ++k) {
        long long max_d = -1;      // max_distance
        long long best_left_idx = -1;
        long long best_new_seat = -1;

        // Находим наибольший промежуток
        for (int i = 0; i < occupied_seats.size() - 1; ++i) {
            long long current_gap = occupied_seats[i + 1] - occupied_seats[i] - 1;

            // Замена max()
            if (current_gap > max_d) {
                max_d = current_gap;
                best_left_idx = i;
            }
        }

        // Вычисляем новое место в середине наибольшего промежутка
        long long gap_len = occupied_seats[best_left_idx + 1] - occupied_seats[best_left_idx];
        best_new_seat = occupied_seats[best_left_idx] + (gap_len / 2);

        // Вставляем новое занятое место, сохраняя сортировку
        occupied_seats.insert(occupied_seats.begin() + best_left_idx + 1, best_new_seat);

        // Если это последний школьник, выводим результат
        if (k == k_count - 1) {
            long long left_gap = best_new_seat - occupied_seats[best_left_idx] - 1;
            long long right_gap = occupied_seats[best_left_idx + 2] - best_new_seat - 1;

            long long min_gap = (left_gap < right_gap) ? left_gap : right_gap;
            long long max_gap = (left_gap > right_gap) ? left_gap : right_gap;

            cout << min_gap << endl << max_gap;
        }
    }
}
