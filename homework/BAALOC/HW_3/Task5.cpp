#include <iostream>
#include <vector>

void markNonPrimes(std::vector<bool>& primeFlags, int n) {
    for (int number = 2; number * number <= n; ++number) {
        if (primeFlags[number]) {
            for (int multiple = number * number; multiple <= n; multiple += number) {
                primeFlags[multiple] = false;
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Введите натуральное число: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Простых чисел нет." << std::endl;
        return 0;
    }

    std::vector<bool> primeFlags(n + 1, true);
    primeFlags[0] = primeFlags[1] = false;

    markNonPrimes(primeFlags, n);

    std::cout << "Простые числа от 2 до " << n << ":" << std::endl;
    for (int number = 2; number <= n; ++number) {
        if (primeFlags[number]) {
            std::cout << number << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
