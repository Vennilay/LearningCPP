#include <iostream>

int main() {
    long long m;

    std::cout << "Введите количество лопастей M: ";
    if (!(std::cin >> m)) {
        std::cout << "Ошибка ввода!" << std::endl;
        return 1;
    }

    for (long long count4 = 0; count4 * 4 <= m; ++count4) {
        const long long ostat = m - (count4 * 4);

        std::cout << "Пробуем взять " << count4 << " шт. по 4 лопасти. " << "Осталось лопастей: " << ostat << ". ";

        if (ostat % 3 == 0) {
            const long long count3 = ostat / 3;
            std::cout << "Делится на 3! (будет " << count3 << " шт.)" << std::endl;

            std::cout << "--- Решение найдено ---" << std::endl;
            std::cout << count3 << " " << count4 << std::endl;

            return 0;
        }
        std::cout << "Не делится на 3, ищем дальше..." << std::endl;
    }

    std::cout << "--- Решение не найдено ---" << std::endl;
    std::cout << "0 0" << std::endl;

    return 0;
}
