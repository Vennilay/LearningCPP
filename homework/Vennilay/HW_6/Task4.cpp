#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cout << "Введите количество свободных мест N: ";
    if (!(std::cin >> n)) {
        std::cout << "Ошибка ввода!" << std::endl;
        return 1;
    }

    std::vector<bool> is_free(55, false);

    std::cout << "Введите номера " << n << " свободных мест:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int seat;
        std::cin >> seat;
        is_free[seat] = true;
    }

    int maks_podryad = 0;
    int tekusch_podryad = 0;

    std::cout << "\n--- Проверяем купе по очереди ---" << std::endl;

    for (int coupe = 1; coupe <= 9; ++coupe) {

        const int start_main = (coupe - 1) * 4 + 1;
        const int side2 = 54 - (coupe - 1) * 2;
        const int side1 = side2 - 1;

        bool full_coupe_free = true;

        for (int k = 0; k < 4; ++k) {
            if (!is_free[start_main + k]) {
                full_coupe_free = false;
                break;
            }
        }

        if (full_coupe_free) {
            if (!is_free[side1] || !is_free[side2]) {
                full_coupe_free = false;
            }
        }

        if (full_coupe_free) {
            tekusch_podryad++;

            if (tekusch_podryad > maks_podryad) {
                maks_podryad = tekusch_podryad;
            }
            std::cout << "Купе №" << coupe << " полностью свободно! (Места: " << start_main << "-" << start_main+3 << " и " << side1 << "," << side2 << ")" << std::endl;
        } else {
            tekusch_podryad = 0;
            std::cout << "Купе №" << coupe << " занято." << std::endl;
        }
    }

    std::cout << "\n--- Результат ---" << std::endl;
    std::cout << "Максимально купе подряд: " << maks_podryad << std::endl;

    return 0;
}
