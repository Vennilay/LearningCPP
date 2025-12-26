#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h> // Необходим для функций SetConsoleCP и SetConsoleOutputCP
using namespace std;

int main() {
    // Настройка кодировки консоли для корректного вывода кириллицы (только для Windows)
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Массив для отслеживания занятости мест. true = свободно, false = занято.
    vector<bool> is_free(55, false); // Места с 1 по 54, индекс 0 не используется

    int N; // Количество свободных мест
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int seat_num;
        cin >> seat_num;
        is_free[seat_num] = true; // Отмечаем место как свободное
    }

    int max_consecutive_free_compartments = 0;
    int current_consecutive_free_compartments = 0;

    // Проверяем каждое из 9 купе
    for (int compartment_num = 1; compartment_num <= 9; ++compartment_num) {
        // Определяем номера мест для текущего купе
        int main_start = (compartment_num - 1) * 4 + 1;
        int main_end = main_start + 3;
        int side_start = 54 - (compartment_num - 1) * 2 - 1;
        int side_end = 54 - (compartment_num - 1) * 2;

        // Проверяем, все ли места в купе свободны
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
    // Проверяем последнюю последовательность после цикла
    max_consecutive_free_compartments = max(max_consecutive_free_compartments, current_consecutive_free_compartments);


    cout << max_consecutive_free_compartments << endl;

    return 0;
}
