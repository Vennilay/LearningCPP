#include <iostream>
#include <vector>

int main() {
    std::vector<bool> is_seat_free(55, false);

    int free_seats_count;
    std::cin >> free_seats_count;

    for (int i = 0; i < free_seats_count; ++i) {
        int seat_number;
        std::cin >> seat_number;
        is_seat_free[seat_number] = true;
    }

    int max_consecutive_coupes = 0;
    int current_consecutive_coupes = 0;

    for (int i = 0; i < 9; ++i) {
        const bool main_seats_are_free = is_seat_free[4 * i + 1] &&
                                   is_seat_free[4 * i + 2] && 
                                   is_seat_free[4 * i + 3] && 
                                   is_seat_free[4 * i + 4];

        const bool side_seats_are_free = is_seat_free[54 - 2 * i] &&
                                   is_seat_free[53 - 2 * i];

        if (main_seats_are_free && side_seats_are_free) {
            current_consecutive_coupes++;
            if (current_consecutive_coupes > max_consecutive_coupes) {
                max_consecutive_coupes = current_consecutive_coupes;
            }
        } else {
            current_consecutive_coupes = 0;
        }
    }44

    std::cout << max_consecutive_coupes << std::endl;

    return 0;
}
