#include <iostream>

int main() {
    long long n = 0, m = 0;

    std::cout << "Введите размеры сетки N и M: ";

    if (std::cin >> n >> m) {

        const long long ways_n = n * (n + 1) / 2;
        std::cout << "Для стороны N=" << n << " можно выбрать отрезков: " << ways_n << std::endl;

        const long long ways_m = m * (m + 1) / 2;
        std::cout << "Для стороны M=" << m << " можно выбрать отрезков: " << ways_m << std::endl;

        const long long res = ways_n * ways_m;

        std::cout << "--- Итог ---" << std::endl;
        std::cout << "Перемножаем: " << ways_n << " * " << ways_m << std::endl;
        std::cout << "Ответ: " << res << std::endl;
    } else {
        std::cout << "Ошибка ввода данных!" << std::endl;
    }

    return 0;
}
