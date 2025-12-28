#include <iostream>

int main() {
    long long a = 0, b = 0, c = 0;

    std::cout << "Введите стоимость основания (A), лопасти (B) и бюджет (C): ";

    if (!(std::cin >> a >> b >> c)) {
        std::cout << "Ошибка: Некорректный ввод! Ожидались целые числа." << std::endl;
        return 1;
    }

    if (a < 0 || b <= 0 || c < 0) {
        std::cout << "Ошибка: Цены не могут быть отрицательными, а B должно быть > 0." << std::endl;
        return 1;
    }

    if (a > c) {
        std::cout << "Максимальное число лопастей: 0 (Не хватает денег даже на основание)" << std::endl;
        return 0;
    }

    const long long result = (c - a) / b;
    std::cout << "Максимальное число лопастей: " << result << std::endl;

    return 0;
}
