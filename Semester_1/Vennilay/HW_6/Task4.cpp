#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cout << "--- Поиск свободных купе ---" << std::endl;
    std::cout << "Введите количество свободных мест N: ";

    if (!(std::cin >> n)) {
        std::cout << "Ошибка: введено не число!" << std::endl;
        return 1;
    }

    std::vector<bool> is_free(55, false);

    std::cout << "Введите номера " << n << " свободных мест:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int seat;
        std::cin >> seat;
        if (seat >= 1 && seat <= 54) {
            is_free[seat] = true;
        }
    }

    int maks_podryad = 0;
    int tekusch_podryad = 0;

    std::cout << "\n--- Начинаем проверку по купе ---" << std::endl;

    for (int coupe = 1; coupe <= 9; ++coupe) {
        const int start_main = (coupe - 1) * 4 + 1;
        const int side2 = 54 - (coupe - 1) * 2;
        const int side1 = side2 - 1;

        std::vector<int> seats_in_coupe;
        for (int k = 0; k < 4; ++k) seats_in_coupe.push_back(start_main + k);
        seats_in_coupe.push_back(side1);
        seats_in_coupe.push_back(side2);

        bool full_coupe_free = true;
        int occupied_seat = -1;

        for (const int seat : seats_in_coupe) {
            if (!is_free[seat]) {
                full_coupe_free = false;
                occupied_seat = seat;
                break;
            }
        }

        if (full_coupe_free) {
            tekusch_podryad++;
            if (tekusch_podryad > maks_podryad) {
                maks_podryad = tekusch_podryad;
            }
            std::cout << "[+] Купе " << coupe << " свободно! (Серия: " << tekusch_podryad << ")" << std::endl;
        } else {
            tekusch_podryad = 0;
            std::cout << "[-] Купе " << coupe << " занято (место " << occupied_seat << ")." << std::endl;
        }
    }

    std::cout << "\n--- Результат ---" << std::endl;
    std::cout << "Макс. купе подряд: " << maks_podryad << std::endl;

    return 0;
}