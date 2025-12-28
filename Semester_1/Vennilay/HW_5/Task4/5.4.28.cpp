#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cout << "Введите целое число n: ";
    std::cin >> n;

    n = std::abs(n);
    int sum = 0;

    while (n > 0) {
        sum += static_cast<int>(n % 10);
        n /= 10;
    }

    std::cout << "Сумма цифр: " << sum << std::endl;
    return 0;
}
