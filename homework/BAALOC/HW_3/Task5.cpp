#include <iostream>
#include <vector>

void markNonPrimes(std::vector<bool>& primeFlags, int n) {
    for (int number = 2; number <= std::sqrt(n); ++number) {
        if (primeFlags[number]) {
            for (int multiple = number * number; multiple <= n; multiple += number) {
                primeFlags[multiple] = false;
            }
        }
    }
}

void displayRes(std::vector<bool>& primeFlags, int n) {
    std::cout << "Простые числа:" << std::endl;
    for (int number = 2; number <= n; number++) {
        if (primeFlags[number]) {
            std::cout << number << std::endl;
        }
    }
}

int main() {
    int n = 0;
    std::cout << "Введите натуральное число: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Простых чисел нет." << std::endl;
        return 1;
    }

    std::vector<bool> primeFlags(n + 1, true);
    primeFlags[0] = primeFlags[1] = false;

    markNonPrimes(primeFlags, n);
    displayRes(primeFlags, n);
    return 0;
}
